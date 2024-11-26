#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
#define RELAY_PIN 0  // Assuming PB0 is used to control the relay


void relay_init(void);
void relay_on(void);
void relay_off(void);

