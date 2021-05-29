#include<iostream>
using namespace std;

void increment(int& i){
    i++;
}

// Bad Practice - to return the reference variable siince the var a is local and
// memory can be deleted at any point of time.
int& func1(int n){
    int a = n;
    return a;
}
// Bad Practice - to return the reference variable siince the var a is local and
// memory can be deleted at any point of time.
int* func2(){
    int a = 10;
    return &a;
}

void func3(int p){
    cout << p << " ";
}

void problem1(){
    int i = 10;
    int &p = i;
    func3(p++);
    cout << i << endl; // 10 11
    cout<<"========================"<<endl;
}

void func4(int i, int& j, int p){
    i++;
    j++;
    p++;
}

void problem2(){
    int i = 10;
    int j = 6;
    int &p = i;
    func4(i, j, p); //i will be unchanged, j will be changed as we are assigning to reference variable.
                    // since we are assigning i to p in function so it will be copied & i will remain same.
    cout << i << " " << j << " " << p << endl;
    cout<<"========================"<<endl;
}

int main(){
    int i;
    i=10;

    int &j = i; //Reference Variable - pointing to same memory location as i
    i++;
    cout << "j : " << j << endl;  // 11
    j++;
    cout << "i : " << i << endl;  // 12
    cout<<"========================"<<endl;

    int k=100;
    j=k;
    cout << "i : " << i << endl;  //100
    cout << "j : " << j << endl;  //100
    cout << "k : " << k << endl;  //100
    cout<<"========================"<<endl;

    increment(i);
    cout << "i : " << i << endl; // 101
    cout<<"========================"<<endl;

    //bad practice 
    int &m = func1(i);
    int *n = func2();
    cout<<"========================"<<endl;

    problem1();
    problem2();

    return 0;
}