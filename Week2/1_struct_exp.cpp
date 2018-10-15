#include <iostream>

using namespace std;
/*
  Struct is a data type that can contain more than 1 different data types together.
  Here Person is the name of the struct.
*/
struct Person{
  int age;
  float height;
  float weight;
};

/*
To access the member of the structs '.' operator is used.
*/
void print_Person(Person p){
    cout << "Person with " << p.height << " m and " << p.weight << " kg at " << p.age  << " age"<< endl;
}
/*
  Value of the Person(toUpdate) changed only in the function.
  It is because we pass its value to the function. Copy of the variable is created.
*/
void update_Person_height(float newHeight,Person toUpdate ){
  toUpdate.height = newHeight;
}
/*
  Update Person using its address.
  Value changed everywhere of the code.
  When address of a struct element is used, '->' operator is used not '.'.
*/
void update_Person_height_pointer(float newHeight,Person *toUpdate ){
  toUpdate->height = newHeight;
}
/*
  Update the value of an element using & operator.
*/
void update_Person_height_reference(float newHeight,Person &toUpdate ){
  toUpdate.height = newHeight;
}

int main(){
    Person person1;
    person1.age = 1;
    person1.height = 1.75;
    person1.weight = 80.2;
    cout << endl <<"Printing our person" << endl;
    print_Person(person1);
    cout << endl << "Let us try to change the height of the person to 1.93"<<endl;
    update_Person_height(1.93,person1);
    print_Person(person1);
    cout << "Nothing changed. Because we have used pass by value technique"<<endl;
    cout << endl<< endl;
    cout << endl << "Let us try to change the height with a new function"<<endl;
    update_Person_height_pointer(1.93,&person1);
    print_Person(person1);
    cout << "We have used pass by reference technique. Address of the struct element passed to the function"<<endl;
    cout << endl<< endl;
    cout <<"Lastly & operator (reference) is used."<<endl;
    update_Person_height_reference(1.33,person1);
    print_Person(person1);
    cout << "Again value of the person is changed."<<endl;

  return 0;





}
