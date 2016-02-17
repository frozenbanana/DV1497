#include <iostream>
#include "Virke.h"
class Panel: public Virke{
		private:
			string profil;
			bool basePainted;
		public:
			Panel();
			Panel(string profile, bool basePainted);
			~Panel();
			void setProfile(string profile);
			string getProfile();
			void setBasePainted();
			bool getBasePainted();
			string toString();
};
