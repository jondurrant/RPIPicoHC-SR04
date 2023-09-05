/***
 *
 * Jon Durrant
 * 15-Aug-2022
 */


#include "pico/stdlib.h"
#include "distance_sensor.h"
#include "stdio.h"

#define NUM_SENSORS 4

#define WEST  		06		//GP06 Trigger GP07 Echo
#define EAST  		14		//GP14 Trigger GP15 Echo
#define NORTH  	18		//GP18 Trigger GP19 Echo
#define SOUTH  	20		//GP20 Trigger GP21 Echo


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

	sensors[0] = new  DistanceSensor(pio0, 0, 		WEST);
	sensors[1] = new DistanceSensor(pio0, 	1, 		NORTH);
	sensors[2] = new DistanceSensor(pio0, 	2, 	EAST);
	sensors[3] = new DistanceSensor(pio0, 	3, 	SOUTH);

	for(;;){


		//Read strategy 2
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
