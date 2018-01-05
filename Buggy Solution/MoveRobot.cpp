/*
 * MoveRobot module role is to implement all logic of the robot's movements.
 * */
#include <iostream>
#include <string>
#include <vector>
#include "RobotDB.h"
#include "Map.h"
#include "Printer.h"
#include "MoveRobot.h"

using std::vector;
using std::string;

/**
 * ###################### Module functions ######################
 */

void move (const string& robotName, const string& dir)
{
    int index=find_robot(robotName);
    int x=0,y=0;
    if (index==-1)
        return;
    else
    {
        get_cord(index,x,y);
        if (x == -1 || y == -1)
        	return;
        if (isDirValid(dir,x,y)){
        	if (dir=="L")
        		y--;
        	else if (dir=="R")
        		y++;
        	else if (dir=="U")
        		x--;
        	else if (dir=="D")
        		x++;
        	else if (dir=="UR"){
        		x--;
        		y++;
        	}
        	else if (dir=="UL"){
        		x--;
        		y--;
        	}
			else if (dir=="DR"){
				x++;
				y++;
			}
			else if (dir=="DL"){
				x++;
				y++;
			}
			else return;
        }
		else{
			x = -1;
			y = -1;
		}
		change_location (index, x, y);
		PrintRobotPlace (robotName, x, y);
    }
}

