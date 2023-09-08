/***
 *
 * Jon Durrant
 * 15-Aug-2022
 */


#include "pico/stdlib.h"
#include "HCSR04Range.h"
#include "stdio.h"

#define NUM_SENSORS 4

#define TRIG	0

#define NORTH  	2
#define EAST  	3
#define SOUTH  	4
#define WEST  	5

/***
 * Main
 * @return
 */
int main( void ){
    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    HCSR04Range ranges(TRIG, NORTH);

	ranges.addEcho(EAST);
	ranges.addEcho(SOUTH);
	ranges.addEcho( WEST);



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
