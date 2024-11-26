#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "dio.h"


void dio_init(){
 SET_BIT(SYSCTL_RCGCGPIO_R,5);
 while(GET_BIT(SYSCTL_PRGPIO_R,5)==0){ }
  CLR_BIT(GPIO_PORTF_DIR_R, MAGNETIC_SWITCH_PIN);  // Set PF4 as input
  SET_BIT(GPIO_PORTF_DEN_R, MAGNETIC_SWITCH_PIN);    // Enable digital function for PF4
  SET_BIT(GPIO_PORTF_PUR_R, MAGNETIC_SWITCH_PIN);    // Enable pull-up resistor for PF4
  SET_BIT(GPIO_PORTF_DIR_R, RED_LED_PIN);
  SET_BIT(GPIO_PORTF_DEN_R, RED_LED_PIN);
  SET_BIT(GPIO_PORTF_DIR_R, GREEN_LED_PIN);
  SET_BIT(GPIO_PORTF_DEN_R, GREEN_LED_PIN);
  SET_BIT(GPIO_PORTF_DIR_R, BUZZER_PIN);
  SET_BIT(GPIO_PORTF_DEN_R, BUZZER_PIN);
}