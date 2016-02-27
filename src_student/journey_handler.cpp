#include "journey_handler.h"
#include <limits>

JourneyHandler::JourneyHandler() {
	this->owner = "unknown";
	this->capacity = 5;
	this->nr_of_journeys = 0;
	this->journeys = new Journey*[this->capacity];

	for(int i = 0; i < this->capacity; i++)
		this->journeys[i] = NULL;
}

JourneyHandler::JourneyHandler(string owner) {
    this->owner = owner;
    this->capacity = 5;
    this->nr_of_journeys = 0;
    this->journeys = new Journey*[this->capacity];
}

JourneyHandler::~JourneyHandler() {
	for (int i = 0; i < capacity; i++) {
	  delete this->journeys[i];
	}
  delete [] journeys;
}

void JourneyHandler::addJourney(int duration, int speed) {
	// expand pointer array if necessary
	if(this->capacity == this->nr_of_journeys) {
		//insert code for expansion
    this->journeys = new Journey*[this-++capacity];
    nr_of_journeys++;
	}
  else
    this->journeys = journeys[nr_of_journeys++];

	// add the journey
}

int JourneyHandler::getNrOfJourneys() const {
	return nr_of_journeys;
}

string JourneyHandler::getLongestJourneyInfo() const {
	// find the longest (distance) journey and return its getInfo().
}

string JourneyHandler::getShortestJourneyInfo() const {
	// find the shortest (distance) journey and return its getInfo().
}

string JourneyHandler::getJourneyInfoAt(int index) const {
	return this->journeys[index]->getInfo();
}
