#ifndef TRACK_H
#define TRACK_H
#include <sstream>
#include <string>
using namespace std;
class Track{
    private:
        string title;
        string artist;
        string genre;
        //Emotion trackEmotion
        string filePath;
        int duration;
    public:
        Track();
        Track(string title, string artist, string genre, string filePath, int duration); // dont forget emotion later on
        ~Track();
        void setTitle(string title);
        void setArtist(string artist);
        void setGenre(string genre);
        void setfilePath(string filePath);
        void setDuration(int duration);
        string getTitle();
        string getArtist();
        string getGenre();
        string getFilePath();
        string toString();
        int getDuration();
};


#endif // TRACK_H
