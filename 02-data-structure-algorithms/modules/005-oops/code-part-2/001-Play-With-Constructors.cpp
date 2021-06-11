#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

/**
 *  1.  Constructor:
 *      -   responsible for creating an object
 *      -   gets called automatically and only once.
 *      -   same name as class name.
 *      -   parametrised constructor can be created.
 *      -   constructor overloading can be done.
 *  2.  Copy Constructor:
 *      -   make a copy of the given object
 *      -   exists by default.
 *      -   shallow copy 
 *      -   you can create your own copy constructor when deep copy is needed.
 *  3.  Copy Assignment Operator:
 *      -   Copies when you do assignment
 *      -   Car d = c; // Copy Constructor
 *      -   Car d;
 *          d = c;  // copy assignment operator
 *      -   you can write your own copy assignment operator for a deep copy.
 *      -   can be called many times.
 *  4.  Destructor:
 *      -   clear out the memory occupied by the object.
 *      -   called automatically when the object goes out of scope
 *      -   needed to write when you have dynamically allocated memory.
 * 
 *  Some Other Concepts:
 *  5.  const data members : 
 *      -   Once initialized, their values can't be changed.
 *  6.  Initialization List:
 *      -   Init constant as well as other memeber.
 *  7.  const parameters:
 *      -   which don't get updated in that particular function.
 *  8.  const function:
 *      -   which don't update the data member of the class.
 */

class Student{
    //access-modifier
    public:
        string name;
        int roll_no;
        //declare constant 
        const int MIN;
        
        //no-arg or default constructor
        // Init List - constant members can be initialized
        Student():MIN(-1){
            cout << "constructor called" << endl;
        }
        //parameterized constructor
        Student(string str, int roll, int minimum=-1):MIN(minimum), roll_no(roll){
            cout << "parameterized constructor called" << endl;
            this->name = str;
            //this->roll_no = roll;  // added in initialization list
        }
        //copy constructor
        Student(Student &s):MIN(s.MIN){    
            cout << "copy constructor called" << endl;
            name = "Copy Constructor";
            roll_no = 111;
        }

        //copy assignment operator
        void operator=(Student &s){    
            cout << "copy assignment operator called" << endl;
            name = s.name;
            roll_no = s.roll_no;
        }

        //destructor 
        ~Student(){
            cout << "Inside destructor of " << this->name << endl;
        }

        void print() const{
            cout << "name - " << name << ", roll number - " << roll_no << endl;
        }

        // const parameters
        void print(const int a) const{
            cout << "Const Integer : " << a << endl;
        }
};

int main() {
    Student s1; // default or no-arg constructor is called
    s1.name = "Tarun";
    s1.roll_no = 1;
    s1.print();
    cout << "=======================" << endl;

    Student s2("Deepak", 2); // parameterised constructor is called
    s2.print();
    cout << "=======================" << endl;

    Student s3(s2);  // copy constructor is called.
    s3.print();
    Student s4 = s1;  // copy constructor is called.
    s4.print();
    s1.print();
    s2.print();
    cout << "=======================" << endl;

    Student s5;
    s5 = s2;  // copy assignment operator is called.
    s5.print();
    cout << "=======================" << endl;

    //Dynamically created Student
    Student *s6 = new Student("ABC" , 364);
    s6->print();
    delete s6;
    cout << "=======================" << endl;


    return 0;
}