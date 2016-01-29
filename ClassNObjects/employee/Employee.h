/*
 *Gör en klass som beskriver anställd
 a. En anställd har egenskaperna 
 anställningsnummer, lön, anställnin
 gstid, personnummer samt namn. Det 
 ska vara möjligt att ändra egenskaper
 na namn, lön och antällningstid. Det 
 ska dessutom vara möjligt att erhå
 lla värden för alla egenskaper. 
 Slutligen ska det vara möjligt att (genom anrop av en medlemsfunktion) få 
 en utskrift av värdet på alla egen
 skaper. Gör ett testprogram som skapar 
 två objekt av klasstypen ovan oc
 h testar de medlemsfunktioner som 
 implementerats i klassen. 
 * */
#ifndef Friend_H_
#define Friend_H_
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;


Class Employee{
  public:
    Employee();
    Employe(string name, int employeeNr, int dateOfBirth, int salary, int employeeStart);
    ~Employee();

    string getName() const;
    int getEmployeeNr() const;
    int getdateOfBirth() const;
    int getSalary() const;
    int getEmployeeStart() const;
    int getEmployeeTime() const;


    void setName() const;
    void setEmployeeNr() const;
    void setdateOfBirth() const;
    void setSalary() const;
    void setEmployeeStart const;
    void setEmployeeTime() const;

    bool operator ==(const Employee & otherEmployee) const;
    bool operator <(const Employee & otherEmployee) const;

    string toString()const;
  private:
    string name;
    int employeNr;
    int dateOfBirth;
    int salary;
    int employeeStart;
    int employeeTime;
}

#endif
