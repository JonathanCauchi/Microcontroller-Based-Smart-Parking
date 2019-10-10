/*!
 *
 *\file sensor.h
 *\brief Generic Sensor Functions
 */ 

#ifndef SENSOR_H
#define SENSOR_H

/*! 
 * \brief This method initialises the pins used as 
 *input by the Sensors
 */
void sensor_init(void);
/*! 
 * \brief This method gets the Pin value
 */
int sensor_get(Pin pin);

#endif // SENSOR_H

// *******************************ARM University Program Copyright © ARM Ltd 2014*************************************   
