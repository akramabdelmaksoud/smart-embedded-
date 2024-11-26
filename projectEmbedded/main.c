#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "tm4c123gh6pm.h"
#include "adc.h"
#include "dio.h"
#include "temperature.h"
#include <stdint.h>



void control_leds_buzzer(int door_status, int temperature) {
    if (!door_status == 0) {  // Door closed
        SET_BIT(GPIO_PORTF_DATA_R, RED_LED_PIN);
        CLR_BIT(GPIO_PORTF_DATA_R, GREEN_LED_PIN);
    } else {  // Door open
        SET_BIT(GPIO_PORTF_DATA_R, GREEN_LED_PIN);
        CLR_BIT(GPIO_PORTF_DATA_R, RED_LED_PIN);
    }

    if (temperature > TEMP_THRESHOLD_HIGH) {
        SET_BIT(GPIO_PORTF_DATA_R, BUZZER_PIN);  // Turn on buzzer
    } else {
        CLR_BIT(GPIO_PORTF_DATA_R, BUZZER_PIN);  // Turn off buzzer
    }
}

int main(void) {
    int door_status;
    int temperature;

    dio_init();   // Initialize GPIO
    adc_init();   // Initialize ADC

    while (1) {
        // Read door status
        door_status = !GET_BIT(GPIO_PORTF_DATA_R, MAGNETIC_SWITCH_PIN);

        // Read temperature
        temperature = read_temperature();
        // Control LEDs and buzzer
        control_leds_buzzer(door_status, temperature);
    }
}

