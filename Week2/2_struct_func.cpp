#include <iostream>

using namespace std;


struct Student{
  string name;
  long number;
  int scores[3];
  // A struct can have functions too. (Not in C language)
  void printStudent();
  void enterScores();
  void init_student(string name,long number);
  void add_scores(int p1,int p2,int p3);
};

// Function of a Student struct. 'Student::' is added to that purpose.
// If function is written inside of a struct, no need to pass a struct object to
// function. Here print function does not have any parameter.
void Student::printStudent(){
  cout << "Name: "<<name <<endl << "Number: "<<number <<endl << "Scores: ";
  for(int i = 0 ; i< 3;i++) cout << scores[i] << " ";
  cout << endl;
}

/* Name of the parameters and elements of the struct have same names.
It is not clear that which name stands for parameter or element of the struct.
Thus, name = name; and number = number will not work.
*/
void Student::init_student(string name,long number){
  /* name = name;
     number = number;*/
  this->name = name;
  this->number = number;
  // Here this pointer refers to a object that calls the funtion. Which is
  // student2 variable for our example
}

void Student::add_scores(int p1,int p2,int p3){
    scores[0] = p1;
    this->scores[1] = p2;
    scores[2] = p3;
}


int main(){

  Student student1;
  student1.name = "Burak Bekci";
  student1.number = 12341234;
  student1.scores[0] = 12;
  student1.scores[1] = 62;
  student1.scores[2] = 92;
  student1.printStudent();

  cout << endl << endl;
  Student student2;
  student2.init_student("Sadık Ekin",23241442);
  student2.add_scores(89,88,76);
  student2.printStudent();
  return 0;
}
