#include "University_reg.h"


UniversityReg::UniversityReg() {
	this->capacity = 0;
	this->nr_of_persons = 0;
	this->persons = new Person*[this->capacity];

	for (int i = 0; i < this->capacity; i++) {
		this->persons[i] = nullptr;
	}
}
UniversityReg::UniversityReg(int capacity) {
	this->capacity = capacity;
	this->nr_of_persons = 0;
	this->persons = new Person*[this->capacity];

	for (int i = 0; i < capacity; i++) {
		this->persons[i] = nullptr;
	}
}
UniversityReg::UniversityReg(const UniversityReg &original) {
	// Early exits
	if (this == &original)
		return;

	// Avallokering av gamla this.
	this->freeMemory();

	// Kopiering
	this->capacity = original.capacity;						// Kopierar statiska värden
	this->nr_of_persons = original.nr_of_persons;			//
	this->persons = new Person*[original.nr_of_persons];	// Skapar en pointerarray av samma storlek

	for (int i = 0; i < original.nr_of_persons; i++) {
		Employee* a_employee = nullptr;
		Student* a_student = nullptr;

		for (int i = 0; i < this->nr_of_persons; i++) {
			/*
			a_employee = dynamic_cast<Employee *>(this->persons[i]);
			if (a_employee != nullptr) {
				this->persons[i] = new Employee(*a_employee);
			}

			a_student = dynamic_cast<Student *>(this->persons[i]);
			if (a_student != nullptr) {
				this->persons[i] = dynamic_cast<Student *>(a_student);
			}
			*/
			this->persons[i] = original.persons[i]->clone();

		}
	}

}
void UniversityReg::freeMemory() {
	for (int i = 0; i < this->nr_of_persons; i++) {
		delete this->persons[i];
	}
	// Vi har minnesläckor här helt enkelt.
	delete[]this->persons;
}
UniversityReg::~UniversityReg() {
	this->freeMemory();
}

void UniversityReg::add(string name, string mail, int reg_nr) {
	if (this->nr_of_persons = this->capacity) {
		this->expand();
	}
	this->persons[this->nr_of_persons] = new Student(name, mail, reg_nr);
	this->nr_of_persons++;


}
void UniversityReg::add(string name, string mail, string department, int salary) {
	if (this->nr_of_persons = this->capacity) {
		this->expand();
	}
	this->persons[this->nr_of_persons] = new Employee(name, mail, department, salary);
	this->nr_of_persons++;

}

int UniversityReg::getNumberOfStudents() const {
	int students = 0;	// Antal hittade studenter

	Student* a_student = nullptr; // Skapar en 
	for (int i = 0; i < this->nr_of_persons; i++) {
		a_student = dynamic_cast<Student *>(this->persons[i]);

		if (a_student != nullptr) {
			students++;
		}
	}
	
	return students;
}
int UniversityReg::getNumberOfEmployees() const {
	int employees = 0;	// Antal hittade studenter

	Employee* a_employee = nullptr; // Skapar en temporär Employee pekare
	for (int i = 0; i < this->nr_of_persons; i++) {
		a_employee = dynamic_cast<Employee *>(this->persons[i]);// Vi tar infon i persons[i] och
																// gör om denna infon till typen
		if (a_employee != nullptr) {							// Employee och försöker sedan sätta in den i 
			employees++;										// a_employee - Detta går endast om infon är kompitabel
		}														// med klassen employee - och funkar därför inte om det är en student pekare som persons[i] har.
	}
	
	return employees;
}

void UniversityReg::expand() {
	Person** temp_array = new Person*[this->capacity];	// Skapa temporär array
	this->capacity += 5;								// Öka capacity

	for (int i = 0; i < this->nr_of_persons; i++) {		// Kopiera tidigare objekt till ny array
		temp_array[i] = this->persons[i];				//
	}													//

	for (int i = 0; i < this->nr_of_persons; i++) {		// Avallokera objekt i tidigare array
		delete this->persons[i];						//
	}													
	delete[] this->persons;								// Avallokera tidigare array
	this->persons = temp_array;							// Peka om tidigare array till ny array
}