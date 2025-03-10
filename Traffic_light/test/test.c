#include "../include/traffic_light.h"
#include <stdio.h>

/* Test function to verify state transitions */
void testTrafficLight() {
    LightState currentState;

    // Test Case 1: Verify initial state transition (NS_RED_EW_GREEN -> NS_RED_EW_YELLOW)
    currentState = NS_RED_EW_GREEN;
    setLightState(&currentState, NS_RED_EW_YELLOW);
    if (currentState != NS_RED_EW_YELLOW) {
        printf("Test Case 1 Failed: Expected NS_RED_EW_YELLOW, got %d\n", currentState);
    } else {
        printf("Test Case 1 Passed\n");
    }

    // Test Case 2: Verify state transition (NS_RED_EW_YELLOW -> NS_GREEN_EW_RED)
    currentState = NS_RED_EW_YELLOW;
    setLightState(&currentState, NS_GREEN_EW_RED);
    if (currentState != NS_GREEN_EW_RED) {
        printf("Test Case 2 Failed: Expected NS_GREEN_EW_RED, got %d\n", currentState);
    } else {
        printf("Test Case 2 Passed\n");
    }

    // Test Case 3: Verify state transition (NS_GREEN_EW_RED -> NS_YELLOW_EW_RED)
    currentState = NS_GREEN_EW_RED;
    setLightState(&currentState, NS_YELLOW_EW_RED);
    if (currentState != NS_YELLOW_EW_RED) {
        printf("Test Case 3 Failed: Expected NS_YELLOW_EW_RED, got %d\n", currentState);
    } else {
        printf("Test Case 3 Passed\n");
    }

    // Test Case 4: Verify state transition (NS_YELLOW_EW_RED -> NS_RED_EW_GREEN)
    currentState = NS_YELLOW_EW_RED;
    setLightState(&currentState, NS_RED_EW_GREEN);
    if (currentState != NS_RED_EW_GREEN) {
        printf("Test Case 4 Failed: Expected NS_RED_EW_GREEN, got %d\n", currentState);
    } else {
        printf("Test Case 4 Passed\n");
    }

    // Test Case 5: Verify invalid state handling
    currentState = (LightState)46; // Invalid state
    setLightState(&currentState, NS_RED_EW_GREEN); // Try to set a valid state
    if (currentState != NS_RED_EW_GREEN) {
        printf("Test Case 5 Failed: Expected state to change to NS_RED_EW_GREEN\n");
    } else {
        printf("Test Case 5 Passed\n");
    }
}

#ifdef TESTING
// Test program
int main() {
    printf("Running Traffic Light State Machine Test Suite...\n");
    testTrafficLight();
    return 0;
}
#endif
