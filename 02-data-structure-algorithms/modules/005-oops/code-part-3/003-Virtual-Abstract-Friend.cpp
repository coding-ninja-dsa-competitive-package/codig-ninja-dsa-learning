/**
 *  Pure Virtual Function:
 *  ======================
 *  -   Function that have no definition.
 *          virtual void print() = 0;
 *  
 *  Abstract Class :
 *  ==============
 *  -   Incomplete class.
 *  -   Any class that atleast one virtual function .
 *  -   We can't create object for abstract class.
 * 
 *  Friend Function:
 *  ================
 *  -   We can access the private/protected properties with the help of friend functions.
 *  -   Friend functions doesn't have access to "this" pointer.
 *  -   Friend functions can be declared in any access modifier i.e. private, protected etc.
 * 
 *  Friend Class:
 *  =============
 *  -   If we have multiple functions which needs access to private properties of
 *      another class, we can make the class as friend class.
 */
#include<iostream>

using namespace std;

/**
 *  Abstract Class
 */
class AbstractClass {
    public :
        virtual void print() = 0;
};
class Derived : public AbstractClass{
    public:
        void print(){
            cout << "Derived print function"<< endl;
        }
};
void problem1(){
    // AbstractClass a;     // abstract class object can't be created.
    Derived d;
    d.print();
}

/**
 *  Friend function
 */
class Bus{
    public:
        void print();
};
class Truck{
    private:
        int x;
    protected:
        int y;
    public: 
        int z;  
        
        friend void Bus::print();
};
//friend function need to be defined outside
void Bus::print(){
    Truck t;
    t.x = 20;
    t.y = 30;
    cout << t.x << " " << t.y << endl;
}
void problem2(){
    Bus b;
    b.print();
}

/**
 *  Friend Class
 */
class Bus2{
    public:
        void print2();
};
class Truck2{
    private:
        int x;
    protected:
        int y;
    public: 
        int z;  
        
        friend class Bus2;
};
//friend function need to be defined outside
void Bus2::print2(){
    Truck2 t;
    t.x = 20;
    t.y = 30;
    cout << t.x << " " << t.y << endl;
}
void problem3(){
    Bus2 b;
    b.print2();
}

int main() {
    // abstract class
    // problem1();

    // friend function - access to private properties of any class.
    // problem2();

    // friend class
    //problem3();

    int arr[]= {1, -2, 3 , 4,5, 6};
    int dp[6];
    for(int i=0;i<6;i++)dp[i]=0;
    dp[0]=arr[0];
    int ans=max(0,arr[0]);
    for(int i=1;i<6;i++){
        dp[i]=max(dp[i-1]+arr[i],arr[i]);
        ans=max(ans,dp[i]);
    }

    cout << ans;


    return 0;
}


