#include <iostream>
#include "Virke.h"
class Regel: public Virke{
		private:
			string classification;
		public:
			Regel();
			Regel(string classification);
			~Regel();
			void setClassification(string classification);
			string getClassification();
			string toString();

}
