/*
 * This module role is to interface between the user, the map and robot module.
 * This is the main module for controlling the program, inputs are receiving here.
 * */

#include "Interface.h"


using namespace std;

//strcmpi to compare case insensitive , strcmp for the sensitive compare
const char *commands[] = {"Move", "AddDirt", "Clean", "Place", "Delete", "MoveMulti"};

moveDirection string2enum(const string &dir) {
    moveDirection direction;
    if (dir == "U") direction = U;
    else if (dir == "D") direction = D;
    else if (dir == "L") direction = L;
    else if (dir == "R") direction = R;
    else if (dir == "UL") direction = UL;
    else if (dir == "UR") direction = UR;
    else if (dir == "DL") direction = DL;
    else if (dir == "DR") direction = DR;
    return direction;
}

void StartControl() {
    auto *robotsDB = new RobotDB;
    char line[256];
    cout << "Start entering commands:" << endl;


    string command, name, dir; // command- the command from the user, name- robot's name from the user
    moveDirection direction; // The directions that the robot needs to move in the map, input from the user
    int x, y; // coordinates for location in the map, input from the user


//    while (cin.getline(line, 256)) {
//
//    }

    while (cin >> command) {
        if (command == "AddDirt") {
            cin >> x >> y;
            if (inMapLimit(x, y)) {
                pair<int, int> xy{x, y};
                if (!robotsDB->isRobotAtLocation(xy))
                    addDirt(x, y);
            }
            continue;
        }
        cin >> name;
        Robot *curRobot = robotsDB->getRobot(name);
        if (curRobot == nullptr and command != "Place") continue;
        else if (command == "Place") {
            cin >> x >> y;
            pair<int, int> xy{x, y};
            if (curRobot == nullptr) {
                if (inMapLimit(x, y)) robotsDB->addRobot(new Robot(name, xy));
            } else {
                curRobot->setLocation(xy);
                PrintRobotPlace(name, x, y);
            }
        } else if (command == "Delete") {
            robotsDB->deleteRobot(name);
        } else if (command == "Move") {
            cin >> dir;
            direction = string2enum(dir);
            curRobot->robotMove(direction);
        } else if (command == "Clean") {
            curRobot->robotClean();
        } else if (command == "MoveMulti") {
                while (cin >> dir) {
                    if (dir == "end")
                        break;
                    direction = string2enum(dir);
                    curRobot->robotMove(direction);
                }
        } else std::cout << "Please enter a valid command" << std::endl;
    }

    PrintTable(robotsDB->getRobots(), robotsDB->getRanks(), robotsDB->getTanks());
    delete robotsDB;
}
