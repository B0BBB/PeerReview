#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>

using std::string;

/** Add a dirt to the map, meaning place 1 at x,y location
 * @param x: x coordinate
 * @param y: y coordinate
 */
void addDirt( int x,  int y);

/**
 * Check if x,y coordinates is valid. valid - if the coordinates in the map is in the map limits.
 * @param x: x coordinate
 * @param y: y coordinate
 * @return: True if the if coordinates are valid, false otherwise.
 */
bool inMapLimit (int x, int y);
bool inMapLimit (std::pair<int, int> xy);

int** getMap();
int getMapWidth();
int getMapHight();

void cleanDirt(int x, int y);
bool cleanDirt(const std::pair<int, int> xy);

#endif