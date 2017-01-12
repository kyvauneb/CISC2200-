/*
 * Kyvaune Brammer
 *
 */

#include <iostream>
#include "maze.h"

using namespace std;

Maze::Maze() {

	character = '0';

	for (int i = 0; i < ROWS; i++) {

		for (int j = 0; j < COLUMNS; j++) {

			maze[i][j] = character;
		}
	}
	writeBlockedPositions();
	writeExit();
}

void Maze::printMaze() {

	for (int i = 0; i < ROWS;i++) {
		cout << "+---+---+---+---+---+" << endl;

		for (int j=0; j < COLUMNS; j++) {
			cout << "| " << maze[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "+---+---+---+---+---+" << endl;
}

void Maze::writeBlockedPositions() {

	char blockedPosition = '+';

	// NOTE: Blocked positions are (1,4), (2,4), (3,4), (3,3), (3,1), (3,0), (1,1), (0,2)

	maze[1][4] = blockedPosition;

	maze[2][4] = blockedPosition;

	maze[3][4] = blockedPosition;

	maze[3][3] = blockedPosition;

	maze[3][1] = blockedPosition;

	maze[3][0] = blockedPosition;

	maze[1][1] = blockedPosition;

	maze[0][2] = blockedPosition;

}

void Maze::writeExit() {

	maze[0][3] = 'E';
}

void Maze::setCell(int r, int c, char m) {

	maze[r][c] = m;
}

char Maze::getCell(int r, int c) {

	char cell = maze[r][c];
	return cell;

}
bool Maze::backTrack(int r, int c) {

	if (getCell(r, c) == 'E') {
		return true;
	}
	else if (r < 0 || c < 0 || r >= ROWS || c >= COLUMNS) {
		cout << "Cell " << r << ", " << c << " doesn't exit this maze"  << endl;
		return false;
	}
	else if (getCell(r, c) == '+') {
		cout << "Blocked position: " << r << ", " << c << endl;
		return false;
	}
	else if (getCell( r, c ) == '$') {
		cout << "Position already visited:  " << r << ", " << c << endl;
		return false;
	}
	else {
		setCell(r, c, '$');

		if (backTrack( (r + 1), (c) ) == true) {
			return true;
		}
		else if ( backTrack( (r - 1), (c) ) == true) {
			return true;
		}
		else if ( backTrack( (r), (c + 1) ) == true) {
			return true;
		}
		else if ( backTrack( (r), (c - 1) ) == true) {
			return true;
		}
		else {
			return false;
		}
	}
}
