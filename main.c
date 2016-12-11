


#include "tm4c1294.h"
#include <stdint.h>


int main(void) {
	// Enable clk for port F, J, and N
	SYSCTL_RCGCGPIO_R = (SYSCTL_RCGCGPIO_R5 |SYSCTL_RCGCGPIO_R8 |SYSCTL_RCGCGPIO_R12);

	// intialization of port N <on board LEDS>
	GPIO_PORTN_DIR_R |= 0x03; //make PN0 and PN1 as output
	GPIO_PORTN_DEN_R |= 0x03; //digital enable for PN0 and PN1
	
	// intialization of port J <on board sw>
	GPIO_PORTJ_AHB_DIR_R |= 0x00; // make PJ0 and PJ1 as input
	GPIO_PORTJ_AHB_DEN_R |= 0x03; // digital enable for PJ0 and PJ1
	GPIO_PORTJ_AHB_PUR_R |= 0x03; // pull up PJ0 and PJ1

	while(1){

		GPIO_PORTN_DATA_R = ~(GPIO_PORTJ_AHB_DATA_R); //write sw input to leds

	}

}
