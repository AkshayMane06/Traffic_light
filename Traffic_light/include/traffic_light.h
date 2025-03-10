#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <stdio.h>
#include <unistd.h> // For sleep()

/* Defining States */
typedef enum {
    NS_RED_EW_GREEN,    // North-South: Red, East-West: Green
    NS_RED_EW_YELLOW,   // North-South: Red, East-West: Yellow
    NS_GREEN_EW_RED,    // North-South: Green, East-West: Red
    NS_YELLOW_EW_RED    // North-South: Yellow, East-West: Red
} LightState;

/* Function Declarations */
void runTrafficLight(LightState *currentState);
void setLightState(LightState *currentState, LightState newState);

#endif