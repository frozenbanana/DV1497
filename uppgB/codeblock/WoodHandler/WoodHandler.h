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
			WoodHandler& operator=(const WoodHandler &orig);  // assignment operator
			WoodHandler(const WoodHandler &orig);             // cpy kontruktor
			WoodHandler(int capacity);                        // kontruktor med egen capacity
			WoodHandler();                                    // default konstruktor
			~WoodHandler();
			void setCapacity(int capacity);
			int getNrOfWood();
			int getNrOfPanels();
			int getNrOfJoists();
			string printAllWood() const;
            string decideDerived(Wood* unknown) const;
            bool searchPanel(int index, string dimensions, string profile);
            bool makePanelIsPrimed(int index, bool primed);
            bool decideIfPrimed(int index);
            string printAllPanel();
            string printAllJoist();
            void expand();
};
