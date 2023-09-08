/***
 *
 * Jon Durrant
 * 15-Aug-2022
 */


#include "pico/stdlib.h"
#include "distance_sensor.h"
#include "stdio.h"

#define NUM_SENSORS 4

#define NORTH  	6		//GP06 Trigger GP07 Echo
#define EAST  		8		//GP08 Trigger GP09 Echo
#define SOUTH  	2		//GP02 Trigger GP03 Echo
#define WEST  		4		//GP04 Trigger GP05 Echo


/***
 * Main
 * @return
 */
int main( void ){
    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    // Create an instance of the sensor
    // specify the pio, state machine, and gpio pin connected to trigger
	// echo pin must be on gpio pin trigger + 1.
    DistanceSensor* sensors[NUM_SENSORS];

	sensors[0] = new  DistanceSensor(pio0,  0, 	NORTH);
	sensors[1] = new DistanceSensor(pio0, 	1, 	EAST);
	sensors[2] = new DistanceSensor(pio0, 	2, 	SOUTH);
	sensors[3] = new DistanceSensor(pio0, 	3, 	WEST);

	for(;;){


		//Read strategy
		for (int i=0; i < NUM_SENSORS; i++){
			sensors[i]->TriggerRead();
			while (sensors[i]->is_sensing){
				sleep_us(100);
			}
		}

		// Read result
		printf("Reading ");

		for (int i=0; i < NUM_SENSORS; i++){
			printf("%d , ",sensors[i]->distance);
		}

		printf(" cm\n");

		sleep_ms(200);
	}

}
