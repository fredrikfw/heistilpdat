#include "elev_module.h"

void floor_reached() {
    elevio_doorOpenLamp(1);

    int sec = 0;
    int trigger = 3;
    clock_t clock_init = clock();

    while(sec < trigger) {
        if(elevio_obstruction() || elevio_stopButton()) {
            clock_init = clock();
        }
        if(elevio_stopButton()) {
            elevio_stopLamp(1);
        }
        
        clock_t differense = clock() - clock_init;
        sec = differense / CLOCKS_PER_SEC;
    }
    
    elevio_doorOpenLamp(0);
}