#include <iostream>
#include <string>
#include "grid.h"
using namespace std;

int main() {
	cin.exceptions(ios::eofbit | ios::failbit | ios::badbit);
	string cmd;
	Grid g;
	int moves = 0;
	bool moveset = false;
	int gamesize = 0;


	try {
		while (true) {
			cin >> cmd;
			if (cmd == "new") {
				int n;
				cin >> n;
				gamesize = n;
				g.init(n); // Initialize Grid g to let it be an n x n Grid
			}
			else if (cmd == "init") {
				int r = 0;
				int c = 0;
				while (true) {
					cin >> r;
					cin >> c;
					if ((r == -1) || (c == -1)) break;
					g.turnOn(r, c);
				}
				cout << g;
			}
			else if (cmd == "game") {
				moveset = true;
				cin >> moves;
				cout << moves << " move";
					if (moves == 1) {
						cout << " left" << endl;
					}
					else {
						cout << "s left" << endl;
					}	
			}
			else if (cmd == "switch") {
				int r = 0, c = 0;
				cin >> r >> c;
				if ((0 <= r) && (r < gamesize) && (0 <= c) && (c < gamesize)) {
					g.toggle(r, c);
				}
				moves--;
				cout << g;
				cout << moves << " move";
				if (moves == 1) {
					cout << " left" << endl;
				}
				else {
					cout << "s left" << endl;
				}
			}
			if ((moves == 0) && moveset) {
				if (g.isWon()) {
					cout << "Won" << endl;
				}
				else {
					cout << "Lost" << endl;
				}
				break;
			}
			if ((moves != 0) && (g.isWon())) {
				cout << "Won" << endl;
				break;
			}
		}
	}
	catch (ios::failure &) {
	}
}
