#include "control_module.h"




void stop(){
    int stop_yn = elevio_stopButton();
    if(stop_yn == 1){
        elevio_stopLamp(1);
        elevio_motorDirection(0);
    } 
}

 

void run_elevator(){


    
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
                //check vector
                //drive elevator
                break;

            case STOP:
                elevio_stopLamp(1);
                elevio_motorDirection(0);
                //delete queue
                break;

            default:
                break;
        }
    
    }

}