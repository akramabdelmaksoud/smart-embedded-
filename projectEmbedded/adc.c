#include "adc.h"
void adc_init(void) {
    // Enable clock for ADC0 and Port E
    SET_BIT(SYSCTL_RCGCADC_R, 0);  // Enable ADC0 clock
    SET_BIT(SYSCTL_RCGCGPIO_R, 4);  // Enable clock for GPIO Port E
    while (!GET_BIT(SYSCTL_PRGPIO_R, 4));  // Wait for Port E to be ready

    // Configure PE3 as AIN3
    SET_BIT(GPIO_PORTE_AFSEL_R, TEMP_SENSOR_CHANNEL);  // Enable alternate function for PE3
    CLR_BIT(GPIO_PORTE_DEN_R, TEMP_SENSOR_CHANNEL);  // Disable digital function for PE3
    SET_BIT(GPIO_PORTE_AMSEL_R, TEMP_SENSOR_CHANNEL);  // Enable analog function for PE3

    // Configure ADC0 for single sample mode
    CLR_BIT(ADC0_ACTSS_R, 3);  // Disable sample sequencer 3
    ADC0_EMUX_R &= ~0xF000;      // Set trigger source to processor (default)
    ADC0_SSMUX3_R = TEMP_SENSOR_CHANNEL;  // Use AIN3 (PE3)
    ADC0_SSCTL3_R = 0x6;         // Set IE0 and END0 bits
    SET_BIT(ADC0_ACTSS_R, 3);    // Enable sample sequencer 3
}