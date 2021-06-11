/**
 *  Encapsulation:
 *  =============
 *  -   combine the data and functions into an entity ia called as encapsulation.
 *      Ex: person class that can have multiple data member and functions.
 * 
 *  Abstraction:
 *  ===========
 *  -   hiding the un-necessary details from the outside world.
 *      Ex: -   TV is operated with remote but internal (what's happening inside) is
 *              not known to us. Another example is ATM.
 *          -   sort method 
 *          -   STL
 *  -   We need to make the property/function "private" to achieve abstraction.
 *  -   Updates/Changes can be done easily without affecting the user experience.
 *  -   We can avoid the errors as it will be visible from third person.
 * 
 *  Inheritance:
 *  ===========
 *  -   Inheriting the characteristics/properties from the parent.
 *  -   If we don't specify the access modifier , be default it is considered as private.
 *  -   INHERITED PUBLICLY:
 *      -   private properties are not accessible.
 *      -   protected properties will come under protected properties of child class.
 *      -   public properties will come under public properties of child class.
 *  -   INHERITED PROTECTED:
 *      -   private properties are not accessible.
 *      -   protected properties will come under protected properties of child class.
 *      -   public properties will come under protected properties of child class.
 *  -   INHERITED PRIVATE:
 *      -   private properties are not accessible.
 *      -   protected properties will come under private properties of child class.
 *      -   public properties will come under private properties of child class.
 *  
 *  -   Constructor execution would happen from parent to child.
 *  -   Destructor execution would happen from child to parent.
 * 
 *  Types of Inheritance:
 *  --------------------
 *  1.  Single Inheritance: 
 *      -   One parent and one child
 *                  A
 *                  |
 *                  B
 *  2.  MultiLevel Inheritance:
 *      -   Muliple level like B inherits A , C inheritance B
 *                  A
 *                  |
 *                  B
 *                  |
 *                  C
 *  3.  Hierarchiral Inheritance:
 *      -   Tree like structure :
 *          Ex : B, C, D inherits A class.
 *                      A
 *                     / \
 *                    B   C
 *  4.  Multiple Inheritance:
 *      -   Multiple base clases and single child class
 *          Ex :  Teaching Assistance can hve properties from both Teacher & Student class.
 *                  teacher     student
 *                      \           /
 *                       \         /
 *                    Teaching Assistant
 *  5.  Hybrid Inheritance:
 *      -   Mixed inheritance
 *      -   If we use more than one inheritance type together. 
 *                         G
 *                       /   \             
 *                      A     B
 *                       \   /
 *                         C
 *                         |
 *                         D
 *                       /   \
 *                      E     F
 *      -   We may get the diamond problem with this type.
 *      -   Here , we will multiple copies of G's functions which will result in ambiguity. 
 *          Possible ways to handle this problem:
 *          1.  Define the same function in C class then C's function will be called.
 *          2.  Use scope resolution operator like :
 *                      c.A::function();
 *          3.  To avoid multiple copies to be stored, we can use virtual. Virtual
 *              keyword ensures that we store only one copy of base class.
 */
#include<iostream>

using namespace std;

/**
 *  INHERITED PUBLICLY
 */
class Vehicle{
    private:
        int maxSpeed;
    protected:
        int numTyres;
    public:
        string color;
};
class Car : public Vehicle{
    public:
        int numGears;

        void print() {
            cout << "Number of tyres - car : " << numTyres << endl;
            cout << "Color - car : " << numTyres << endl;
            cout << "Number of gears - Car : " << numTyres << endl;
            // cout << "Mex Speed : " << maxSpeed;  // since it is private property so not visible.
        }
};
void problem1(){
    Vehicle v;
    v.color = "Blue";
    // v.maxSpeed = 12;     //  private properties not accessible
    // v.numTyres = 12;     //  protected properties are only accessible in same/child class.

    Car c;
    c.color = "Red";
    c.numGears = 12;
    // c.numTyres = 13;      //  protected properties are only accessible in same/child class.
}

/**
 *  INHERITED PROTECTED
 */
class MotorCycle : protected Vehicle{
    public:
        int numGears;

        void print() {
            cout << "Number of tyres - car : " << numTyres << endl;
            cout << "Color - car : " << numTyres << endl;
            cout << "Number of gears - Car : " << numTyres << endl;
            // cout << "Mex Speed : " << maxSpeed;  // since it is private property so not visible.
        }
};
void problem2(){
    MotorCycle c;
    // c.color = "Red";      // public properties became protected.
    c.numGears = 12;
    // c.numTyres = 13;      //  protected properties are only accessible in same/child class.
    // c.maxSpeed = 30;      //  private properties not accessible
}

/**
 *  INHERITED PRIVATE
 */
class Truck : private Vehicle{
    public:
        int numGears;

