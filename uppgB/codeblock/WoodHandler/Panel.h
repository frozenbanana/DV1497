#pragma once
#include "Wood.h"

class Panel: public Wood{
	private:
			string profile;
			bool primed;
	public:
		Panel(const Panel &orig);
		Panel(string dimensions, int meterPrice, string profile, bool primed);
		Panel& operator=(const Panel &orig);
		~Panel();
		virtual string toStringSpecific() const;
		string toString();
		void setProfile(string profile);
		void setPrimed(bool primed);
		string getProfile();
		bool getPrimed();
        virtual Wood* clone()const;

};
