#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

/**
 *  What will be the output of the following code ?
 *  Ans : abc 101 xyz 150   
 */
class Student1{
    public :
        char *name;
        int rollNo;

        // Constructor 1
        Student1(int num){
            rollNo = num;
            name = new char[10];
            strcpy(name, "abc");
        }

        // Constructor 2
        Student1(int num, char *str){
            rollNo = num;
            name = new char[strlen(str) + 1];
            strcpy(name, str);
        }   

        void print(){
            cout << name << " "  <<  rollNo << " ";
        }
};
void problem1() {
    Student1 s1(101);
    s1.print(); // abc 101
    Student1 *s2 = new Student1(150, "xyz");
    s2 -> print();  // xyz 150
}

/**
 *  What is the output
 *  Ans : Nisha 101 Nisha 102
 */
class Student2{
    public :
        char *name;
        int rollNo;

        void print(){
            cout << name << " "  <<  rollNo << " ";
        }
};
void problem2() {
    char name[] = "Misha";
    Student2 s1;
    s1.name = name;
    s1.rollNo = 101;

    name[0] = 'N';
    Student2 s2;
    s2.name = name;
    s2.rollNo = 102;

    s1.print(); // Nisha 101
    s2.print(); // Nisha 102
}

/**
 *  What is the output ?
 *  Ans : COmpilation errror
 */
class Student3 {
    public :
        const int rollNumber;
        int age;
};
void problem3() {
    // Student3 s1;  // compilation error since rollNumber is const
    // s1.rollNumber = 101;
    // s1.age = 20;
    // cout << s1.rollNumber << " " << s1.age;
}

/**
 *  What is the output?
 *  Ans : 100 23
 */
class Student4 {
    public :
        const int rollNumber;
        int age;
        Student4(int r, int a) : rollNumber(r), age(a) {}
};
void problem4() {
    Student4 s1(100, 23);
    cout << s1.rollNumber << " " << s1.age;
}

/**
 *  What is the output?
 *  Ans : Error since x is not in initialization list
 */
class Student5 {
    public :

    const int rollNumber;
    int age;

    int &x;

    //Student5(int r, int a) : rollNumber(r), age(a) {}
};
void problem5() {
    // Student5 s1(100, 23);
    // s1.x = age;
    // cout << s1.rollNumber << " " << s1.age << " " << s1.x;
}

/**
 *  What is the output?
 *  Ans : Garbage Garbage
 */
class Student6 {
    public :
        int rollNumber;
        int age;
};
void problem6() {
    Student6 s1;
    Student6 const s2 = s1;
    s1.rollNumber = 101;
    s1.age = 20;
    cout << s2.rollNumber << " " << s2.age;
}

/**
 *  What is the output?
 */
class Student7 {
    int rollNumber;
    public :
        int age;
        Student7(int r) {
            rollNumber = r;
        }
        int getRollNumber() {
            return rollNumber;
        }
};
void problem7() {
    Student7 s1(101);
    s1.age = 20;
    Student7 const s2 = s1;
    //cout << s2.getRollNumber(); //compilation error since it is not const function
}

/**
 *  Correct Statement?
 *  Ans : Student8::totalStudents
 */
class Student8 {
    public :
        int rollNumber;
        static int totalStudents;
};
int Student8::totalStudents = 20;

void problem8() {
    Student8 s;
    // Correct statement to access totalStudents
}

/**
 *  What is the output?
 *  Ans : Compilation Error
 */
class Student9 {
    public :
        int rollNumber;
        static int getRollNumber() {
            //return rollNumber; // compilation error since rollNumber is not static member
        }
};
void problem9() {
    Student9 s;
    s.rollNumber = 101;
    cout << s.getRollNumber() << endl;
}

/**
 *  What is the output?
 *  Ans : 24
 */
class Student10 {
    public :
        int rollNumber;
        static int numOfStudents;
        Student10() {
            numOfStudents++;
        }
};
int Student10::numOfStudents = 20;

void problem10() {
    Student10 s1, s2, s3, s4;
    cout << Student10 :: numOfStudents;
}

int main(){
    problem1();
    problem2();
    problem3();
    problem4();
    problem5();
    problem6();
    problem7();
    problem8();
    problem9();
    problem10();
}