        void print() {
            cout << "Number of tyres - car : " << numTyres << endl;
            cout << "Color - car : " << numTyres << endl;
            cout << "Number of gears - Car : " << numTyres << endl;
            // cout << "Mex Speed : " << maxSpeed;  // since it is private property so not visible.
        }
};
void problem3(){
    Truck c;
    // c.color = "Red";      // public properties became private.
    c.numGears = 12;
    // c.numTyres = 13;      //  protected properties became private.
    // c.maxSpeed = 30;      //  private properties not accessible
}

/**
 *  Inheritance related to constructor
 */
class Vehicle2{
    public:
        string color;

        Vehicle2(){
            cout << "vehicle2 - default constructor" << endl;
        }
        Vehicle2(int a){
            cout << "vehicle2 - parameterized constructor" << endl;
        }
        ~Vehicle2() {
            cout << "vehicle2 - default destructor" << endl;
        }
};
class Car2 : public Vehicle2{
    public:
        Car2() : Vehicle2() {
            cout << "car2 - default constructor" << endl;
        }
        Car2(int a) : Vehicle2(a){
            cout << "car2 - parameterized constructor" << endl;
        }
        // if parent doesn't have default constructer i.e. have parameterized 
        // constructor instead, then it becomes a complusion to specify type as below.
        Car2(string s) : Vehicle2(2){
            cout << "car2 - parameterized constructor - string" << endl;
        }
        ~Car2() {
            cout << "car2 - default destructor" << endl;
        }
};
void problem4(){
    Car2 c;
    Car2 c2(16);
    Car2 c3("sjdu");
}

/**
 *  Multiple Inheritance
 */
class Teacher{
    public:
        string name;
        string age;

        void print(){
            cout << "Teacher" << endl;
        }
};
class Student{
    public: 
        void print() {
            cout << "Student" << endl;
        }
};
class TA : public Teacher, public Student{

};
void problem5(){
    TA ta;
    // print(); // ambiguity due to diamond problem, so we need to use scope resolution
    ta.Student::print();
    ta.Teacher::print();
}

/**
 *  Mixed Inheritance - Diamond Problem - Virtual keyword
 */
class Vehicle3{
    public:
        string color;

        Vehicle3(){
            cout << "vehicle3 - default constructor" << endl;
        }
        Vehicle3(int a){
            cout << "vehicle3 - parameterized constructor" << endl;
        }
        ~Vehicle3() {
            cout << "vehicle3 - default destructor" << endl;
        }
        void print(){
            cout << "Vehicle print function" << endl;
        }
};
class Car3 : virtual public Vehicle3{
    public:
        Car3() : Vehicle3() {
            cout << "car3 - default constructor" << endl;
        }
        Car3(int a) : Vehicle3(a){
            cout << "car3 - parameterized constructor" << endl;
        }
        // if parent doesn't have default constructer i.e. have parameterized 
        // constructor instead, then it becomes a complusion to specify type as below.
        Car3(string s) : Vehicle3(2){
            cout << "car3 - parameterized constructor - string" << endl;
        }
        ~Car3() {
            cout << "car3 - default destructor" << endl;
        }
};
class Truck3 : virtual public Vehicle3{
    public:
        Truck3() : Vehicle3() {
            cout << "truck3 - default constructor" << endl;
        }
        Truck3(int a) : Vehicle3(a){
            cout << "truck3 - parameterized constructor" << endl;
        }
        // if parent doesn't have default constructer i.e. have parameterized 
        // constructor instead, then it becomes a complusion to specify type as below.
        Truck3(string s) : Vehicle3(2){
            cout << "truck3 - parameterized constructor - string" << endl;
        }
        ~Truck3() {
            cout << "truck3 - default destructor" << endl;
        }
};
class Bus3 : public Car3, public Truck3{
    public:
        Bus3(){
            cout << "Bus3 - default constructor" << endl;
        }
        Bus3(int a){
            cout << "Bus3 - parameterized constructor" << endl;
        }
        // if parent doesn't have default constructer i.e. have parameterized 
        // constructor instead, then it becomes a complusion to specify type as below.
        Bus3(string s){
            cout << "Bus3 - parameterized constructor - string" << endl;
        }
        ~Bus3() {
            cout << "Bus3 - default destructor" << endl;
        }
        // one way to resolve diamond problem but  still we have multiple copies of top parent.
        // void print(){
        //     cout << "Bus print function" << endl;
        // }
};
void problem6(){
    Bus3 c;
    // c.print();          // ambiguity due to multiple copies through multiple base classes.
    c.Car3::print();        // using scope resolution.
    c.print();          // after virtual keyword , we directlt call the top parent's function.
    // Bus3 c2(16);
    // Bus3 c3("sjdu");
}

int main(){
    // inheritance publicly
    // problem1();

    // inherited protected 
    // problem2();

    // inherited private
    // problem3();

    //  contructor inheritance
    // problem4();

    // Multiple Inheritance
    // problem5();

    // Mixed Inheritance
    problem6();
}