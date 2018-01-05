#ifndef MOVEROBOT_H
#define MOVEROBOT_H

#include <iostream>
#include <string>

/**
 * Move the robot to this direction in the map if it is possible.
 * Function will change the robot's position if it's possible. if not - the position will be define by (-1,-1)
 * @param robotName: robot's name
 * @param dir: the wanted direction (L,, LU, LD ,R, RU, RD, D, U,)
 */

void move (const std::string& robotName, const std::string& dir);

#endif

