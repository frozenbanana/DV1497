#include "Virke_Hanterare.hpp"
#include <algorithm>		// Used to simplify deep-copying of a stringarray in expand()

//--------------------------------------------------------------------
VirkeHanterare::VirkeHanterare()
{
	this->capacity = 5;
	this->material_count = 0;
	this->materials = new Virke*[this->capacity];

	this->stringArray = new string[this->capacity];		// Starting out with max capacity
														// and then alters and adapts capacity
	this->pStringArray = new string[this->capacity];	// directly after each expand() - this
	this->pStringCount = 0;								// approach requires the expand to trigger
	this->rStringArray = new string[this->capacity];	// on each increase, but since it's a low-level project
	this->rStringCount = 0;								// efficiency on that level is not neccessary.

	for (int i = 0; i < this->capacity; i++) {			// Filling them up with random text
		this->stringArray[i] = "No input yet";			// enables the expand() to copy the
		this->pStringArray[i] = "No input yet";			// first values in a defined 
		this->rStringArray[i] = "No input yet";			// behavior
	}


}
VirkeHanterare::VirkeHanterare(int capacity)
{
	this->capacity = capacity;
	this->material_count = 0;
	this->materials = new Virke*[this->capacity];

	this->stringArray = new string[this->capacity];		// Starting out with max capacity
														// and then alters and adapts capacity
	this->pStringArray = new string[this->capacity];	// directly after each expand() - this
	this->pStringCount = 0;								// approach requires the expand to trigger
	this->rStringArray = new string[this->capacity];	// on each increase, but since it's a low-level project
	this->rStringCount = 0;								// efficiency on that level is not neccessary.

	for (int i = 0; i < this->capacity; i++) {			// Filling them up with random text
		this->stringArray[i] = "No input yet";			// enables the expand() to copy the
		this->pStringArray[i] = "No input yet";			// first values in a defined 
		this->rStringArray[i] = "No input yet";			// behavior
	}

}
VirkeHanterare::~VirkeHanterare()
{
	this->freeMemory();
	delete[] this->stringArray;
	delete[] this->pStringArray;
	delete[] this->rStringArray;
}
//--------------------------------------------------------------------

/*********************************************************************/
void VirkeHanterare::setMaterialCount(int material_count)
{
	this->material_count = material_count;
}
int VirkeHanterare::getMaterialCount() const
{
	return this->material_count;
}

void VirkeHanterare::setCapacity(int capacity)
{
	this->capacity = capacity;
}
int VirkeHanterare::getCapacity() const
{
	return this->capacity;
}

void VirkeHanterare::add(string dimension, int price_per_meter, string classification)
{
	if (this->material_count == capacity) {
		this->expand();
	}
	this->materials[this->material_count] = new Regel(dimension, price_per_meter, classification);
	this->material_count++;
}
void VirkeHanterare::add(string dimension, int price_per_meter, string profile, bool primed)
{
	if (this->material_count == capacity) {
		
		this->expand();
	}
	this->materials[this->material_count] = new Panel(dimension, price_per_meter, profile, primed);
	this->material_count++;
}

void VirkeHanterare::setStringArray()
{
	for (int i = 0; i < this->material_count; i++) {
		this->stringArray[i] = this->materials[i]->toString();
	}
}
void VirkeHanterare::setPStringArray()
{
	this->pStringCount = detectPanels();
	int current_index = 0;

	for (int i = 0; i < this->material_count; i++) {
		if (this->detectMaterial(this->materials[i]) == "Panel") {
			this->pStringArray[current_index] = this->materials[i]->toString();
			current_index++;
		}
	}
}
void VirkeHanterare::setRStringArray()
{
	this->rStringCount = detectRegels();
	int current_index = 0;
	for (int i = 0; i < this->material_count; i++) {
		if (this->detectMaterial(this->materials[i]) == "Regel") {
			this->rStringArray[current_index] = this->materials[i]->toString();
			current_index++;
		}
	}
}
string VirkeHanterare::getStringArrayPrint() const
{
	stringstream output;
	for (int i = 0; i < this->material_count; i++) {
		output << this->stringArray[i] << endl;
	}
	return output.str();
}
string VirkeHanterare::getPStringArrayPrint() const
{
	stringstream output;
	for (int i = 0; i < this->pStringCount; i++) {
		output << this->pStringArray[i] << endl;
	}
	return output.str();
}
string VirkeHanterare::getRStringArrayPrint() const
{
	stringstream output;
	for (int i = 0; i < this->rStringCount; i++) {
		output << this->rStringArray[i] << endl;
	}
	return output.str();
}

