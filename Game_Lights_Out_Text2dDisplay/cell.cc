#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"
using namespace std;

Cell::Cell()  // Default constructor
	:isOn{ false }, r{ 0 }, c{ 0 }{}


bool Cell::getState() const {
	return isOn;
}


void Cell::setOn() {
	this->isOn = true;
	notifyObservers(SubscriptionType::All); // Notify testdisplay to change
}


void Cell::toggle() {
	if (this->isOn) {
		this->isOn = false;
	}
	else {
		this->isOn = true;
	}
	notifyObservers(SubscriptionType::All); // Notify testdisplay to change
}


void Cell::setCoords(int r, int c) {
	this->r = r; this->c = c;
}


SubscriptionType Cell::subType() const {
	return SubscriptionType::SwitchOnly;
}


void Cell::notify(Subject &whoNotified) {
	toggle();  ///// Not sure whoNotified use
}


Info Cell::getInfo() const {
	Info cellInfo{ this->r, this->c, this->isOn };
	return cellInfo;
}