/**
 *  Polymorphism:
 *  ============
 *  -   It means many forms.
 *  -   Where a set of code behaves differently in different context,
 *  
 *  Types:
 *  -----
 *  1.  Compile Time Polymorphism:
 *      --------------------------
 *      -   We decide at compile time - how to behave.
 *      -   Can be achieved by Function Overloading , Operator Overloading.
 *      -   Method overriding.
 *  2.  Runtime Time Polymorphism:
 *      -------------------------
 *      -   We decide at runtime - how to behave.
 *      -   Our parent reference object can point to child class object.
 *          which is known as run time polymorphism.
 *      -   To achieve runtime polymorphism, we need to have virtual function 
 *          in base class.
 *      Use case:
 *      ---------
 *      -   In any organization, employee may be categorized in diff categories.
 *          So Calculating Salary function can be diff for each category. We can 
 *          virtual function to provide default implementation . 
 */
#include<iostream>

using namespace std;
/**
 *  Function Overloading:
 *  -   Compile time polymorphism.
 *  -   Multiple function with same name but diff signature,
 *  -   Signature is identified by the function name and the arguments but not return type.
 */
class FunctionOverloading{
    public :
        // int test(){};       //  copilation error - since we have alredy function present.
        void test(){};
        void test(int a){};
        void test(int a, int b){}
};
void problem1(){
    FunctionOverloading f;
    f.test(3);
    f.test(2, 4);
}

/**
 *  Method/Function Overriding
 *  -   if same function is present in both parent and child class,
 */
class Vehicle{
    public:
        void print() {
            cout << "Vehicle print function" << endl;
        }
};
class Car : public Vehicle{
    public:
        void print() {
            cout << "Car print function" << endl;
        }
};
void problem2(){
    Vehicle v;
    Car c;
    v.print();  //  vehicle function will be called since it is vehicle class object.
    c.print();  //  car function will be called since it is vehicle class object.

    Vehicle *v1 = new Vehicle;
    Vehicle *v2 = &c;
    v1->print();    // Vehicle call print function will be called with no doubt

    // Vehicle call print function will be called because we are deciding at compile 
    // time which class function to call & v2 is referring to Vehicle.
    v2->print();
}

/**
 *  Runtime Polymorphism
 *  -   To achieve runtime polymorphism, we need to have virtual function in base class.
 */
class Vehicle2{
    public:
        virtual void print() {
            cout << "Vehicle print function" << endl;
        }
};
class Car2 : public Vehicle2{
    public:
        void print() {
            cout << "Car print function" << endl;
        }
};
void problem3(){
    Car2 c;
    Vehicle2 *v1 = new Vehicle2;  //  Vehicle print function will be called
    Vehicle2 *v2 = &c;           //  car print function will be called 
    v1->print(); 
    v2->print();
}

int main(){
    // Function Overloading - Compile Time Polymorphism
    // problem1();

    // Method Overriding - Compile Time Polymorphism
    problem2();

    // Method Overriding - Runtime Polymorphism - Virtual function
    // problem3();
}