#include "movieHandler.h"
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
int menu();
int main(void)
{
	MovieHandler movieHandler;
	int year;
	string title;
	int option=0;
	while(option != 4)
	{
		option=menu();
		switch(option)
		{
			case 1:
				cout << "Enter title: ";
				getline(cin, title);
				cout << "Enter year: ";
				cin >> year;
				if(movieHandler.addMovie(title, year))
					cout << "Successful!" << endl;
				else
					cout << "not successful :(" << endl;
				break;
			case 2:
				cout << "Enter title: ";
				getline(cin, title);
				if(movieHandler.removeMovie(title))
					cout << "Successful!" << endl;
				else
					cout << "not successful :(" << endl;
				break;
			case 3:
				movieHandler.showAllMovies();
				break;
		}
	}
	return 0;
}

int menu(){
  cout << "1. Add a movie" << "\n2.Remove a movie"
       << "\n3. Show all movies" << "\n4. Exit" << endl;
  int option = 0;
  cin >> option;
  return option;

}
