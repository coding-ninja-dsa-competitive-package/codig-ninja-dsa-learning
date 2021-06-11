#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

/**
 *  What will be the output of the following program ?
 *  Ans : 1
 */
class Shape{
    public : 
    int height;
    int width;
};
void problem1() {
    Shape *s = new Shape();
    s -> height = 1;
    cout << s -> height;
}

/**
 *  What will be the output of the following program ?
 *  Ans : Garbage Value
 */
class Box{
    public :
        int width;
        int height;
        int length;
        void volume(){
            cout << length * width * height;
        }
};
void problem2() {
    Box b;
    b.height = 5;
    b.width = 4;
    b.volume();
}

/**
 *  What will be the output of the following program ?
 *  Ans : 12
 */
class Student{
    public :
    char *name;
    int rollNo;
    Student(int num){
        rollNo = num;
    }

    void print(){
        cout << rollNo;
    }
};
void problem3() {
    Student s(12);
    s.print();
}

/**
 *  What will be the output of the following program ?
 *  Ans : Compilation - Since no defalut constructor.
 */
class Student1{
    public :
    char name;
    int rollNo;

    Student1(int num){
        rollNo = num;
    }

    void print(){
        cout << name << " "  <<  rollNo;
    }
};

void problem4() {
    //Student1 *s = new Student1();
    //s -> name = 'A';
    //s -> rollNo = 15;
    //s -> print();
}

/**
 *  Which of the following statements are not true about destructor?
 *  1. It is invoked when object goes out of the scope
 *  2. Like constructor, it can also have parameters 
 *  3. It can be declared in private section
 *  4. It bears same name as that of the class and precedes tilde sign. 
 * 
 *  Ans : Only 2
 */

/**
 *  Copy Constructor
 * 
 *  Assume class DEMO. Which of the following statement(s) responsible to 
 *  invoke copy constructor?
 *  1. DEMO D2(D1); //  Here D1 is an already created object of class  DEMO
 *  2. D2 = D1; // Here D1, D2 are already created objects of class DEMO
 */

/**
 *  Copy Assignment Operator
 *  
 *  Which of the following statement is feasible ?
 *  Ans : p2 = *p1
 *  
 *  Options were:
 *  1.  p2=p1
 *  2.  p2=*p1;
 */
class Pair{
    public :
        int first;
        int second;
};

void problem5(){
    Pair *p1 = new Pair;
    Pair p2;
    //What will be the output ? 
    Pair p3;
    p3.first = 10;
    p3.second = 20;
    Pair p4;
    p4 = p3;
    cout << p4.first << " " << p4.second << endl;  // 10 20
}

int main(){
    problem1();
    problem2();
    problem3();
    problem4();
    problem5();
}