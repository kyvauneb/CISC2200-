/*
 * Kyvaune Brammer
 *
 * CISC2200 - Papadakis
 *
 * Maze Extra Credit
 *
 */


#ifndef MAZE_H
#define MAZE_H

#include <iostream>
using namespace std;

static const int ROWS = 4;
static const int COLUMNS = 5;

class Maze {
 
  public:
	  Maze();

	  void printMaze();
	  
	  void writeBlockedPositions();
	  void writeExit();

	  char getCell(int r, int c);
	  void setCell(int r, int c, char m);
	  bool backTrack(int r, int c);

  private:
	  char maze[ROWS] [COLUMNS];
	  char character;
};

#endif
