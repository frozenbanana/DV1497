#pragma once
#include "Wood.h"
#include <iostream>
#include <string>


class Joist: public Wood{
	private:
		string type;
	public:
		Joist(string dimensions, int meterPrice, string type): Wood(dimensons, meterPrice);
		Joist(const Joist &orig): Wood(orig);
		Joist& operator =(const Joist &orig);
		virtual string toStringSpecific() const;
		void setType(string type);
		string getType();
		~Joist();
};
