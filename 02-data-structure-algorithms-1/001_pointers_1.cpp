#include<iostream>
using namespace std;

void problem1(){
    int i=100;
    cout << &i << endl;   //0x22fe4c - hexadecimal address
    cout<<"========================"<<endl;

    int *p = &i;
    cout << "address : " << p << ", value : "  << *p << endl;
    cout << sizeof(p) << endl;
    cout<<"========================"<<endl;

    i++;
    cout << "i : " << i << endl;
    cout << "*p : " << *p << endl;
    cout<<"========================"<<endl;

    int a = *p;
    a++;
    cout << a << endl;
    cout << *p << endl;
    cout<<"========================"<<endl;

    (*p)++;
    cout << "i : " << i << endl;
    cout << "*p : " << *p << endl;
    cout<<"========================"<<endl;

    // int *q; // never declare like this rather initialize with 0.
    // cout << "q : " << q << endl;
    // cout << "*q : " << *q << endl;
    // (*q)++;
    // cout << *q << endl;
    // cout<<"========================"<<endl;
}

void assignment1(){
    int a = 7;
    int b = 17;
    int *c = &b;
    *c = 7;
    cout  << a << "  " << b << endl;  // 7  7
    cout<<"========================"<<endl;

    int a1 = 50;
    int *ptr = &a1;
    int *q = ptr;
    (*q)++;
    cout << a1  << endl; //51
    cout<<"========================"<<endl;

    int a2 = 50;
    int *ptr2 = &a2;
    cout << (*ptr2)++ << " ";
    cout << a2 << endl; // 50 51
    cout<<"========================"<<endl;

    // int *ptr3 = 0;
    // int a3 = 10;
    // *ptr3 = a3;
    // cout << *ptr3 << endl;  // error
    cout<<"========================"<<endl;

    int a4 = 7;
    int b4 = 17;
    int *c4 = &b4; 
    a4 = *c4;
    *c4 = *c4 + 1;
    cout  << a4 << "  " << b4 << endl;
    cout<<"========================"<<endl;

    float f5 = 10.5;
    float p5 = 2.5;
    float* ptr5 = &f5;
    (*ptr5)++;
    *ptr5 = p5;
    cout << *ptr5 << " " << f5 << " " << p5 << endl;
    cout<<"========================"<<endl;
}

//Pointers Arithmetic
void assignment2(){
    int a = 7;
    int *c = &a;
    c = c + 1;
    cout  << a << "  " << *c << endl;
    cout<<"========================"<<endl;
}

//arrays and pointers
void problem2(){
    int a[10];
    cout << "a : " << a << endl;
    cout << "&a : " << &a << endl;
    cout << "&a[0] : " << &a[0] << endl;
    cout<<"========================"<<endl;

    a[0] = 5;
    a[1] = 10;
    cout << "value of 1st element : " << *a << endl;
    cout << "value of 2nd element : " << *(a+1) << endl;
    cout<<"========================"<<endl;

    int *p = &a[0];
    cout << "a : " << a << endl;
    cout << "p : "  << p << endl;
    cout << "&p : " << &p << endl;
    cout << "&a : " << &a << endl; 
    cout << "size of p : " << sizeof(p) << endl;
    cout << "size of a : " << sizeof(a) << endl;
    cout<<"========================"<<endl;

    p=p+1;
    //a=a+1; // compilation error - expression must be modifiable.

}

void assignment3(){
    int a[5];
    int *c;
    cout << sizeof(a) << " " << sizeof(c)<<endl;
    cout<<"========================"<<endl;

    int a1[6] = {1, 2, 3};
    cout << a1 << " " << &a1<<endl;
    cout<<"========================"<<endl;

    int a2[6] = {1, 2, 3};
    cout << (a2) << endl;
    cout << (a2 + 2) << endl;  // add 8 bytes to the address for a2
    cout<<"========================"<<endl;

    int a3[6] = {1, 2, 3};
    int *b3 = a3;
    cout << b3[2] << endl;  // 3
    cout<<"========================"<<endl;

    int a4[] = {1, 2, 3, 4, 5};
    cout << *(a4) << " " << *(a4 + 4) << endl;  // 1 5
    cout<<"========================"<<endl;

    // int a[] = {1, 2, 3, 4};
    // int *p = a++;  // error - expression must be modifiable.
    // cout << *p << endl;
    // cout<<"========================"<<endl;
}

void problem3(){
    int a[] = {1,2,3};
    char b[] = "acbc";
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
    cout<<"========================"<<endl;

    char *c = &b[0];
    cout << "c : " << c << endl;
    cout<<"========================"<<endl;

    char c1 = 'a';
    char *pc = &c1;
    cout<<"========================"<<endl;

    cout << "c1 : " << c1 << endl;
    cout << "pc : " << pc << endl;
    cout<<"========================"<<endl;

    char str[] = "abcde";
    //char *pstr = "abcde"; // warning - C++ forbids converting a string constant to 'char*'
}

