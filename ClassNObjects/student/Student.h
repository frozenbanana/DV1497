#ifndef Student_H
#define Student_H
#include <iostream>
#include <string>
using namespace std;
class Student{

  private:
    string name;
    string program;
    int phoneNumber;
    int dateOfBirth;
  public:
    Student(string name = "unknown", string program = "unknown", int phoneNumber = 0, int birthday = 0);
    ~Student();
    void setName(string name);
    void setProgram(string program);
    void setPhoneNumber(int phoneNumber);
    void setDateOfBirth(int dateOfBirth);
    string getName()const;
    string getProgram()const;
    int getPhoneNumber()const;
    int getDateOfBirth()const;
    void show();
};
#endif
