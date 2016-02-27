#include "Student.h"

void showAllStudents(Student st[], int nrOfStudents);
void addStudent(Student st[], int &nrOfStudents);
int findStudent(Student st[], int nrOfStudents);
bool removeStudent(Student st[], int &nrOfStudents);
int menu();

int main(void){
  Student st[20];
  int nrOfStudents;
  int option = 0;
  while (option != 5) {
    option = menu();
    switch (option){
      case 1:
        cin.ignore();
        addStudent(st, nrOfStudents);
        break;
      case 2:
        showAllStudents(st, nrOfStudents);
        break;
      case 3:
        cin.ignore();
        if(removeStudent(st, nrOfStudents) != -1)
          cout << "Succesful!\n";
        break;
      case 4:
          int position;
          position = findStudent(st, nrOfStudents);
          if(position != -1){
            st[position].show();
          }
          else
            cout << "Not found\n";
        break;
      }
  }
  return 0;
}

void showAllStudents(Student st[], int nrOfStudents){
    for (int i = 0; i < nrOfStudents; i++) {
      st[i].show();
    }
}

void addStudent(Student st[], int &nrOfStudents){
    string name;
    string program;
    int phoneNumber;
    int dateOfBirth;
    cout << "Enter name: ";
    getline(cin,name);
    cout << "Enter program: ";
    getline(cin,program);
    cout << "Enter phone number: ";
    cin >> phoneNumber;
    cout << "Enter date of birth: ";
    cin >> dateOfBirth;
    st[nrOfStudents] = Student(name, program, phoneNumber, dateOfBirth);
    nrOfStudents++;

}

int findStudent(Student st[], int nrOfStudents){
    int flag = -1;
    string name;
    cout << "Enter name to search: " << endl;
    getline(cin,name);
    for (int i = 0; i < nrOfStudents; i++) {
      if(st[i].getName() == name)
        flag = i;
    }

    return flag;
}

bool removeStudent(Student st[], int &nrOfStudents){
    bool isRemoved = false;
    int position = -1;
   cout << "Enter name to search: " << endl;
    position = findStudent(st, nrOfStudents);
        if(position != -1){
          st[position] = st[nrOfStudents];
          isRemoved = true;
          nrOfStudents--;
        }
    return isRemoved;
}

int menu(){
  cout << "1. Add a student" << "\n2. Show all students" << "\n3. Remove a student by name"
       << "\n4. Find a student" << "\n5. Exit" << endl;
  int option = 0;
  cin >> option;
  return option;

}


