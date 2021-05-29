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

/**
 *  Fraction Class
 */
class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int num, int den){
            this->numerator = num;
            this->denominator = den;
        }

        void print(){
            cout << this->numerator << " / " << this->denominator << endl;
        }

        void add(const Fraction &f){
            int lcm = this->denominator * f.denominator;
            int x = lcm / this->denominator;
            int y = lcm / f.denominator;
            int num = x*this->numerator + y*f.numerator;
            this->numerator = num;
            this->denominator = lcm;
            simplify();
        }

        void simplify(){
            int gcd = 1;
            int minimum = min(this->numerator, this->denominator);
            for(int i=1; i<=minimum; i++){
                if(this->numerator%i == 0 && this->denominator%i == 0){
                    gcd = i;
                }
            }
            this->numerator = this->numerator/gcd;
            this->denominator = this->denominator/gcd;
        }
};

/**
 *  Create Complex Number class.
 */
class ComplexNumbers{
    private:
        int real;
        int imaginary;
    public:
        ComplexNumbers(int r, int i){
            this->real = r;
            this->imaginary = i;
        }

        void plus(const ComplexNumbers &c){
            this->real = this->real+c.real;
            this->imaginary = this->imaginary+c.imaginary;
        }

        void  multiply(const ComplexNumbers &c){
            int r = this->real*c.real - this->imaginary*c.imaginary;
            int i = this->real*c.imaginary + this->imaginary*c.real;
            this->real = r;
            this->imaginary = i;
        }

        void print(){
            cout << this->real << " + " << "i" << imaginary<< endl;
        }
};

void assignment1(){
    int real1, imaginary1;
    int real2, imaginary2;
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    int choice;
    cin >> choice;
    if(choice == 1){
        c1.plus(c2);
        c1.print();
    } else if(choice == 2){
        c1.multiply(c2);
        c1.print();
    }
}

int main() {

    //problem1();
    //problem2();
    //problem3();
    //problem4();
    //problem5();

    //Fraction class run
    // Fraction f1(10, 2);
    // Fraction f2(20,6);
    // f1.add(f2);
    // f1.print();

    assignment1();
    

    return 0;
}