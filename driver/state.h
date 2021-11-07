#pragma once

#include <stdint.h>

#define MAX_RIBBONS_COUNT 8
#define PRESETS_COUNT 8

struct state_t {

  struct triggers_t {
    uint8_t save;
    uint8_t load;
  } triggers;

  struct setup_t {
    uint8_t ribbons_count;
    uint8_t ribbons_length[MAX_RIBBONS_COUNT];
  } setup;

  struct {
    float   bpm;
    uint8_t brightness;
    uint8_t strobe_speed;
  } master;

  struct {
    uint8_t palette;

    uint8_t colormod_enable;
    uint8_t colormod_osc;
    uint8_t colormod_width;
    
    uint8_t maskmod_enable;
    uint8_t maskmod_osc;
    uint8_t maskmod_width;
    uint8_t maskmod_move;

    uint8_t slicer_osc;
    uint8_t slicer_nslices;
    uint8_t slicer_useflip;
    uint8_t slicer_useuneven;

    uint8_t feedback_enable;
    uint8_t feedback_qty;

    uint8_t strobe_enable;

    uint8_t speed_scale;

    uint8_t brightness;

  } presets[PRESETS_COUNT];
};