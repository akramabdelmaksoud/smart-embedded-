#include "relay.h"

void relay_init(void) {
    // Enable clock for Port B
    SET_BIT(SYSCTL_RCGCGPIO_R, 1);  // Enable clock for GPIO Port B
    while (!GET_BIT(SYSCTL_PRGPIO_R, 1));  // Wait for Port B to be ready

    // Configure PB0 as output
    SET_BIT(GPIO_PORTB_DIR_R, RELAY_PIN);   // Set PB0 as output
    SET_BIT(GPIO_PORTB_DEN_R, RELAY_PIN);   // Enable digital function for PB0
}
void relay_on(void) {
    SET_BIT(GPIO_PORTB_DATA_R, RELAY_PIN);  // Turn relay ON (lamp ON)
}

void relay_off(void) {
    CLEAR_BIT(GPIO_PORTB_DATA_R, RELAY_PIN);  // Turn relay OFF (lamp OFF)
}