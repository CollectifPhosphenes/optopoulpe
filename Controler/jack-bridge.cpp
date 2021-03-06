#include "jack-bridge.hpp"

#include <exception>

#include <jack/jack.h>
#include <jack/midiport.h>

#include <string.h>

int jack_callback(jack_nframes_t nframes, void* args)
{
  JackBridge* bridge = (JackBridge*)args;

  {
    jack_nframes_t events_count;
    jack_midi_event_t event;

    void* in_buffer = jack_port_get_buffer(bridge->midi_in, nframes);
    events_count = jack_midi_get_event_count(in_buffer);

    for (jack_nframes_t i = 0 ; i < events_count ; ++i)
    {
      if (0 != jack_midi_event_get(&event, in_buffer, i))
        continue;
      std::vector<uint8_t> msg;
      msg.reserve(event.size);
      for (size_t i=0 ; i<event.size ; ++i)
        msg.emplace_back(event.buffer[i]);
      bridge->from_jack.push(std::move(msg));
    }
  }

  {
    void* out_buffer = jack_port_get_buffer(bridge->midi_out, nframes);
    jack_midi_clear_buffer(out_buffer);

    std::optional<std::vector<uint8_t>> optmsg;
    while (std::nullopt != (optmsg = bridge->to_jack.pop()))
    {
      auto msg = optmsg.value();
      void* raw = jack_midi_event_reserve(out_buffer, 0, msg.size());
      memcpy(raw, msg.data(), msg.size());
    }
  }

  return 0;
}

JackBridge::JackBridge(const char* name)
{
	jack_status_t jack_status;
	client = jack_client_open(name, JackNullOption, &jack_status);
	if (NULL == client)
		throw std::runtime_error("Can't open jack client");
	
	midi_in = jack_port_register(client, "midi_in", JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0);
	if (NULL == midi_in)
		throw std::runtime_error("Can't open midi in");

	midi_out = jack_port_register(client, "midi_out", JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0);
	if (NULL == midi_out)
		throw std::runtime_error("Can't open midi out");
	
	if (0 != jack_set_process_callback(client, jack_callback, this))
		throw std::runtime_error("Can't set process callback");
}
JackBridge::~JackBridge()
{
  if (client) jack_client_close(client);
}

void JackBridge::activate()
{
	if (0 != jack_activate(client))
		throw std::runtime_error("Can't activvate client");
}

std::vector<std::vector<uint8_t>> JackBridge::incomming_midi()
{
  std::vector<std::vector<uint8_t>> result;
	std::optional<std::vector<uint8_t>> optmsg;
  while (std::nullopt != (optmsg = from_jack.pop()))
    result.push_back(optmsg.value());
  return result;
}
void JackBridge::send_midi(std::vector<uint8_t>&& msg)
{
  to_jack.push(std::forward<std::vector<uint8_t>>(msg));
}