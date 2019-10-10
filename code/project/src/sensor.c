/*!
 *\brief Sensor
 *This Source file is used to implement the functions
 *to be used to drive the Sensors used in this project
 * 
 *\author $Author: bv $
 *\version $Revision: 1.0 $
 *\date $Date: 2019/05/15 $
 *$Id: doxygen_sensorSource.html, v 1.0 2019/05/15 bv Exp $
 */ 


#include <platform.h>
#include <gpio.h>
#include "sensor.h"

/*!
 *\brief This method sets the pins to be used as
 *input by the Sensors.
 * P1_31 is the Pre-Gate Sensor for Entrance 1
 * P1_30 is the Post-Gate Sensor for Entrance 1
 * P0_26 is the Pre-Gate Sensor for Entrance 2
 * P0_25 is the Post-Gate Sensor for Entrance 2
 * P0_24 is the Pre-Gate Sensor for Exit 
 * P0_5 is the Post-Gate Sensor for Exit
 
 
*/
void sensor_init(void) {
	gpio_set_mode(P0_5,Input);
	gpio_set_mode(P0_24,Input);
	gpio_set_mode(P0_25,Input);
	gpio_set_mode(P0_26,Input);
	gpio_set_mode(P1_30,Input);
	gpio_set_mode(P1_31,Input);

}

/*!
 * This method gets the value of
 * the pin passed as a parameter
*/

int sensor_get(Pin pin) {
	return !gpio_get(pin);
}


// *******************************ARM University Program Copyright © ARM Ltd 2014*************************************   
