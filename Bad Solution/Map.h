#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>

using std::string;

/** Add a dirt to the map, meaning place 1 at x,y location
 * @param x: x coordinate
 * @param y: y coordinate
 */
void addDirt(const int x, const int y);

/** cleaning (x,y) location and return true if cleaning succeed
 * @param x: x coordinate
 * @param y: y coordinate
 */
bool clean(const int x, const int y);

/** check is (x,y) is dirty
 * @param x: x coordinate
 * @param y: y coordinate
 * @return: True if (x,y) location is dirty, false otherwise.
 */
bool isDirty(const int x, const int y);

/**
 * Check if x,y coordinates is valid. valid - if the coordinates in the map is in the map limits.
 * @param x: x coordinate
 * @param y: y coordinate
 * @return: True if the if coordinates are valid, false otherwise.
 */
bool inMapLimit (int x, int y);

/**
 * Check if robot can move to this direction in the map.
 * @param x: x coordinate
 * @param y: y coordinate
 * @return: True if robot can move to this direction in the map. False otherwise
 */
bool isDirValid (const string& dir, const int x, const int y);

/*
 * print the current map
 */
void PrintMap();

#endif
