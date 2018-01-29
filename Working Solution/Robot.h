#ifndef Robot1_ROBOT_H
#define Robot1_ROBOT_H

#include <utility> //std::pair, std::make_pair
#include <string>
#include "Printer.h"

using namespace std;

typedef enum {
    U, D, L, R, UR, UL, DR, DL
} moveDirection;

class Robot {
public:
    void robotMove(moveDirection direction);

    void robotClean();

    const string getRobotName() const { return name; };

    const pair<int, int> &getLocation() const { return location; };

    const int getRobotTank() const { return tank; }

    const int getRobotRank() const { return rank; }

    void setLocation(pair<int, int> location);

    Robot(string &robot_name, pair<int, int> &robot_location) {
        name = robot_name;
        location = robot_location;
        tank = 0;
        rank = 0;
        PrintRobotPlace(name, location.first, location.second);
    }

    ~Robot() {};

private:
    pair<int, int> location;
    string name;
    int tank;
    int rank;

    void emptyTank();

    void updateRank();
};

#endif //Robot1_ROBOT_H