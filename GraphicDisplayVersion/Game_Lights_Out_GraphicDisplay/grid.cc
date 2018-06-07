#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid()
	:gridSize{ 0 }, td{ nullptr }, gd{ nullptr } {}


Grid::~Grid() {
	delete this->td;
	delete this->gd;
}


void Grid::clearGrid() {
	for (int i = 0; i < gridSize; i++) {
		theGrid.pop_back(); // Clear the vector<cell>
	}
	this->gridSize = 0;
	delete this->td;
	delete this->gd;
	this->td = nullptr;
	this->gd = nullptr;
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


void Grid::init(int n, Xwindow &xw) {
	this->clearGrid();
	this->gridSize = n;
	this->td = new TextDisplay{ n };
	this->gd = new GraphicsDisplay{ n, xw };
	for (int i = 0; i < n; i++) {
		vector<Cell> vc;
		for (int j = 0; j < n; j++) {
			vc.push_back(Cell());
			(vc.back()).setCoords(i, j);
			(vc.back()).attach(this->td);
			(vc.back()).attach(this->gd);
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
