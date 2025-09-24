#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include "unity_config.h"
#include <unity.h>
#include <string.h>
#include "routine.h"

void setUp(void) {
}

void tearDown(void) {}

void test_upper_case()
{
    char upper = 'U';

    char lower = get_Char(upper);

    TEST_ASSERT_EQUAL_CHAR('u', lower);
}

void test_lower_case()
{
    char upper = 'a';

    char lower = get_Char(upper);

    TEST_ASSERT_EQUAL_CHAR('A', lower);
}

void test_string() {
    char* str = "Hello World";
    char buf[20] = {0}; 
    for (int i = 0; i < (strlen(str)); ++i) {
        buf[i] = get_Char(str[i]);
    }
    char* expected = "hELLO wORLD";

    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, buf, strlen(str));
}

void test_blink(){
    int count = 0; 
    bool on = 0;
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    for (int i = 0; i < 100; ++i){
        int current_count = count;
        bool old_on = on;
        blink_led(&count, &on);
        int current_gpio =  cyw43_arch_gpio_get(CYW43_WL_GPIO_LED_PIN);
        TEST_ASSERT_EQUAL_MESSAGE(current_gpio, old_on, "GPIO is set by on variable.");
        TEST_ASSERT_EQUAL_MESSAGE(count, current_count + 1, "Count should always increment.");
        if ((i+1) % 11) {
            TEST_ASSERT_NOT_EQUAL_MESSAGE(old_on, on, "ONLY toggle when count is not a multiple of 11.");
        } else {
            TEST_ASSERT_EQUAL_MESSAGE(old_on, on, "Should not toggle otherwise.");
        }
    }
}

int main (void)
{
    stdio_init_all();
    sleep_ms(5000); // Give time for TTY to attach.
    hard_assert(cyw43_arch_init() == PICO_OK);
    while(1) {
        printf("Start tests\n");
        UNITY_BEGIN();
        RUN_TEST(test_upper_case);
        RUN_TEST(test_lower_case);
        RUN_TEST(test_string);
        RUN_TEST(test_blink);
        sleep_ms(5000);
        UNITY_END();
    }
}