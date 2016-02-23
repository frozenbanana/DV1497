#pragma once
#include "Wood.h"
#include <iostream>
#include <string>

class Joist: public Wood{
	private:
		string type;
	public:
		Joist(string dimensions, int meterPrice, string type); // konstuktor med egna parametrar
		Joist(const Joist &orig);                              // cpy konst
		Joist& operator =(const Joist &orig);                  // assignment overlod
		virtual string toStringSpecific() const;                // skickar ut unik objectsinformation
		void setType(string type);                              // set
		string getType()const;                                  // get
		~Joist();                                               // destruktor
		virtual Wood* clone()const;                             // skickar Woodpekare av typ Joist till cpy konst
};
