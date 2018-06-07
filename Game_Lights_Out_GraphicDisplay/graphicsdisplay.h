#ifndef __GRAPHICDISPLAY_H__
#define __GRAPHICDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
#include "window.h"
class Cell;

class GraphicsDisplay : public Observer {
	const int gridSize;
	Xwindow & xw;
public:
	GraphicsDisplay(int n, Xwindow & theWindow);

	void notify(Subject &whoNotified) override;
	SubscriptionType subType() const override;

	~GraphicsDisplay();

};

#endif

