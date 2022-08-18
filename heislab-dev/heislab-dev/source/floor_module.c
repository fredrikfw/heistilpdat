#include "floor_module.h"

void floor_light_on() {
    int current_floor = elevio_floorSensor();
    if(current_floor != -1){
        elevio_floorIndicator(current_floor);
    }
    
}

