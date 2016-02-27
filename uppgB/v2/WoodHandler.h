#pragma once
#include "Wood.h"

class WoodHandler{
		private:
			int nrOfWood;
			Wood **woods;
			int capacity;
		public:
			bool addPanel(string dimensons, int meterPrice, string profile, bool primed);
			bool addJoist(string dimensons, int meterPrice, string type);
			bool removePanel(string dimensons, int meterPrice);
			bool removeJoist(string dimensons, int meterPrice);
			WoodHandler& operator=(const WoodHandler &orig);  // vad är skillnaden
			WoodHandler(const WoodHandler &orig);  // vad är skillnaden 
			WoodHandler(int capacity);
			WoodHandler();
			~WoodHandler();
			void setCapacity();
			int getNrOfWood();
			int getNrOfPanels();
			int getNrOfJoists();
			void printAllWood() const;

};
