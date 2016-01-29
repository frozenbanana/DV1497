#ifndef MOVIE_H
#define MOVIE_H
#include <string>
using namespace std;
class Movie
{
private:
	string title;
	int year;
public:
	Movie();
	~Movie(){}
	void setTitle(string title);
	string getTitle() const;
	void setYear(int year);
	int getYear() const;
	Movie(string title, int year);
};

#endif
