#include "esp_event.h" /*Header file for delay*/

#define GPIO_OUT_REG    *((unsigned int*)0x3FF44004U) /*output value register*/
#define GPIO_OUTPUT_REG *((unsigned int*)0x3FF44020U) /*output enable register.*/
#define GPIO_LED 1U << 2 /*GPIO 2- connected to onboard LED*/
#define DELAY 300

void app_main(){

	GPIO_OUT_REG |= GPIO_LED;

	while(1){
	GPIO_OUTPUT_REG |= GPIO_LED;  /*Turn LED ON*/

	vTaskDelay(DELAY/portTICK_PERIOD_MS);

	GPIO_OUTPUT_REG &= ~GPIO_LED; /*Turn LED OFF*/

    vTaskDelay(DELAY/portTICK_PERIOD_MS);

	}
}
