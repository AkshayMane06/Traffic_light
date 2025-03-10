Traffic Light Simulation
This project simulates a traffic light system using a state machine approach. The system ensures that traffic flows in one direction (e.g., North-South) while stopping traffic in the perpendicular direction (e.g., East-West). It follows a strategy where signals in opposite directions are always in complementary states to avoid collisions.

Project Structure
bash
Copy
traffic_light_project/
│
├── src/
│   ├── traffic_light.c  # Main program logic and state machine implementation
│
├── include/
│   └── traffic_light.h  # Header file for the traffic light system
│
├── test/
│   └── test.c           # Test suite to verify state transitions and edge cases
│
└── Makefile             # Makefile to build, run, and clean the project
Components Overview
traffic_light.c
Contains the main() function and the core logic of the traffic light system.
Implements the runTrafficLight() function, which manages the state transitions and timing.
traffic_light.h
Defines the LightState enum, which outlines the possible states for the traffic lights.
Declares the runTrafficLight() and setLightState() functions.
test.c
Contains a test suite to ensure the correctness of state transitions.
Tests all possible state transitions and edge cases to ensure the system operates as expected.
Makefile
Provides the build instructions for the project.
Contains targets to build the main program, run the tests, and clean up the build artifacts.
Assumptions and Behavior
Opposite States
When one direction (e.g., North-South) is green, the perpendicular direction (e.g., East-West) will always be red.
This ensures that traffic flows in one direction while stopping traffic in the opposite direction.
State Combinations
The system uses state combinations to manage the traffic light states for both North-South (NS) and East-West (EW) directions. The following are examples:

NS_GREEN_EW_RED: North-South traffic flows (green), while East-West traffic is stopped (red).
NS_YELLOW_EW_RED: North-South traffic prepares to stop (yellow), while East-West traffic remains stopped (red).
Naming Convention
Enum states are named in uppercase for consistency and clarity. Example: NS_RED_EW_GREEN, NS_YELLOW_EW_RED.
State Transitions
Each direction follows a fixed sequence: Green → Yellow → Red.
When one direction is green or yellow, the opposite direction must be red to avoid conflicts.
No Simultaneous Red States: The system ensures that both directions are not red at the same time to maintain efficiency.
Looping Behavior
The system cycles through all states indefinitely, transitioning through them in a fixed sequence.
Invalid State Handling
If an invalid state is encountered, the system defaults to flashing yellow lights in both directions as a cautionary measure.
How It Works
Initial State
The system begins in the NS_RED_EW_GREEN state.
State Timing
Green state: Lasts for 10 seconds.
Yellow state: Lasts for 3 seconds.
After the set duration, the system automatically transitions to the next state.
Continuous Operation
The system loops indefinitely, transitioning through all states in a cyclic manner.
Invalid State Recovery
If the system encounters an invalid state, it will display flashing yellow lights for both directions as a warning.
How to Build and Run the Project
Prerequisites
GCC (GNU Compiler Collection) installed.
Make installed.
Steps
Clone the repository:

bash
Copy
git clone <repository-url>
cd traffic_light_project
Build the project:

bash
Copy
make
Run the main program:

bash
Copy
make run
Run the tests:

bash
Copy
make test
Clean the build:

bash
Copy
make clean
Future Enhancements
Pedestrian Crossing Button: Add a feature to handle pedestrian crossings by interrupting the light cycle with a timer.
Green Arrow for Turns: Implement a green arrow for specific turn lanes to allow more controlled traffic flow.
