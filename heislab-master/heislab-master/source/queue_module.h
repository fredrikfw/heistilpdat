#pragma once
#include "control_module.h"

/**
 * @file
 * @brief 
 * A library for handeling the queue as well as other functions concerning the queue.
 * The queue is seperated into three arrays that are prioritized differently.
 * @param on_the_way_calls Array that holds calls that happen on the way as the
 * elevator is moving. This array is prioritized first. An example would be if the
 * elevator is moving frpom the first floor to the fourth and someone presses the 
 * up button on the third floor.
 * @param cab_calls Array the holds calls coming thom inside the elevator. This array is
 * prioritized second.
 * @param floor_calls Array the holds calls coming from outside the elevator that
 * does not fall into on_the_way_orders. These calls are prioritize last.
 * @param array_size Size of each array. Used to iterate through the arrays.
 */


/**
 * @brief Deletes all calls from all queues. 
 * 
 */
void empty_queue();

/**
 * @brief Adds a given call to a chosen array.  
 * @param[in] arr The array in which to put the call.
 * @param[in] call The floor that the elevator is called to.
 */
void add_to(int arr[], int call);

/**
 * @brief Returns the next floor the elevator should go to. This is where the prioritization
 * of the arrays happens.
 * @param[out] next_floor The floor that the elevator shoud go to.
 * 
 */
int next_floor();


/**
 * @brief Removes the current finished call from all arrays. 
 * 
 * @param[in] current_floor The current call that was just finished.
 */
void call_finished(int current_floor);


/**
 * @brief Reads all buttons and adds calls to queue. 
 * 
 * @param[in] state The current state of the system.
 * @param[in] dirn Current motor direction of the elevator.
 * @param[in] prev_floor Previous defined floor which the elevator was at.
 */
void read_buttons(enum ELEV_STATE *state, MotorDirection *dirn, int *prev_floor);

/**
 * @brief This function deicides which array to add a call to. If a call is already in 
 * a queue it will not be added to an array. 
 * 
 * @param[in] state The current state of the system.
 * @param[in] dirn Current motor direction of the elevator.
 * @param[in] call_floor The floor which the elevator is called to.
 * @param[in] prev_floor Previous defined floor which the elevator was at.
 * @param[in] btn The button type of the call. 
 */
void add_call(enum ELEV_STATE *state, MotorDirection *dirn, int call_floor, int *prev_floor, ButtonType btn);


