#ifndef PWM_HELPERS_H    /* This is an "include guard" */
#define PWM_HELPERS_H

#include "pwm_helpers.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void pwm_cfg(uint pin);
void pwm_freq(uint16_t freq);
int pwm_duty_u16(uint16_t duty_u16);

#endif /* PWM_HELPERS_H */