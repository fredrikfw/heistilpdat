#pragma once
#include "driver/elevio.h"
#include "control_module.h"
/**
 * @file
 * @brief 
 * Library for simple functions connected to the floors.
 */

/**
 * @brief Checks the current floor and turns on the light of that floor. 
 * 
 */
void floor_light_on();

/**
 * @brief Turns on button lights when they are pressed.
 * 
 */
void button_light_on(int floor, ButtonType btn);

/**
 * @brief Turns off button lights. Called when a call is finished.
 * 
 */
void button_light_off(int floor, ButtonType btn);
