#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/cyw43_arch.h"

void blink_led(int* count, bool* on);

char get_Char(char c);