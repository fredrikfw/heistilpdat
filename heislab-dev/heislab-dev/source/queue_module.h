#pragma once
#include "driver/elevio.h"
/**
 * @file
 * @brief 
 * Library for queue and overall control
 */

/**
 * @brief 
 * Structure for holding array of order and other data related to the elevator
 * and its movement
 */
struct Queue{
    int orders[100];
    int ready;          //door closed and ready to move to new floor?
    int elev_floor;
    int state_motor;
    int next_floor;
};

typedef enum { 
    INIT   = 0,
    STANDBY   = 1,
    GO_TO = 2,
    FLOOR_REACHED = 3,
    STOP = 3,
    } ELEV_STATE;
    
/**
 * @brief Init, drive elevator to known floor
 * 
 */
void init_floor(void);

/**
 * @brief Read stop button from elevator, set motor drive to zero
 * 
 */
int check_stop();


/**
 * @brief 
 * 
 */
void run_elevator();

//void add_order(State s, dirn, knapp )
