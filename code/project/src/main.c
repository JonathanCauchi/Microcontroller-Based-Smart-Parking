/*!
 *\file main.c
 *\brief Main file used for Parking System Execution. 
*/
#include <platform.h>
#include <gpio.h>
#include "delay.h"
#include "lcd.h"
#include "sensor.h"
#include "leds.h"
/*!
 *\brief Enumeration to code the States
 * used by the system while it is running. 
*/
enum State{
	Idle = 0,  //System is waiting for an event to happen
	 Gate1 = 1, //System is waiting for the Post-Gate Sensor of Entrance 1
	 Gate2 = 2, //System is waiting for the Post-Gate Sensor of Entrance 2
	 Exit = 3, //System is waiting for the Post-Gate Sensor of Exit
	 Full= 4, //System is Full. There are no parking spaces available. Cars can only exit. 
	 Waiting=5	//System is in a temporary state until the necessary updates are done
	}; 

/*!
 *\brief Main Method. In this function, all the
 * necessary computation is done calling the functions 
 * found in header files. During this project, the Car Park
 * is assumed to hold only 5 Cars. 
*/
int main(void) {
	//Setting Car Park counter to 0. 
	int counter=0;
	//Setting the System to State Idle. 
  int State= Idle;

	//Initiating the Sensors to be ready for Input
		sensor_init();
	//Initiating LEDs
		leds_init();
	//Initiating the LCD Screen
		lcd_init();
	//Clearing LCD Screen
		lcd_clear();
	//Displaying Welcome Message
		lcd_print("PARKING SYSTEM");
		
	//Switching the Green component of the first Entrance LED off.
	gpio_set(P0_4,0);
	//Switching the Red component of the first Entrance LED on.
	gpio_set(P5_2,1);
		//Switching the Green component of the second Entrance LED off. 
	gpio_set(P5_1,0);
	//Switching the Red component of the second Entrance LED on.
	gpio_set(P5_0,1);
	//Switching the Green component of the exit LED off.
	gpio_set(P5_3,0);
	//Switching the Red component of the exit LED on. 
	gpio_set(P5_4,1);
	
	//While loop to achieve Continuous Program Execution. 
	while(1){	
		//If the Pre-Gate sensor of Entrance 1 is High
	if(sensor_get(P1_31)==0 && State==Idle){
		//Setting the System to state Gate 1.
		State=Gate1;
		//Switching the Red Component of the first Entrance LED off.  
			gpio_set(P5_2,0);
		//Setting the Green Component of the first Entrance LED on.
		gpio_set(P0_4,1);
		//Delaying to give time for the car to move. 
			delay_ms(2000);
		//If the Post-Entrance sensor of Entrance 1 is High
		if(sensor_get(P1_30)==0 && State==Gate1){
			//Set the System state to waiting.
			State=Waiting;
			//Switching the Red Component of the first Entrance LED on.
			gpio_set(P5_2,1);
			//Switching the Green Component of the first Entrance LED off. 
			gpio_set(P0_4,0);
			//Incrementing the counter by 1.
			counter+=1;	
			//Clearing the LCD screen
		  lcd_clear();
			//Displaying the number of parking spaces available.
			lcd_print("PARKING:");
			lcd_print_digit(5-counter);
			//If there are less than 5 cars parked, system is set to state Idle.
			if(counter<5){
				State=Idle;
			}
			//Else, system is set to state Full.
			else{
				lcd_clear();
				//Displaying a message to the user that there are no parking spaces left. 
				lcd_print("PARKING FULL");
				State=Full;
			}
		}	
		else{ //To be executed if the car doesn't touch the Post-Entrance sensor within the time allocated. 
			//Setting the Red Component of the first Entrance LED On.
			gpio_set(P5_2,1);
			//Setting the Green Component of the first Entrance LED off. 
			gpio_set(P0_4,0);
			//Setting the system to state Idle. 
			State=Idle;}
	}
	
	//If the Pre-Gate sensor of Entrance 2 is High
	if(sensor_get(P0_26)==0 && State==Idle){
		//Setting the State of the System to Gate2
		State=Gate2;
		//Switching the Red Component of the Second Entrance LED off. 
		gpio_set(P5_0,0);
		//Switching the Green Component of the Second Entrance LED on. 
	  gpio_set(P5_1,1);
		//Delay to give time for the car to move.
		delay_ms(2000);
		//If the Post-Gate sensor of Entrance 2 is High
		if(sensor_get(P0_25)==0 && State==Gate2){
			//Setting the system to State Waiting. 
			State=Waiting;
			//Switching the Green Component of the Second Entrance LED off.
			gpio_set(P5_1,0);
			//Switching the Red Component of the Second Entrance LED on. 
			gpio_set(P5_0,1);
			//Incrementing the no of parked cars by 1.
			counter+=1;	
		
		//Clearing the LCD;
		lcd_clear();
		//Displaying the number of Parking Spaces available.  
		lcd_print("PARKING:");
		lcd_print_digit(5-counter);
		//If there are Less than 5 cars parked, System should return to state Idle. 	
		if(counter<5){
		  State=Idle;
		}
		//Else the system State is set to Full.
		else{
			lcd_clear();
			//Displaying a message to the user that there are no parking spaces left. 
			lcd_print("PARKING FULL");
			State=Full;
		}
	 }
		else{ //To be executed if within the time frame given, the car doesn't touch the second sensor. 
			//Setting the Green Component of the first LED off.
			gpio_set(P5_1,0);
			//Switching the Red Component of the first Entrance LED on. 
			gpio_set(P5_0,1);
		  //Setting the system back to state Idle.
			State=Idle;}
 }
	//If the Pre-Gate of Exit is High  and there are cars parked. 
   else if (sensor_get(P0_24)==0 && (State==Idle || State==Full) && counter>=0){
		 //Setting the system state to Exit.
		 State=Exit;
		 //Switching the Red Component of the Exit LED off.
		 gpio_set(P5_4,0);
		 //Switching the Green Component of the Exit LED on. 
			gpio_set(P5_3,1);
		 //Delay to give time for the car to move.
		delay_ms(2000);
		 //If the Post-Gate Sensor of the Exit is High 
		if(sensor_get(P0_5)==0 && State==Exit){
			//System  state is set to Waiting
			State=Waiting;
			//Switching the Green Component of the Exit LED off
			gpio_set(P5_3,0);
			//Switching the Red Component of the Exit LED on. 
			gpio_set(P5_4,1);
			//Decrementing the counter to increase a parking space.
			counter=counter-1;	
		}
		//Clearing the LCD screen.
		lcd_clear();
		//Displaying the number of parking spaces available.
		lcd_print("PARKING:");
		lcd_print_digit(5-counter);
		//Setting the System state to Idle. 
		State=Idle;
	 }
 }
}


// *******************************ARM University Program Copyright © ARM Ltd 2014*************************************
