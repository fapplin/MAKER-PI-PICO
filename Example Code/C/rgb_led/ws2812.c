/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
} //end put_pixel

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)(r) << 8) |
         ((uint32_t)(g) << 16) |
         (uint32_t)(b);
} //end urgb_u32


const int PIN_TX = 28;

int main() 
{
    stdio_init_all();
   
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, PIN_TX, 800000, true);

    put_pixel(urgb_u32(0xff, 0, 0));  // Red
    sleep_ms(500);
    put_pixel(urgb_u32(0, 0xff, 0));  // Green
    sleep_ms(500);
    put_pixel(urgb_u32(0, 0, 0xff));  // Blue
    sleep_ms(500);
    put_pixel(urgb_u32(0xff, 0xff, 0));  // Purple
    sleep_ms(500);
    put_pixel(urgb_u32(0, 0xff, 0xff));  // Cyan
    sleep_ms(500);
    put_pixel(urgb_u32(0xff, 0xff, 0xff));  // White
    sleep_ms(500);
    put_pixel(urgb_u32(0, 0, 0));  // Black or off
    sleep_ms(500);

    sleep_ms(1000);
    // Clear all pixels
    for (int i = 0; i <= 60; i++) {
      put_pixel(urgb_u32(0, 0, 0));  // Black or off
    } //end for

    sleep_ms(1000);
} //end main