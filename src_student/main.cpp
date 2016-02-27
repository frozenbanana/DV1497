#include "journey_handler.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main() {
	
	srand(time(NULL));	

	JourneyHandler jh("Mars Simulation Software");
	int tmp_nr_of_journeys = 0;

	cout << "How many journeys:";
	cin >> tmp_nr_of_journeys;
	cin.ignore();

	for(int i = 0; i < tmp_nr_of_journeys; i++)
		jh.addJourney((rand() % 10) + 1, (rand() % 20) + 1);
	
	for(int i = 0; i < jh.getNrOfJourneys(); i++)
		cout << i << " :: " << jh.getJourneyInfoAt(i) << endl;
	cout << endl;

	cout << "Longest journey:" << endl;
	cout << jh.getLongestJourneyInfo() << endl;
	cout << endl;

	cout << "Shortest journey:" << endl;
	cout << jh.getShortestJourneyInfo() << endl;
	cout << endl;
	
	//getchar();
	return 0;
}