/*********************************************************************/
void VirkeHanterare::freeMemory()
{
	for (int i = 0; i < this->material_count; i++) {
		delete this->materials[i];
	}
	delete[] this->materials;

}
void VirkeHanterare::expand()
{
	// Create and allocate bigger array
	this->capacity += 1;									// Reason for +1 is in the constructor
	Virke** new_array = new Virke*[this->capacity];
	
	// Copy to bigger array (Deep copying)
	for (int i = 0; i < this->material_count; i++) {
			new_array[i] = this->materials[i]->clone();
		}

	// Delete old array
	this->freeMemory();

	// Repoint to new array
	this->materials = new_array;

	//--------------- And also with our stringArrays ---------------//
	// Create and allocate bigger arrays
	this->pStringCount = detectPanels();	// These won't detect the first time a p/r is added,
	this->rStringCount = detectRegels();	// But since set is always used after the first time, and set detects again, it doesn't matter.

	string* temp_arrayAll = new string[this->material_count+1];	// +1 because I earlier chose
	string* temp_arrayP = new string[this->pStringCount+1];		// to increase material_count
	string* temp_arrayR = new string[this->rStringCount+1];		// after expand()

	// Copy to the bigger arrays
	for (int i = 0; i < this->material_count; i++) {
		temp_arrayAll[i] = this->stringArray[i];
	}
	if (pStringCount == 0) {								// Guarantees that the value that is
		temp_arrayP[0] = this->pStringArray[0];				// copied is never "error reading..."
	}														// which crashes the program
	for (int i = 0; i < this->pStringCount; i++) {
		temp_arrayP[i] = this->pStringArray[i];	
	}
	if (rStringCount == 0) {								// Guarantees that the value that is
		temp_arrayR[0] = this->rStringArray[0];				// copied is never "error reading..."
	}														// which crashes the program
	for (int i = 0; i < this->rStringCount; i++) {
		temp_arrayR[i] = this->rStringArray[i];			}

	// Delete old arrays
	delete[] this->stringArray;
	delete[] this->pStringArray;
	delete[] this->rStringArray;

	// And finally repoint the new arrays to our variables
	this->stringArray = temp_arrayAll;	
	this->pStringArray = temp_arrayP;
	this->rStringArray = temp_arrayR;
}
string VirkeHanterare::detectMaterial(Virke* &other) const
{
	string detected_material = "Material not in the system.";

	// Create temporary material pointers
	Regel* temp_regel = nullptr;
	Panel* temp_panel = nullptr;

	temp_regel = dynamic_cast<Regel *>(other);
	temp_panel = dynamic_cast<Panel *>(other);
	if (temp_regel != nullptr) {
		detected_material = "Regel";
	}
	else if (temp_panel != nullptr) {
		detected_material = "Panel";
	}
	
	return detected_material;
}
int VirkeHanterare::detectPanels() const
{
	int detected_panels = 0;

	for (int i = 0; i < this->material_count; i++) {
		if (this->detectMaterial(this->materials[i]) == "Panel") {
			detected_panels++;
		}
	}

	return detected_panels;
}
int VirkeHanterare::detectRegels() const
{
	int detected_regels = 0;

	for (int i = 0; i < this->material_count; i++) {
		if (this->detectMaterial(this->materials[i]) == "Regel") {
			detected_regels++;
		}
	}

	return detected_regels;
}


int VirkeHanterare::linearSearch(string dimension, int price) const
{
	int* possible_indexes = new int[this->material_count];
	int true_index = -1;
	int current_array_spot = 0;

	for (int i = 0; i < this->material_count; i++) {
		possible_indexes[i] = -1;
	}

	for (int i = 0; i < this->material_count; i++) {
		if (this->materials[i]->getDimension() == dimension) {
			possible_indexes[current_array_spot] = i;
			current_array_spot++;
		}
	}
	for (int i = 0; i < this->material_count; i++) {	
		if (possible_indexes[i] == i) {
			if (this->materials[i]->getPricePerMeter() == price) {
				true_index = i;
				break;
			}
		}

	}

	delete[] possible_indexes;
	return true_index;
}







VirkeHanterare& VirkeHanterare::operator = (const VirkeHanterare &other)
{
	// Delete "this" if not already empty


	// Copy material_count and capacity


	// Reallocate "this" to the new size


	// Loop - create


	/*
	CellPhoneHandler& operator = (const CellPhoneHandler &other);
	CellPhoneHandler& CellPhoneHandler::operator = (const CellPhoneHandler &other) {
	for (int i = 0; i < this->cellphone_count; i++) {
	delete this->cellPhones[i];
	}
	delete[] this->cellPhones;

	this->capacity = other.capacity;
	this->cellphone_count = other.cellphone_count;

	this->cellPhones = new CellPhone*[this->capacity];

	for (int i = 0; i < this->cellphone_count; i++) {
	this->cellPhones[i] = new CellPhone(*other.cellPhones[i]);
	}

	return *this;
	}

	*/

	return *this;
}

