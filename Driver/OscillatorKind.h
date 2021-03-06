#pragma once

enum class OscillatorKind {
    Sin,
    Triangle,
    SawTooth,
    Noise,
};

OscillatorKind map_to_oscillator_kind(uint8_t x)
{
  return static_cast<OscillatorKind>((x * (int)4) / 255);
}

uint8_t eval_oscillator(OscillatorKind oscillator, uint8_t x)
{
  uint8_t tmp;
  switch (oscillator)
  {    
    case OscillatorKind::Sin:      return sin8(x);
    case OscillatorKind::SawTooth: return x;
    case OscillatorKind::Triangle: return triwave8(x);
    case OscillatorKind::Noise:   
      tmp = random8();
      return random8() ^ ((tmp << 4) | (tmp >> 4));
    default:                       return 0;
  }
}
