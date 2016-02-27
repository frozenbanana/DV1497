#include "journey.h"

class JourneyHandler {
private:
	string owner;
	Journey** journeys;
	int capacity;
	int nr_of_journeys;
public:
	JourneyHandler();
	JourneyHandler(string owner);
	~JourneyHandler();
	void addJourney(int duration, int speed);
	int getNrOfJourneys() const;
	string getJourneyInfoAt(int index) const;
	string getLongestJourneyInfo() const;
	string getShortestJourneyInfo() const;
	//sortJourneys() const;
	//removeJourney(string name);
};
