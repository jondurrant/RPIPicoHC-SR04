/***
 *
 * Jon Durrant
 * 15-Aug-2022
 */


#include "pico/stdlib.h"
#include "HCSR04Range.h"
#include "stdio.h"

#define TRIG_GP  	14
#define ECHO_GP 	15


/***
 * Main
 * @return
 */
int main( void ){
    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    HCSR04Range range(TRIG_GP,  ECHO_GP);


	for(;;){
		range.trigger();
		sleep_ms(10);

		printf("Range %d mm\n", range.getDistanceMM());

		sleep_ms(200);
	}

}
