#include <iostream>
#include <sstream>
#include <string>
#include "track.h"

using namespace std;

Track::Track(){
    this->title = "UNKNOWN";
    this->artist = "UNKNOWN";
    this->genre = "UNKNOWN";
    this->filePath = "UNKNOWN";
    this->duration = 0;
}
Track::Track(string title, string artist, string genre, string filePath, int duration){
    this->title = title;
    this->artist = artist;
    this->genre = genre;
    this->filePath = filePath;
    this->duration = duration;
}
Track::~Track(){ };
void Track::setTitle(string title){
    this->title = title;
}
void Track::setArtist(string artist){
    this->artist = artist;
}
void Track::setGenre(string genre){
    this->genre = genre;
}
void Track::setfilePath(string filePath){
    this->filePath = filePath;
}

void Track::setDuration(int duration){
    this->duration = duration;
}
string Track::getTitle(){
    return this->title;
}
string Track::getArtist(){
    return this->artist;
}
string Track::getGenre(){
    return this->genre;
}
string Track::getFilePath(){
    return this->filePath;
}
int Track::getDuration(){
    return this->duration;
}
string Track::toString(){
    stringstream ss;
    ss << this->title << endl;
    ss << this->artist << endl;
    ss << this->genre << endl;
    ss << this->filePath << endl;
    ss << this->duration << endl;
    return ss.str();
}
