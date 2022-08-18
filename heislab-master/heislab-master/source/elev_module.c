#include "elev_module.h"

void door_handler(enum ELEV_STATE *state, MotorDirection *dirn, int *prev_floor)
{
    elevio_doorOpenLamp(1);

    int sec = 0;
    int trigger = 1;
    clock_t clock_init = clock();
    int light_off = 0;

    while (sec < trigger) {
        read_buttons(state, dirn, prev_floor);

        if (elevio_obstruction() || elevio_stopButton()) {
            clock_init = clock();
        }
        if (elevio_stopButton()) {
            elevio_stopLamp(1);
        }

        // Makes sure elevio_stopLamp is only set to 0 once to reduce runtime
        else if (elevio_stopButton() == 0 && light_off == 0) {
            elevio_stopLamp(0);
            light_off = 1;
        }

        clock_t differense = clock() - clock_init;
        sec = differense / CLOCKS_PER_SEC;
    }
    elevio_doorOpenLamp(0);
}