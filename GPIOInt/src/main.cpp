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

    HCSR04Range range(WEST, WEST +1);


	for(;;){
		range.trigger();
		sleep_ms(10);

		printf("Range %d mm\n", range.getDistanceMM());

		sleep_ms(200);
	}

}
