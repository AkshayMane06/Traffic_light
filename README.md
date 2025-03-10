This project simulates a traffic light system using a state machine approach. The system ensures that traffic flows in one direction (e.g., North-South) while stopping traffic in the perpendicular direction (e.g., East-West). The system follows a strategy where the signals in opposite directions are always in complementary states to avoid collisions.

project structure 

traffic_light_project/
│
├── src/
│   ├── traffic_light.c  # Main program
│
├── include/
│   └── traffic_light.h  # Header file
│
├── test/
│   └── test.c           # Test program
│
└── Makefile             # Makefile


traffic_light.c:

Contains the main() function and the implementation of the traffic light state machine.

Defines the runTrafficLight() function, which handles the state transitions and timing.

traffic_light.h:

Contains the LightState enum, which defines the possible states of the traffic light system.

Declares the runTrafficLight() and setLightState() functions.

test.c:

Contains the test suite to verify the correctness of the state transitions.

Tests all possible state transitions and edge cases.

Makefile:

Compiles and links the project.

Provides targets for building the main program, running tests, and cleaning the build artifacts.


Assumptions
Opposite States:

If the signal is green in one direction (e.g., North-South), the signal in the perpendicular direction (e.g., East-West) must be red.

This ensures that traffic flows in one direction while stopping traffic in the opposite direction.

State Combinations:

The system combines states for North-South (NS) and East-West (EW) traffic.

For example:

NS_GREEN_EW_RED: North-South traffic flows (green), while East-West traffic is stopped (red).

NS_YELLOW_EW_RED: North-South traffic prepares to stop (yellow), while East-West traffic remains stopped (red).

Naming Convention:

Enum states are named in uppercase letters for clarity and consistency.

Example: NS_RED_EW_GREEN, NS_YELLOW_EW_RED.

State Transitions:

Each direction (NS and EW) follows a sequence: Green → Yellow → Red.

When one direction is green or yellow, the opposite direction must be red.

No Simultaneous Red States:

The system does not allow both directions to be red at the same time, as this would be inefficient and unnecessary.

Looping Behavior:

The system loops indefinitely, transitioning through all states in a cyclic manner.


How It Works
Initial State:

The system starts in the NS_RED_EW_GREEN state.

State Transitions:

Each state has a fixed duration:

Green: 10 seconds.

Yellow: 3 seconds.

After the duration elapses, the system transitions to the next state.

Looping:

The system cycles through all states indefinitely.

Invalid State Handling:

If an invalid state is encountered, the system defaults to flashing yellow lights in both directions as a cautionary measure.

How to Build and Run
Prerequisites
GCC (GNU Compiler Collection) installed.

Make installed.

Steps
1.Clone the Repository:

git clone <repository-url>
cd traffic_light_project

2.Build the Project:
make


3.Run the Main Program:
make run

4.Run the Tests:
make test

5.Clean the Build:
make clean

Future Enhancements 
1. Pedestrian Crossing button interrupt set timer. 
2. Green Arrows for turn.
