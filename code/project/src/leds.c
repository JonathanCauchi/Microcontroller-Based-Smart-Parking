/*!
 * \file      leds.c
 * \brief     Controls an RGB LED.
 */
 
#include <platform.h>
#include <gpio.h>
#include "leds.h"

/*! \brief In this method, the pins used as output
 * for the three LEDS in use are set. 
 * P5_2 -> Red Entrance 1
 * P0_4 -> Green Entrance 1
 * P5_0 -> Red Entrance 2
 * P5_1 -> Green Entrance 2
 * P5_4 -> Red Exit 1
 * P5_3 -> Green Exit 1
 */
void leds_init(void) {
	gpio_set_mode(P5_0, Output);
  gpio_set_mode(P5_1, Output);
	gpio_set_mode(P0_4,Output);
	gpio_set_mode(P5_2,Output);
	gpio_set_mode(P5_3,Output);
	gpio_set_mode(P5_4,Output);
}


// *******************************ARM University Program Copyright © ARM Ltd 2014*************************************   
