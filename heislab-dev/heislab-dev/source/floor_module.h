#pragma once
#include "driver/elevio.h"

/**
 * @file
 * @brief 
 * Library for floor
 */

/**
 * @brief Structure for holding data for each floor. Each floor have a unique initialization 
 * of the struct
 * 
 */
struct Floor{
    int this_floor;  
    int floor_btn;

    int bool_floor_light;
    int bool_elev_on_floor;

};



/**
 * @brief floor light on
 * 
 */
void floor_light_on();