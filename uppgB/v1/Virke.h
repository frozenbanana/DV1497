#include <iostream>

class Virke{
	private:
		string type;
		double meterPrice;
		int dimensions; // for numbers __x__
	public:
		Virke();
		~Virke();
		void setType(string type);
		void setMeterPrice(double meterPrice);
		void setDimensions(int dimensions);
		string getType();
		double getMeterPrice();
		int getDimensions();
		string toString();
		virtual string toStringSpecific(const=0);
};
