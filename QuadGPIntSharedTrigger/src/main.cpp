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

    HCSR04Range ranges(SOUTH, WEST +1);

	ranges.addEcho(NORTH +1);
	ranges.addEcho(EAST +1);
	ranges.addEcho( SOUTH +1);



	for(;;){

		ranges.trigger();

		sleep_ms(100);
		printf("Range ");

		for (int i=0; i < NUM_SENSORS; i++){
			printf("%d, ", ranges.getDistanceMM(i));
		}

		printf(" mm\n");

		sleep_ms(200);
	}

}
