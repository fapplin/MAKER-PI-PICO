#ifndef PWM_HELPERS_H    /* This is an "include guard" */
#define PWM_HELPERS_H

#include "pwm_helpers.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void pwm_deinit();
void set_pwm_pin(uint pin, uint freq, uint duty_c);


#endif /* PWM_HELPERS_H */