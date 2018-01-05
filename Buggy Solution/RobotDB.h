#ifndef ROBOTDB_H
#define ROBOTDB_H

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

/*
 * Place robot in the map according to given coordinates
 * @param robotName: robot's name
 * @param x: x coordinate - represent the row!
 * @param y: y coordinate - represent the column!
 * @return: True, If the robot exist and the input coordinates are different from the original coordinates of the robots, otherwise false
 * moreover, if the robot isn't exist we will create a new robot and place him in the desire coordinates, and returns true.
 */
bool place_robot (const string& robotName, const int x, const int y) ;

/*
 * Search robot's location in the map. once it find the location - delete the robot, if the robot not exist do nothing.
 * @param robotName: robot's name
 */
void delete_robot (const string& robotName);

/*
 * Check if there is a robot in coordinates x,y
 * @param x: x coordinate
 * @param y: y coordinate
 * @retyrn: True if there is a robot in x,y. false, otherwise.
 */
bool is_location_robot (const int x, const int y);

/*
 * function that gets robot's name and return the index if there is one already in the map, and -1 if there isn't.
 * @param robotName: robot's name
 */
int find_robot (const string& robotName);

/*
 * Change the x and y values to the x and y robot's Coordinates.
 * @param index: robot's location in the vector.
 * @param x: x coordinate
 * @param y: y coordinate
 */
void get_cord (const int index, int& x, int& y);

/*
 * Change robot location to x and y Coordinates.
 * @param index: robot's location in the vector.
 * @param x: x coordinate
 * @param y: y coordinate
 */
void change_location (const int index, const int x, const int y);

/*
 * update the rank of of robot in index
 * @param index: robot's location in the vector.
 */
void updateRank(const int index);

/*
 * update the rank of of tankCouner in index
 * @param index: robot's location in the vector.
 */
void updateTank(const int index);

/*
 * get function for robots vector
 */
vector<string> getRobots();

/*
 * get function for ranks vector
 */
vector<int> getRanks();

/*
 * get function for tanksCounter vector
 */
vector<int> getTanks();

/*
 * get function for tanksCounter specific index
 */
int getTankCounter(const int index);

/*
 * empty the cleaning tank for a specific robot (index)
 */
void emptyTank(const string& robotName,const int index);

#endif

