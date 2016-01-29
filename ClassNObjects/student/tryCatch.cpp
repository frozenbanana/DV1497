#include "Student.h"

using namespace std;

int main (void){
Student st;
int dateOfBirth = 0;
cout << "please enter dateOfBirth: " << endl;
cin >> dateOfbirth;
int dayAndMonth = 0;
int day;
int month;
dayAndMonth = dateOfBirth % 10000;
day = dayAndMonth % 100;
month = dayAndMonth / 100;
if (day > 31 || day <1){
  throw 1;
 }
else if(month > 12 || month < 1){
  throw 2;
}
 catch (int error){
  if(error == 1)
    cout << "Wrong day!\n";
  else if(error == 2)
    cout << "Wrong month!\n";
 cout << "Error Number: " << error << endl;
 }

}
