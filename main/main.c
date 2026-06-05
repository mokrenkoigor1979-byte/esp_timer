#include <stdbool.h>

#include "driver/gpio.h"
#include "esp_timer.h"

#define LED GPIO_NUM_21

static bool state = false;

void app_main(void)
{
    gpio_reset_pin(LED);
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);
    gpio_set_level(LED, state);
}
