#include <iostream>
#include <utility>
#include "graphicsdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(int n, Xwindow & theWindow)
	: gridSize{ n }, xw{ theWindow } {
	int side = 500 / gridSize;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			xw.fillRectangle(j * side, i * side, side, side, Xwindow::Black);
		}
	}
}

void GraphicsDisplay::notify(Subject &whoNotified) {
	Info cellinfo{ whoNotified.getInfo() };
	int side = 500 / gridSize;
	if ((cellinfo.row < gridSize) && (cellinfo.col < gridSize)) {
		if (cellinfo.state) {
			xw.fillRectangle(cellinfo.col * side, cellinfo.row * side, side, side, Xwindow::White);
		}
		else {
			xw.fillRectangle(cellinfo.col * side, cellinfo.row * side, side, side, Xwindow::Black);
		}	
	}
}

GraphicsDisplay::~GraphicsDisplay() {}

SubscriptionType GraphicsDisplay::subType() const {
	return SubscriptionType::All;
}

