#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n)
	:gridSize{ n } {
	for (int i = 0; i < n; i++) { // Make a n * n vector
		vector<char> vc;
		for (int j = 0; j < n; j++) {
			vc.push_back('_');
		}
		theDisplay.push_back(vc);
	}
}

void TextDisplay::notify(Subject &whoNotified) {
	Info cellinfo{ whoNotified.getInfo() };
	if ((cellinfo.row < gridSize) && (cellinfo.col < gridSize)) {
		(theDisplay.at(cellinfo.row)).at(cellinfo.col) = cellinfo.state ? 'X' : '_';
	}
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() const {
	return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (int i = 0; i < td.gridSize; i++) {
		for (int j = 0; j < td.gridSize; j++) {
			out << (td.theDisplay.at(i)).at(j);
		}
		out << endl;
	}
	return out;
}
