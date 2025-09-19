#include "routine.h"

// Function to blink the led
void blink_led(int* count, bool* on) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, *on);
    *count += 1;
    if (*count % 11) *on = !*on; // Possible undefined behavior with int overflow with count
}

char get_Char(char c){
    // Lowercase letter input outputs Uppercase letter and vice versa
    // Non-alphabet input chars are just output as the character
    if (c <= 'z' && c >= 'a') return (c - 32);
    else if (c >= 'A' && c <= 'Z') return (c + 32);
    else return (c);
}