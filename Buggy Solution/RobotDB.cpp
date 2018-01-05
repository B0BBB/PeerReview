/*
 * RobotDB module holds the database of all the robots and implement the functionality of robot interface.
 * */
#include <iostream>
#include <string>
#include <vector>
#include "RobotDB.h"

using std::vector;
using std::string;

vector<string> robots; // vector that holds all the robot's name that the user insert
vector<int> cord_x; // vector that holds the suitable x coordinates that the user insert. represent the rows!
vector<int> cord_y; // vector that holds the suitable y coordinates that the user insert. represent the columns!
vector<int> ranks; // vector that all the vector ranks
vector<int> tankCounter; // vector that all the vector tank counter

/**
 * ###################### Module functions ######################
 */


bool place_robot (const string& robotName, const int x, const int y)
{
    int index=find_robot(robotName);
    if (index==-1)
    {
        robots.push_back(robotName);
        cord_x.push_back(x);
        cord_y.push_back(y);
        ranks.push_back(0);
        tankCounter.push_back(0);
        return true;
    }
    else
    {
		vector<int>::iterator iter_x = cord_x.begin()+index;
		vector<int>::iterator iter_y = cord_y.begin()+index;
		if (x==*iter_x && y==*iter_y)
			return false;
		else
		{
			*iter_x=x;
			*iter_y=y;
			return true;
		}
    }
}

//####################################################################################################

void delete_robot (const string& robotName)
{
    int index=find_robot(robotName);
    if (index==-1)
        return;
    else
    {
        vector<string>::iterator iter_r = robots.begin()+index;
        vector<int>::iterator iter_x = cord_x.begin()+index;
        vector<int>::iterator iter_y = cord_y.begin()+index;
        robots.erase(iter_r);
        cord_x.erase(iter_x);
        cord_y.erase(iter_y);
    }
}

//####################################################################################################

bool is_location_robot(const int x, const int y)
{
     for (vector<int>::iterator iter_x = cord_x.begin (), iter_y = cord_y.begin (); iter_x != cord_x.end (); iter_x++, iter_y++ ){
    if (*iter_x==x && *iter_y==y){
       return true;
   }
}
 return false;
}

//####################################################################################################

int find_robot(const string& robotName)
{
    for (vector<string>::size_type i = 0; i != robots.size (); i++)
    {
        if (robots[i]==robotName)
        {
            return i;
        }
    }
    return -1;
}

//####################################################################################################

void get_cord(const int index, int& x, int& y)
{
     vector<int>::iterator iter_x = cord_x.begin()+index;
     vector<int>::iterator iter_y = cord_y.begin()+index;
     x=*iter_x;
     y=*iter_y;
}

//####################################################################################################

void change_location (const int index, const int x, const int y)
{
    vector<int>::iterator iter_x = cord_x.begin()+index;
    vector<int>::iterator iter_y = cord_y.begin()+index;
    *iter_x=x;
    *iter_y=y;
}

//####################################################################################################

void updateRank(const int index)
{
	ranks[index]++;
}

//####################################################################################################

void updateTank(const int index)
{
	tankCounter[index]++;
}

//####################################################################################################


vector<string> getRobots(){
	return robots;
}

//####################################################################################################

vector<int> getRanks(){
	return ranks;
}

//####################################################################################################

vector<int> getTanks(){
	return tankCounter;
}

//####################################################################################################

int getTankCounter(const int index){
	return tankCounter[index];
}

//####################################################################################################

void emptyTank(const string& robotName, const int index){
	place_robot(robotName, 0 ,0);
	tankCounter[index]=0;
}
