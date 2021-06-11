#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;


/**
 *  When a copy constructor is needed ?
 *  -   By default, copy constructor does a shallow copy. If we need to do
 *      deep copy, we need to create the copy constructor of our own.
 * 
 *  Shallow Copy :
 *  ------------
 *  -   If we have pointer in our class and if we will try to change the element,
 *      it will change the main object as well.
 *  Deep Copy:
 *  ---------
 *  -   We will copy the pointer elements in different object so main object will
 *      not be changed if we modify the main object.
 */

class Car{
    private:
        float price;

    public:
        int model_no;
        char *name;

        Car(){
            name = NULL;
        }

        Car(float p, int m, char *n){
            price = p;
            model_no = m;
            name = new char[strlen(n)+1];
            strcpy(name, n);
        }

        //Copy Constructor
        Car(Car &X){
            price = X.price;
            model_no = X.model_no;
            //deep copy
            name = new char[strlen(X.name)+1];
            strcpy(name, X.name);
        }

        //Copy assignment operator
        void operator=(Car &X){
            price = X.price;
            model_no = X.model_no;
            //deep copy
            name = new char[strlen(X.name)+1];
            strcpy(name, X.name);
        }

        void print(){
            cout << "Name : " << name << endl;
            cout << "Model : " << model_no << endl;
            cout << "Price : " << price << endl << endl;
        }

        // Destructor for deleting the dynamically allocated memery.
        ~Car(){
            cout << "inside destructor of " << this->name << endl;
            if(this->name != NULL){
                delete [] name;
            }
        }
};

int main() {
    Car c(100, 200, (char *)"BMW"); // parameterized constructor
    Car d(c);  // Copy constructor
    c.print();
    d.print();
    cout << "=======================" << endl;

    d.model_no = 900;
    c.print();
    d.print();
    cout << "=======================" << endl;

    /**
     *  -   Without Copy constructor, shallow copy will be done and both the 
     *      objects will be changed to "AMW".
     *  -   With copy constructor, deep copy will be done and only object d
     *      will be changed to "AMW".
     */
    d.name[0] = 'A';
    c.print();
    d.print();
    cout << "=======================" << endl;

    /**
     *  -   Without Copy assignment operator, shallow copy will be done.
     *  -   With Copy assignment operator, deep copy is needed.
     */ 
    Car a = c;  // copy constructor will be called.
    Car b;
    b = c;  // copy assignment operator will be called.
    b.name[0] = 'A';
    c.print();
    b.print();
    cout << "=======================" << endl;


    return 0;
}