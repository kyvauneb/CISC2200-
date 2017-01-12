/*
 * Kyvaune Brammer
 *
 * MAZE DRIVER
 *
 */

#include <iostream>
#include "maze.h"

using namespace std;

int main() {

	int row, col;
	char start = 'M';
	bool validEntry;
	Maze Maze;

	Maze.printMaze();

	while (validEntry == false) {

		cout << "Enter the row from 0 to " << ROWS - 1 << ":(0 = Row1, 1= Row2, etc) ";
		cin >> row;

		cout << "Now enter the column from 0 to " << COLUMNS - 1 << ":(0 = Column1, 1 = Column2, etc) ";
		cin >> col;
	
		if (Maze.getCell(row, col) != '+') {
			Maze.setCell(row, col, start);
			validEntry = true;
			cout << endl << endl;
		}
		else {
			cout << "Not a valid position, try again." << endl << endl;
		}
	}

	if (Maze.backTrack(row, col) == true) {
		cout << "You found a way out!!!" << endl;
	}
	else {
		cout << "No exit found, please try again!" << endl;
	}
	Maze.printMaze();
}
