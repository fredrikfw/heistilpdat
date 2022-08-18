#include "queue_module.h"

/*void add_order(State s, dirn, knapp ) {
    if(s = standby){
        pri = 1;
    }

    if(s = )
}
*/

void init_floor(void){
        if (elevio_floorSensor() == -1) {
        elevio_motorDirection(-1);
    }

    while (elevio_floorSensor() == -1){ //waits for elevator to reach a floor
    }

    elevio_motorDirection(0);
}

void stop(){
    int stop_yn = elevio_stopButton();
    if(stop_yn == 1){
        elevio_stopLamp(1);
        elevio_motorDirection(0);
    } 
}

void run_elevator(){

    //mulige states
    typedef enum { 
    INIT   = 0,
    STANDBY   = 1,
    FLOOR_REACHED = 2,
    STOP = 3,
    } ELEV_STATE;
    
    ELEV_STATE state = INIT;  //settes automatisk til init

    //looper gjennom
    while(1) {
        
        if(elevio_stopButton() == 1){  //må alltid sjekke om det er stop
            state = STOP;
        }

        switch(state){
            case INIT:
                if (elevio_floorSensor == -1) {
                    elevio_motorDirection(-1);
                }

                while (elevio_floorSensor == -1){ //waits for elevator to reach a floor
                }

                elevio_motorDirection(0);
                state = STANDBY;
                break;
            
            case STANDBY:
                //while not order, wait
                //add_order(standby, dirn, )

                //if order, state = GO_TO
                
                break;

            case STOP:
                elevio_motorDirection(0);

                if(elevio_floorSensor() != -1){
                        floor_reached();
                                                
                    }

                while(elevio_stopButton() == 1) {
                    elevio_stopLamp(1);
                    //delete queue
                    
                }
                
                init_floor();
                state = STANDBY;
                break;

            case GO_TO:
                

                break;
        }
    }
}

void add_order(ELEV_STATE state, MotorDirection dirn, int current_floor, int order_floor, ButtonType btn) {

}