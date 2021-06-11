#include<iostream>

using namespace std;
/**
 *  Const Functions and Static Members
 */

class Student{
    private:
        // good practice to declare the static memeber with private modifier.
        static int totalStudents;
    public:
        int roll_number;
        int age;

        Student(){
            totalStudents++;
        }

        int getAge(){
            return age;
        }

        //const function
        int getRollNumber() const{
            return roll_number;
        }

        //static member function can call only static members
        static int getTotalStudents(){
            return totalStudents;
        }
};

//Initialize the static member
int Student::totalStudents = 0;

//Const Object Creation
void problem1(){
    const Student s1;
    //s1.getAge();  //compilation error since the getAge() is not const function
    s1.getRollNumber();

}

//Static Members
void problem2(){
    Student s;
    cout << s.roll_number << " " << s.age << endl;
    cout << s.getTotalStudents() << endl;

    Student s1, s2, s3, s4, s5;
    cout << "Total Number of Stdents created : " <<  Student::getTotalStudents() << endl;
}

int main(){
    // const object creation
    problem1();
    // static members
    problem2();
}