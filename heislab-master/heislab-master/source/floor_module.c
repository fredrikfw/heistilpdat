#include "floor_module.h"


void floor_light_on() {
    int current_floor = elevio_floorSensor();
    if(current_floor != -1){
        elevio_floorIndicator(current_floor);
    }
    
}

void button_light_on(int floor, ButtonType btn) {
    if( floor >= 0 && floor <= 3) {
        elevio_buttonLamp(floor, btn, 1);    
    }
}


void button_light_off(int floor, ButtonType btn) {
    if(floor >= 0 && floor <= 3) { 
        elevio_buttonLamp(floor, btn, 0);    
    }
}