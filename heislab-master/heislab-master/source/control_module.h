#pragma once
#include "driver/elevio.h"
#include "elev_module.h"
#include "stdio.h"
#include <string.h>
#include "queue_module.h"
#include "floor_module.h"

/**
 * @file
 * @brief 
 * Library for overall control of the whole system. 
 */

/**
 * @brief States of the system used for the state machine.
 * @param INIT Inital state of the system when the elevator is turned on.
 * Drives the elevator to a defined floor.
 * @param STANDBY State where the elevator is not doing anything and is ready to
 * take calls. The system returns to this state after each finished call.
 * @param GO_TO The state where the elevator is moving.
 * @param FLOOR_REACHED State where the elevator has reached a call floor and 
 * has to open and close the door.
 * @param STOP State when the stop button is pressed.
 * 
 */
enum ELEV_STATE{
    INIT = 1,
    STANDBY = 2,
    GO_TO = 3,
    FLOOR_REACHED = 4,
    STOP = 5   
}ELEV_STATE;


/**
 * @brief The state machine of the system. Put the system in the appropriate state given the input parameters
 * and the natural behavior of an elevator. The different states calls a variety of functions to give the states
 * their wanted behaviour. 
 * @param[in] state The current state of the system.
 * @param[in] dirn Current motor direction of the elevator.
 * @param[in] prev_floor Previous defined floor which the elevator was at.
 * 
 */
void run_elevator(enum ELEV_STATE *state, MotorDirection *dirn, int *prev_floor);

/**
 * @brief The elevator goes to the specified floor.
 * @param[in] floor The specified floor the elevator will go to.
 * @param[in] prev_floor Previous defined floor which the elevator was at.
 * @param[in] dirn Current motor direction of the elevator.
 * 
 */
void go_to_floor(int floor, int *prev_floor, MotorDirection *dirn);
