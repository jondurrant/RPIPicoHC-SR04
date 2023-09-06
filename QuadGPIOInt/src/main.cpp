/***
 *
 * Jon Durrant
 * 15-Aug-2022
 */


#include "pico/stdlib.h"
#include "HCSR04Range.h"
#include "stdio.h"

#define NUM_SENSORS 4

#define WEST  		06		//GP06 Trigger GP07 Echo
#define NORTH  	18		//GP18 Trigger GP19 Echo
#define EAST  		14		//GP14 Trigger GP15 Echo
#define SOUTH  	20		//GP20 Trigger GP21 Echo

/***
 * Main
 * @return
 */
int main( void ){
    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    HCSR04Range *ranges[NUM_SENSORS];
    ranges[0] = new HCSR04Range(WEST, WEST +1);
    ranges[1] = new HCSR04Range(NORTH, NORTH +1);
    ranges[2] = new HCSR04Range(EAST, EAST +1);
    ranges[3] = new HCSR04Range(SOUTH, SOUTH +1);



	for(;;){

		for (int i=0; i < NUM_SENSORS; i++){
			ranges[i]->trigger();
			sleep_ms(100);
		}


		sleep_ms(100);
		printf("Range ");

		for (int i=0; i < NUM_SENSORS; i++){
			printf("%d, ", ranges[i]->getDistanceMM());
		}

		printf(" mm\n");

		sleep_ms(200);
	}

}
