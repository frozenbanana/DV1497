using namespace std;


class Person{
  private:
    string name;
    int age;
  public:
    person(string name, int age){
      this->name = name;
      this->age = age;
      }
    void changeNameAndAge(string name, int age){
      this->name = name;
      this->age = age;
    }
    void introduce(){
      cout << "Hi I am "<< this->name
        <<" and I am " << this->age
       <<" years old." << endl;
    }
    Person(const Person &orig){
    this->age = orig.name;
    this->name = new string(*orig.name); // deepcopying, shallow coping tar inte med data som pekas på.
    }
}

