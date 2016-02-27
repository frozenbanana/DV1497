//Movie.cpp
#include "movie.h"
Movie::Movie()
{
	this->title="unkown";
	this->year=0;
}
Movie::Movie(string title, int year)
{
	this->title=title;
	this->year=year;
}
void Movie::setTitle(string title)
{
	this->title=title;
}
string Movie::getTitle() const
{
	return this->title;
}
void Movie::setYear(int year)
{
	this->year=year;
}
int Movie::getYear() const{
	return this->year;
}
