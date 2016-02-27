#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Wood{
		private:
			string dimensions;
			int meterPrice;
		public:
			Wood(const Wood &orig);
			Wood& operator = (const Wood& orig);
			Wood();
			Wood(string dimensions, int meterPrice);
			virtual ~Wood();
			virtual string toStringSpecific()const =0; // förklara varför detta behövs
			string getDimensons();
			int getMeterPrice();
			string toString();
			void setDimensons(string dimensons);
			void setMeterPrice(int meterPrice);

};
