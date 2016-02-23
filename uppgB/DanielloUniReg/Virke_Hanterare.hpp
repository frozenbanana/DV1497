#ifndef VIRKE_HANTERARE_HPP
#define VIRKE_HANTERARE_HPP
// Nödvändiga includes
#include "Regel.h"
#include "Panel.h"
#include <string>

class VirkeHanterare {
private:
	Virke** materials;
	int material_count;
	int capacity;

	string* stringArray;	// Doesn't need it's own count - it uses material_count
	string* pStringArray;
	string* rStringArray;
	int rStringCount;
	int pStringCount;

	void expand();											// TESTED
	void freeMemory();										// Tested
	string detectMaterial(Virke* &other) const;				// Tested
	int detectPanels() const;								// Tested - also zvenglizh
	int detectRegels() const;								// Testad - also svenglizh
	
	
public:
	// Should be in private  - TESTING AREA
	int linearSearch(string dimension, int price) const;

	// Should be in private  - TESTING AREA

	VirkeHanterare();										// Testad
	VirkeHanterare(int capacity);							// Testad
	~VirkeHanterare();										// Testad

	void setMaterialCount(int material_count);				// Testad
	int getMaterialCount() const;							// Testad
	void setCapacity(int capacity);							// Testad
	int getCapacity() const;								// Testad

	VirkeHanterare& operator = (const VirkeHanterare &other); // Waiting for priority

	//--------MENU FUNCTIONS-------------------------
	void add(string dimension, int price_per_meter, string classification);			// Tested
	void add(string dimension, int price_per_meter, string profile, bool primed);	// Tested
	void setStringArray();									// Tested
	void setPStringArray();									// Tested
	void setRStringArray();									// Tested
	string getStringArrayPrint() const;						// Tested
	string getPStringArrayPrint() const;					// Tested
	string getRStringArrayPrint() const;					// Tested


	//--------MENU FUNCTIONS-------------------------


};

#endif