#include "tracklist.h"

Tracklist::Tracklist(){
    this->title = "Nameless";
    this->totDuration = 0;
    this->filePath = "NONE";
    this->nrOfTracks = 0;
    this->capacity = 10;
    this->tracks = new Track[this->capacity];
}

Tracklist::Tracklist(string title, string filePath, int capacity){
    this->title = title;
    this->filePath = filePath;
    this->capacity = capacity;
    this->tracks = new Track[this->capacity];
}
Tracklist::~Tracklist(){
       delete [] this->tracks;
}
Tracklist::Tracklist(const Tracklist &orig){
                this->capacity = orig.capacity;
                this->nrOfTracks = orig.nrOfTracks;
                this->tracks = new Track[orig.capacity];
                this->totDuration = orig.totDuration;
                for(int i = 0; i < this->nrOfTracks;i++){
                                this->tracks[i] = orig.tracks[i];
                }
}
Tracklist& Tracklist::operator=(const Tracklist &orig){
                if(this != &orig){
                    delete [] this->tracks;
                    this->capacity = orig.capacity;
                    this->nrOfTracks = orig.nrOfTracks;
                    this->totDuration = orig.totDuration;
                    this->tracks = new Track[this-capacity];
                    for(int i = 0; i < this->nrOfTracks; i++){
                        this->tracks[i] = orig.tracks[i];
                    }
                }
        return *this;
}


void Tracklist::setTitle(string title){
    this->title = title;
}
void Tracklist::setfilePath(string filePath){
    this->filePath = filePath;
}
void Tracklist::setNrOfTracks(int nrOfTracks){
    this->nrOfTracks = nrOfTracks;
}

void Tracklist::setCapacity(int capacity){
    this->capacity = capacity;
}

string Tracklist::getTitle(){
    return this->title;
}

string Tracklist::getFilePath(){
    return this->filePath;
}

int Tracklist::getNrOfTracks(){
    return this->nrOfTracks;
}

int Tracklist::getCapacity(){
    return this->capacity;
}
void Tracklist::setTotDuration(){
    int totDuration = 0;
    for(int i = 0; i < this->nrOfTracks;i++){
        totDuration += tracks[i].getDuration();
    }
}
int Tracklist::getTotDuration(){
    return this->totDuration;
}

bool Tracklist::addTrack(Track aTrack, int index){
    bool flag = true;
    if(index > this->nrOfTracks){                               // check if index index in within range
         throw "not allowed position!";
         flag = false;
    }
        if(this->nrOfTracks == this->capacity){                 // if array is full
                this->expand();
        }
        this->tracks[this->nrOfTracks++] = this->tracks[index]; // moves the occupied index to the last place
        this->tracks[index] = aTrack;                           // and then put the item on index

        return flag;
}

bool Tracklist::removeTrack(Track aTrack){
    bool flag = false;
    for(int i = 0; i < this->nrOfTracks; i++){                                      // loop through all tracks in playlist
        if(tracks[i].getTitle() == aTrack.getTitle() && tracks[i].getArtist() == aTrack.getArtist()){   //if track is matched with track in playlist
            this->tracks[i] = tracks[this->nrOfTracks--];                           // replace the last track in playlist with the track that is going to be removed
            flag = true;
        }
    }
    return flag;
}

bool Tracklist::saveTracklist(){
    bool flag = false;
    ofstream savingFile(this->title.c_str());
      if(savingFile.is_open()){                                 // opens a new txt file with the title of playlist
        savingFile << toStringTracklist();                      // sends all information about the tracks of playlist to txt file
        savingFile.close();                                       // cloeses file
        flag = true;
    }
    return flag;
}

bool Tracklist::readTracklist(string filePath){
    bool flag = false;
    int totDuration;
    string title, nrOfTracks, capacity;                                  // string variables for member objects
    string trackTitle, trackArtist, trackGenre, trackDuration, trackFilePath;         // string variables for Track constructor

    ifstream readingFile(filePath);
    if(readingFile.is_open()){
      getline(readingFile, title);                              // getting first 4 lines in file to determine members of object
      getline(readingFile, totDuration);
      getline(readingFile, nrOfTracks);
      getline(readingFile, capacity);
      this->title = title;
      this->totDuration = totDuration;                          // this is unnecessary
      this->nrOfTracks = nrOfTracks;
      this->capacity = capacity;
      this->tracks = new Track[this->capacity];
      for(int i = 0; i < this->nrOfTracks;i++){
          getline(readingFile, title);                         //skipping index
          getline(readingFile, trackTitle);                         //read data about every track to variables
          getline(readingFile, trackArtist);
          getline(readingFile, trackGenre);
          getline(readingFile, trackFilePath);
          getline(readingFile, trackDuration);
          tracks[i] = Track(trackTitle,trackArtist,trackGenre,trackFilePath,intDuration);   // creates track objects accordingly
      }
      readingFile.close();
    }
    return flag;
}

string Tracklist::toStringTracklist(){
    stringstream ss;
    ss << this->title << endl;
    ss << this->totDuration << endl;
    ss << this->nrOfTracks << endl;
    ss << this->capacity << endl;
    for(int i = 0; i < this->nrOfTacks;i++){
        ss << i << endl;                                                // inserting index to get a better view in file
        ss << tracks[i].toString();
    }
    return ss.str();
}
void Tracklist::expand(){
    Track temp = new Track[this->capacity+=this->capacity/2];
    for(int i = 0; i < this->nrOfTracks; i++){
        temp[i] = this->tracks[i];
    }
    delete [] this->tracks;
    this->tracks = temp;
}
