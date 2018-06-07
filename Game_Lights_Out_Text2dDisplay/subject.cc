#include "subject.h"
#include "observer.h"
#include "subscriptions.h"
using namespace std;

void Subject::attach(Observer *o) {
	this->observers.push_back(o);
}

void Subject::notifyObservers(SubscriptionType t) {
	for (vector<Observer *>::iterator it = observers.begin(); it != observers.end(); ++it) {
		if ((*it)->subType() == t) {
			(*it)->notify(*this);
		}
	}
}

Subject::~Subject() {}; ///// Leave it here temp


