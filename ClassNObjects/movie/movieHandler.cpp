#include "movieHandler.h"
using namespace std;
MovieHandler::MovieHandler()
{
	this->nrOfMovies = 0;
}
MovieHandler::~MovieHandler()
{
 for(int i = 0; i < nrOfMovies; i++){
   delete this->movies[i];
 }
 delete this->movies;
}
bool MovieHandler::addMovie(string title, int year){
	bool flag=false;
	//23 is SIZE. You can use try catch
	if(this->nrOfMovies < 23)
	{
		this->movies[nrOfMovies]=Movie(title,year);
		this->nrOfMovies++;
		flag=true;
	}
	return flag;
}

void MovieHandler::showAllMovies() const
{
	for(int i=0; i < this->nrOfMovies; i++)
	{
    cout << "Title" << this->movies[i].getTitle() << "year: " << this->movies[i].getYear() << endl;
	}
}
bool MovieHandler::removeMovie(string title)
{
	//kolla om film finns. ta film längstbak och flytta ner
	bool flag = false;
	for(int i=0; i < this->nrOfMovies; i++)
	{
		if(this->movies[i].getTitle()==title)
		{
			this->movies[i].setTitle(this->movies[this->nrOfMovies-1].getTitle());
			this->movies[i].setYear(this->movies[this->nrOfMovies-1].getYear());
			//decres number of movies
			this->nrOfMovies--;
			flag=true;
		}
	}
	return flag;
}



