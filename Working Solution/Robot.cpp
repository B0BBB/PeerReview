#include "Robot.h"
#include "Map.h"

using namespace std;
#define OUT pair<int, int> (-1,-1)
#define INIT pair<int, int> (0, 0)
#define TANK_FULL (5) // define threshold for full the cleaning tank

void Robot::robotClean() {
    if (location != OUT) {
        if (tank < TANK_FULL) {
            if (cleanDirt(location)) {
                updateRank();
            }
            tank++;
            PrintClean(name, location.first, location.second);
        } else {
            setLocation(INIT);
            tank = 0;
        }
    }
}

void Robot::robotMove(const moveDirection direction) {
    if (location == OUT) return;
    pair<int, int> newLocation = location;
    switch (direction) {
        case U:
            newLocation.first--;
            break;
        case D:
            newLocation.first++;
            break;
        case L:
            newLocation.second--;
            break;
        case R:
            newLocation.second++;
            break;
        case UL:
            newLocation.first--;
            newLocation.second--;
            break;
        case UR:
            newLocation.first--;
            newLocation.second++;
            break;
        case DL:
            newLocation.first++;
            newLocation.second--;
            break;
        case DR:
            newLocation.first++;
            newLocation.second++;
            break;
        default:
            std::cout << "Please enter a valid command" << std::endl;
            break;
    }
    if (inMapLimit(newLocation))
        setLocation(newLocation);
    else setLocation(OUT);

    PrintRobotPlace(name, location.first, location.second);
}

void Robot::setLocation(const pair<int, int> newLocation) {
    if (inMapLimit(newLocation))
        location = newLocation;
    else location = OUT;
}

void Robot::emptyTank() {
    tank = 0;
    PrintRobotPlace(name, location.first, location.second);
}

//TODO: Update the rank of the Robot
void Robot::updateRank() {
    rank++;
}
