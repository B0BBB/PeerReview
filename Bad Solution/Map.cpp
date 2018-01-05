/*
 * map module role is to hold the map structure and functionality
 * Note: x represent row and y column
 */

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
    gmap[x][y]=1;
}

//####################################################################################################

bool clean(const int x, const int y)
{
	if (inMapLimit(x,y)){
		gmap[x][y]=0;
		return true;
	}
	else return false;
}

//####################################################################################################

bool isDirty(const int x, const int y)
{
	bool is_dirty = false;
	if (inMapLimit(x,y))
		if (gmap[x][y]==1)
			is_dirty = true;
	return is_dirty;
}

//####################################################################################################

bool inMapLimit (const int x, const int y)
{
	if (x>=0 && x<S_HIGH && y>=0 && y<S_WIDTH)
		return true;
	else
		return false;
}

//####################################################################################################

bool isDirValid (const string& dir, const int x, const int y)
{
	bool DirValid = true;
	if (dir=="U")
		DirValid = inMapLimit(x-1,y);
	else if (dir=="L")
		DirValid = inMapLimit(x,y-1);
	else if (dir=="D")
		DirValid = inMapLimit(x+1,y);
	else if (dir=="R")
		DirValid = inMapLimit(x,y+1);
	else if(dir=="UR")
		DirValid = inMapLimit(x-1,y+1);
	else if(dir=="UL")
		DirValid = inMapLimit(x-1,y-1);
	else if(dir=="DR")
		DirValid = inMapLimit(x+1,y+1);
	else if(dir=="DL")
		DirValid = inMapLimit(x+1,y-1);
	return DirValid;
 }

//####################################################################################################

void PrintMap()
{
	std::cout << "  ";
	for (int i = 0; i < S_WIDTH; ++i)
		std::cout << i << " ";
	std::cout << std::endl;
	for (int i = 0; i < S_HIGH; ++i)
	{
		std::cout << i << " ";
	    for (int j = 0; j < S_WIDTH; ++j)
	    {
	        std::cout << gmap[i][j] << " ";
	    }
	    std::cout << std::endl;
	}
}
