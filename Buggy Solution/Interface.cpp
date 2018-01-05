/*
 * This module role is to interface between the user, the map and robot module.
 * This is the main module for controlling the program, inputs are receiving here.
 * */
#include <iostream>
#include <string>
#include "Interface.h"
#include "RobotDB.h"
#include "Map.h"
#include "MoveRobot.h"
#include "Printer.h"

using std::cin;
using std::string;

#define TANK_FULL (5) // define threshold for full the cleaning tank

void StartControl() {
    string command, name; // command- the command from the user, name- robot's name from the user
    string dir; // The directions that the robot needs to move in the map, input from the user
    int x, y; // coordinates for location in the map, input from the user

    std::cout << "Start entering commands:" << std::endl;

    while (cin >> command) {
        if (command == "Place") {
            cin >> name >> x >> y;
            if (inMapLimit(x, y) && place_robot(name, x, y)) {
                PrintRobotPlace(name, x, y);
            }
        } else if (command == "Delete") {
            cin >> name;
            delete_robot(name);
        } else if (command == "Move") {
            cin >> name >> dir;
            move(name, dir);
        } else if (command == "AddDirt") {
            cin >> x >> y;
            if (inMapLimit(x, y))
                if (!is_location_robot(x, y))
                    addDirt(x, y);
        } else if (command == "Clean") {
            cin >> name;
            const int index = find_robot(name);
            if (index != -1) {
                get_cord(index, x, y);
                if (getTankCounter(index) <= TANK_FULL) {
                    if (x != -1 && y != -1) {
                        bool dirty = isDirty(x, y);
                        clean(x, y);
                        updateTank(index);
                        if (dirty)
                            updateRank(index);
                        PrintClean(name, x, y);
                    }
                } else emptyTank(name, index);
            }

        } else if (command == "MoveMulti") {
            cin >> name;
            cin >> dir;
            do {
                move(name, dir);
                cin >> dir;
            } while (dir != "end");
        } else std::cout << "Please enter a valid command" << std::endl;

        /* just for debugging */
//        PrintMap();
//        PrintTable(getRobots(), getRanks(), getTanks());
    }
    PrintTable(getRobots(), getRanks(), getTanks());
}
