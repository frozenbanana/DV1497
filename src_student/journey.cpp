#include "journey.h"
#include <sstream>

Journey::Journey() {
	this->duration = 0;
	this->speed = 0;
}

Journey::Journey(int duration, int speed) {
	// fix
	this->duration = duration;
	this->speed = speed;
}

Journey::~Journey() {
}

void Journey::setDuration(int duration) {
  this->duration = duration;
}

void Journey::setSpeed(int speed) {
  this->speed = speed;
}

int Journey::getDuration() const {
	return this->duration;
}

int Journey::getSpeed() const {
	return this->speed;
}

int Journey::getDistance() const {
	return this->speed*this->duration;
}
string Journey::to_string(int data) const{
  stringstream ss;
  ss << data;
  return ss.str();
}
string Journey::getInfo() const {
  stringstream res;
	res << "Journey info: ";
	res << "Duration: ";
	res << to_string(this->duration);
	res << " seconds, ";
	res << "Speed: ";
	res << to_string(this->speed);
	res << " m/s, ";
	res << "Distance: ";
	res << to_string(this->getDistance());
	res << " m.";
	return res.str();
}
