#ifndef TRACKLIST_H
#define TRACKLIST_H
#include "track.h"
#include <fstream>

class Tracklist: public Track
{
    private:
        string title;
        Track* tracks;
        int totDuration;
        int nrOfTracks;
        int capacity;
        string filePath;
    public:
        Tracklist();
        Tracklist(string title, string filePath, int capacity);
        ~Tracklist();
        Tracklist(const Tracklist &orig);
        Tracklist& operator=(const Tracklist &orig);
        void setTitle(string title);
        void setTotDuration();
        void setNrOfTracks(int nrOfTracks);
        void setCapacity(int capacity);
        void setfilePath(string filePath);
        string getTitle();
        string getFilePath();
        int getTotDuration();
        int getNrOfTracks();
        int getCapacity();

        bool addTrack(Track aTrack, int index);
        bool removeTrack(Track aTrack);
        bool saveTracklist();
        bool readTracklist(string filePath);
        string toStringTracklist();
        void expand();
};

#endif // TRACKLIST_H
