//MovieHandler
#include "movie.h"
#ifndef movieHandler_h
#define movieHandler_h
class MovieHandler
{
private:
	int nrOfMovies;
	Movie movies[23];
  Movie movies2 = new Movie[23];
  Movie *movies3[23];
  Movie **movies4 = new Movie*[23];
public:
	MovieHandler();
	~MovieHandler();
	bool addMovie(string title, int year);
	void showAllMovies() const;
	bool removeMovie(string title);
};
#endif
