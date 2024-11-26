#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "temperature.h"


int read_temperature(void) {
    int adc_value;

    SET_BIT(ADC0_PSSI_R, 3);  // Start ADC conversion
    while (!GET_BIT(ADC0_RIS_R, 3));  // Wait for conversion to complete
    adc_value = ADC0_SSFIFO3_R & 0xFFF;  // Read ADC result
    SET_BIT(ADC0_ISC_R, 3);  // Clear interrupt flag

    // Convert ADC value to temperature
    return (adc_value * 330) / 4096;  // Convert ADC to Celsius (assuming LM35)
}
