Phase A) How to set up the test scenario.
    1) Extensively check the main task's funcitonality (after creating the blink task) by checking every alpha-char input value for upper and lower case.

Phase B) How to exercise the system
    - Build and compile to the Pico device
    Use LEDs or GPIOs outputs for certain behaviors
    1) Utilize Visual Studio Code's serial monitor to verify alpha-char input values 

Phase C) Expected behavior.
    1) We expect that the uppercase inputs will output a lowercase letter, and vice versa
    Output:
    ----- Sent utf8 encoded message: "Hello World" ----
    hELLO wORLD