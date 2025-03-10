#include "../include/traffic_light.h"
#include <stdio.h>
#include <unistd.h> // For sleep()

void runTrafficLight(LightState *currentState) {
    printf("Traffic Light System\n");

    // State machine Loop
    while (1) { // Forever loop
        switch (*currentState) {
            case NS_RED_EW_GREEN:
                printf("NS:Red, EW: Green\n");
                sleep(10); // Green for 10 seconds
                setLightState(currentState, NS_RED_EW_YELLOW);
                break;

            case NS_RED_EW_YELLOW:
                printf("NS:Red, EW: Yellow\n");
                sleep(3); // Yellow for 3 seconds
                setLightState(currentState, NS_GREEN_EW_RED);
                break;

            case NS_GREEN_EW_RED:
                printf("NS:Green, EW: Red\n");
                sleep(10); // NS Green for 10 seconds
                setLightState(currentState, NS_YELLOW_EW_RED);
                break;

            case NS_YELLOW_EW_RED:
                printf("NS:Yellow, EW: Red\n");
                sleep(3); // NS Yellow for 3 seconds
                setLightState(currentState, NS_RED_EW_GREEN);
                break;

            default: // Invalid state handling
                printf("Invalid State!\n");
                printf("NS:Flashing Yellow, EW:Flashing Yellow\n");
                break;
        }
    }
}

/* Setter function to update the state */
void setLightState(LightState *currentState, LightState newState) {
    *currentState = newState;
}

#ifndef TESTING
// Main program
int main() {
    LightState currentState = NS_RED_EW_GREEN; // Initial state
    runTrafficLight(&currentState);
    return 0;
}
#endif
