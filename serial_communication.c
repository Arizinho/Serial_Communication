#include <stdio.h>
#include "pico/stdlib.h"

#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12
#define BUZZER 21

#define SLICE_GPIO21 2
#define CHANNEL_GPIO21 PWM_CHAN_B
#define TOP 8877
#define DIV 32

int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}