void assignment4(){
    char ch = 'a';
    char* ptr = &ch;
    ch++;
    cout << *ptr << endl; //b
    cout<<"========================"<<endl;

    char b[] = "xyz";
    char *c = &b[0];
    cout << c << endl; //xyz
    cout<<"========================"<<endl;

    char b1[] = "xyz";
    char *c1 = &b1[0];
    c1++;
    cout << c1 << endl;
    cout<<"========================"<<endl;

    char s[]= "hello";
    char *p = s;
    cout << s[0] << " " << p[0] << endl;
    cout<<"========================"<<endl;
}

//=========================================
void print(int *p){
    cout << *p << endl;
}

void incrementPointer(int *p){
    p = p+1;
}

void increment(int *p){
    (*p)++;
}

int sum(int *a, int n){
    int sum=0;
    for(int i=0; i<n ; i++){
        sum+= a[i];
    }
    return sum;
}

void problem5(){
    int i=10;
    int *p = &i;
    print(p);  // print the value of i = 10
    cout<<"========================"<<endl;

    cout << p << endl;
    incrementPointer(p); // since pointer will be copied to function so pointer will change only in copy
    cout << p << endl;   // So same value of address will be printed.
    cout<<"========================"<<endl;

    cout << *p << endl;
    increment(p);  // Since we are changing the value at address stored in pointer.
    cout << *p << endl; // it will increment the value.
    cout<<"========================"<<endl;

    int a[10] = {1,2,3,4,5,4,5,4,5,4};
    cout << sizeof(a) << endl;
    cout << "sum of 10 elements : " <<  sum(a, 10) << endl;
    cout << "sum of last 7 elements : " << sum(a+3, 7) << endl;
    cout<<"========================"<<endl;
}

void changeSign(int *p){
    *p = (*p)  *  -1;
}

void fun(int a[]) {
    cout << a[0] << " ";
}

void square(int *p){
    int a = 10;
    p = &a;
    *p = (*p) * (*p);
}

void assignment5(){
    int a = 10;
    changeSign(&a);
    cout << a << endl;  // -10
    cout<<"========================"<<endl;

    int a1[] = {1, 2, 3, 4};
    fun(a1 + 1);
    cout << a1[0] << endl;  // 2 1
    cout<<"========================"<<endl;

    int a2 = 10;
    square(&a2);    
    cout << a2 << endl;
    cout<<"========================"<<endl;
}

//============================
void increment1(int **p){
    p = p+1;
}

void increment2(int **p){
    *p = *p+1;
}

void increment3(int **p){
    **p = **p+1;
}

void problem6(){
    int i=10;
    int *p = &i;
    int **p2 = &p;

    cout << "p2 : " << p2 << endl;
    cout << "address of p : " << &p << endl;
    cout<<"========================"<<endl;

    cout << "address of i : " << &i << endl;
    cout << "p : " << p << endl;
    cout << "p2 : " << *p2 << endl;
    cout<<"========================"<<endl;

    cout << "i : " << i << endl;
    cout << "*p : " << *p << endl;
    cout << "**p : " << **p2 << endl;
    cout<<"========================"<<endl;

    cout << "p2 : " << p2 << endl;
    increment1(p2);
    cout << "p2 : " << p2 << endl;
    cout<<"========================"<<endl;

    cout << "i : " << i << endl;
    increment3(p2);
    cout << "i : " << i << endl;
    cout<<"========================"<<endl;

    cout << "p : " << p << endl;
    increment2(p2);
    cout << "p : " << p << endl;
    cout<<"========================"<<endl;
}

void increment5(int **p){
  (**p)++;
}

void assignment6(){
    int a = 10;
    int *p = &a;
    int **q = &p;
    int b = 20;
    *q = &b;
    (*p)++;
    cout << a << " " << b << endl;
    cout<<"========================"<<endl;

    int a1 = 100;
    int *p1 = &a1;
    int **q1 = &p1;
    int b1 = (**q1)++ + 4;
    cout << a1 << " " << b1 << endl;
    cout<<"========================"<<endl;

    int a2 = 100;
    int *p2 = &a2;
    int **q2 = &p2;
    int b2 = (**q2)++;
    int *r2 = *q2;
    (*r2)++;
    cout << a2 << " " << b2 << endl;
    cout<<"========================"<<endl;

    int num = 10;
    int *ptr = &num;
    increment5(&ptr);
    cout << num << endl;
    cout<<"========================"<<endl;
}

int main(){

    // problem1();
    // assignment1();

    // //pointers arithmetic
    // assignment2();

    // //Arrays and pointer
    // problem2();
    // assignment3();

    //characters and pointers
    // problem3();
    // assignment4();

    //functions and pointers
    // problem5();
    // assignment5();

    //double pointer
    // problem6();
    // assignment6();

    return 0;
}