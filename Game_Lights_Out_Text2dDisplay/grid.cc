#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid() 
	:gridSize{ 0 }, td{ nullptr } {}


Grid::~Grid() { 
	delete this->td;
}


void Grid::clearGrid() {
	for (int i = 0; i < gridSize; i++) {
		theGrid.pop_back(); // Clear the vector<cell>
	}
	this->gridSize = 0;
	delete this->td;
	this->td = nullptr;
}


bool Grid::isWon() const {
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			bool isOn = theGrid[i][j].getState();
			if (isOn) {
				return false;
			}
		}
	}
  return true;
}


void Grid::init(int n) {
	this->clearGrid();
	this->gridSize = n;
	this->td = new TextDisplay{ n };
	for (int i = 0; i < n; i++) {
		vector<Cell> vc;
		for (int j = 0; j < n; j++) {
			vc.push_back(Cell());
			(vc.back()).setCoords(i, j);
			(vc.back()).attach(this->td);
		}
		theGrid.push_back(vc);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((0 <= (i - 1)) && ((i - 1) < gridSize)) {
				theGrid[i][j].attach(&theGrid[i - 1][j]);
			}
			if ((0 <= (i + 1)) && ((i + 1) < gridSize)) {
				theGrid[i][j].attach(&theGrid[i + 1][j]);
			}
			if ((0 <= (j - 1)) && ((j - 1) < gridSize)) {
				theGrid[i][j].attach(&theGrid[i][j - 1]);
			}
			if ((0 <= (j + 1)) && ((j + 1) < gridSize)) {
				theGrid[i][j].attach(&theGrid[i][j + 1]);
			}
		}
	}
}


void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}


void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
  theGrid[r][c].notifyObservers(SubscriptionType::SwitchOnly);
}


ostream &operator<<(ostream &out, const Grid &g) {
	out << *(g.td);
	return out;
}
