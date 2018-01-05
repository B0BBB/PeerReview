#include <iostream>
#include "Map.h"
#include <string>

#define S_HIGH (7) // define the numbers of rows
#define S_WIDTH (7) // define the numbers of columns

using std::string;

int gmap [S_HIGH][S_WIDTH] =
{
{ 0 , 1 , 1 , 1 , 1 , 1 , 1},
{ 1 , 0 , 0 , 0 , 1 , 0 , 1},
{ 0 , 0 , 1 , 1 , 1 , 0 , 1},
{ 1 , 0 , 0 , 0 , 0 , 0 , 1},
{ 1 , 1 , 1 , 0 , 1 , 0 , 1},
{ 1 , 0 , 0 , 0 , 0 , 0 , 1},
{ 1 , 0 , 1 , 1 , 1 , 1 , 1}
} ;

/**
 * ###################### Module functions ######################
 */

void addDirt(const int x, const int y)
{
    if (inMapLimit(x,y))
        gmap[x][y]=1;
}

//####################################################################################################

bool inMapLimit (const int x, const int y)
{
    return x >= 0 && x < S_HIGH && y >= 0 && y < S_WIDTH;
}

bool inMapLimit (const std::pair<int, int> xy)
{
    int x = xy.first;
    int y = xy.second;
    return x >= 0 && x < S_HIGH && y >= 0 && y < S_WIDTH;
}

int** getMap(){
	return (int**) gmap;
}

int getMapWidth(){
	return S_WIDTH;
}

int getMapHight(){
	return S_HIGH;
}

void cleanDirt(const int x, const int y){
    if (inMapLimit(x,y) && gmap[x][y])
        gmap[x][y]=0;
    }

bool cleanDirt(const std::pair<int, int> xy){
    int x = xy.first;
    int y = xy.second;
    if (inMapLimit(x,y) && gmap[x][y]){
        gmap[x][y]=0;
        return true;
    } else return false;
}