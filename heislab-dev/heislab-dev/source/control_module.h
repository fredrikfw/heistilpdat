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

//mulige states
typedef enum { 
INIT   = 0,
STANDBY   = 1,
FLOOR_REACHED = 2,
STOP = 3,
} ELEV_STATE;


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