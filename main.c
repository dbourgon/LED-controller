#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "hardware/pwm.h"

int config_gpio()
{
    ////
    // Indicator LEDs
    
    // LED0
    gpio_init(0);
    gpio_pull_down(0); // Pull Down
    gpio_set_dir(0, 1); //Set as output
    
    // LED1
    gpio_init(1);
    gpio_pull_down(1);
    gpio_set_dir(1, 1); // Set as output
    
    // LED2
    gpio_init(2);
    gpio_pull_down(2);
    gpio_set_dir(2, 1); // Set as output
    
    ////
    // Input buttons
    
    // BTN0
    gpio_init(6);
    gpio_pull_down(6);
    gpio_set_input_hysteresis_enabled(6, 1); // Set as input
    
    // BTN1
    gpio_init(7);
    gpio_pull_down(7);
    gpio_set_input_hysteresis_enabled(7, 1); // Set as input
    
    // BTN2
    gpio_init(8);
    gpio_pull_down(8);
    gpio_set_input_hysteresis_enabled(8, 1); // Set as input
    
    ////
    // Pulse Width Modulation Output
    
    // PWM5
    gpio_init(5);
    gpio_set_function(5, GPIO_FUNC_PWM);
    uint slice_5 = pwm_gpio_to_slice_num(5);
    pwm_set_wrap(slice_5, 31);
    pwm_set_chan_level(slice_5, PWM_CHAN_A, 0);
    pwm_set_enabled(slice_5, 1);
    
    // PWM6
    gpio_init(6);
    gpio_set_function(6, GPIO_FUNC_PWM);
    uint slice_6 = pwm_gpio_to_slice_num(6);
    pwm_set_wrap(slice_6, 31);
    pwm_set_chan_level(slice_6, PWM_CHAN_A, 0);
    pwm_set_enabled(slice_6, 1);
    
    // PWM7
    gpio_init(7);
    gpio_set_function(7, GPIO_FUNC_PWM);
    uint slice_7 = pwm_gpio_to_slice_num(7);
    pwm_set_wrap(slice_7, 31);
    pwm_set_chan_level(slice_7, PWM_CHAN_A, 0);
    pwm_set_enabled(slice_7, 1);
    
    return 0;
}

int main()
{
    config(gpio);
    
    return 0;
}
