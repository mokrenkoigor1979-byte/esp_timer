#include <stdbool.h>

#include "driver/gpio.h"
#include "esp_timer.h"

#define LED GPIO_NUM_21

static bool state = false;

static void timer_callback(void *args)
{
    state = !state;
    gpio_set_level(LED, state);
}

void app_main(void)
{
    gpio_reset_pin(LED);
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);
    gpio_set_level(LED, state);

    esp_timer_handle_t timer;
    esp_timer_create_args_t timer_args = {
        .callback = timer_callback,
        .name = "oneshot"};
    esp_timer_create(&timer_args, &timer);
    esp_timer_start_periodic(timer, 1000000);
}
