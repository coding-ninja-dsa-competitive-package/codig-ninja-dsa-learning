#include<iostream>
using namespace std;

void assignment1(){
    int arr[] = {4, 5, 6, 7};
    int *p = (arr + 1);
    cout << *arr + 9 << endl;
}

void assignment2(){
    int numbers[5];
    int * p;
    p = numbers; 
    *p = 10;
    p = &numbers[2]; 
    *p = 20;
    p--; 
    *p = 30;
    p = numbers + 3;
    *p = 40;
    p = numbers;
    *(p+4) = 50;
    for (int n=0; n<5; n++) {
        cout << numbers[n] << ",";
    }
}

void assignment3(){
    char *ptr; 
    char Str[] = "abcdefg";
    ptr = Str;
    ptr += 5;
    cout << ptr;
}

void assignment4(){
    char arr[20];
    int i;
    for(i = 0; i < 10; i++) {
        *(arr + i) = 65 + i;
    }
    *(arr + i) = '\0';
    cout << arr;
}

void swap (char *x, char *y) 
{
  char *t = x;
  x = y;
  y = t;
}

void assignment5(){
    char *x = "geeksquiz";  //warning -  C++ forbids converting a string constant to 'char*'
    char *y = "geeksforgeeks"; //warning -  C++ forbids converting a string constant to 'char*'
    char *t;
    swap(x, y);
    cout<<x << " "<<y;
    t = x;
    x = y;
    y = t; 
    cout<<" "<<x<< " "<<y;
}

void assignment6(){
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;
    cout<<*ptr2<<" ";
    cout<< ptr2 - ptr1;
}

void assignment7(){
    char st[] = "ABCD";
    for(int i = 0; st[i] != '\0'; i++) {
        cout << st[i] << *(st)+i << *(i+st) << i[st];
    }
}


void Q(int z)
{
  z += z;
  cout<<z << " ";
}

void P(int *y) 
{
  int x = *y + 2;
  Q(x);
  *y = x - 1; 
  cout<<x << " ";
}

void assignment8(){
    int x = 5;
    P(&x);
    cout<<x;
}

void assignment9(){
    char st[] = "ABCD";
    for(int i = 0; st[i] != '\0'; i++) {
        cout << st[i] << *(st)+i << *(i+st) << i[st];
    }
}

void assignment10(){
    int ***r, **q, *p, i=8;
    p = &i;
    (*p)++;
    q = &p;
    (**q)++;
    r = &q;
    cout<<*p << " " <<**q << " "<<***r;
}

int f(int x, int *py, int **ppz) {
    int y, z;
    **ppz += 1;
    cout << "x : " << x << endl;
    z = **ppz;
    cout << "z : " << z << endl;
    *py += 2;
    cout << "x : " << x << endl;
    y = *py;
    cout << "y : " << y << endl;
    x += 3;
    cout << "x : " << x << endl;
    return x + y + z;
}

void assignment11(){
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;
    cout << f(c, b, a);
}

int main(){
    //assignment1();

    //assignment2();
    //assignment3();
    //assignment4();
    //assignment5();
    //assignment6();
    assignment7();
    //assignment8();
    //assignment9();
    //assignment10();
    //assignment11();

    return 0;
}