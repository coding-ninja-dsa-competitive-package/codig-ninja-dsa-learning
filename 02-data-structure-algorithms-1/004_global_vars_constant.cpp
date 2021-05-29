 #include<iostream>
using namespace std;

//Macro - before compilation , it will replace the PI with value in the code at all places.
#define PI 3.14

//global variable
int a=10;

void problem1(){
    int r = 10;
    double area = PI * r * r;
    cout << "area : " << area << endl;
    cout<<"========================"<<endl;

    a = 20;
    cout << "a in problem1() : " << a << endl;
    cout<<"========================"<<endl;
}

/**
 *  What is the output of the following program?
 *  Ans : 3
 */
int x=1;
void print(){
    int x = 2;
    {
        int x = 3;
        cout << x << endl;
    }
}
void assignment1(){
    print();
}


/**
 *  What is the output of the following program?
 *  Ans : 16    
 *  -   "MULTIPLY(a, b)" will be replaced by "a*b" in code.
 *      So, MULTIPLY(2+3, 3+5) will be replaced by 2+3*3+5. And according 
 *      to operator precedence, multiply operator (*) has higher precedence 
 *      than plus operator (+). 
 *  -   So, 3*3 will be evaluated first. Hence expression will become : 2+9+5 = 16
 */
#define MULTIPLY(a, b) a*b
void assignment2(){
    // 2+3*3+5 = 16
    cout << MULTIPLY(2+3, 3+5);
}

/**
 *  What is the output of the following program?
 *  Ans : 36
 */
#define SQUARE(x) x*x
void assignment3(){
    // 36/6*6 = 36
    int x = 36 / SQUARE(6);
    cout << x << endl;
}

inline int func2(int a, int b){
    return (a>b) ? a : b;
}

int func3(int a, int b, int c=10){
    return a+b+c;
}

void problem2(){
    int x=30, y=40;
    int max = func2(x, y);
    cout << max << endl;
    cout<<"========================"<<endl;

    int z = func3(x, y);
    cout << z << endl;
    cout<<"========================"<<endl;
}
//==========================

void problem3(){
    //constant int
    const int i = 10;
    int const i2 = 12;

    //constant reference from a non const int 
    int j=22;
    const int &k = j;
    j++;
    cout << k << endl;

    //const reference from a const int
    int const j2=12;
    int const &k2 = j2;

    //reference from a const int
    int const j3 = 123;
    //int & k3 = j3; //can't be done.
    //k3++;
}

//const argument will confirm that pointer will not be changed.
void func4(const int *p){
    p++;
}

void problem4(){
    int const i=10;
    int const *p = &i; // p is a pointer of constant int.
                       // so we can do " p = &i" but can't do (*p)++

    int j = 12;
    int *p3 = &j;
    func4(p3);

    int * const p4 = &j; // p3 is a constant pointer to j.
                        // so we can do (*p3)++ but not p3++
}

void problem5(){
    int i=10;
    int j=20;
    int const *p = &i;
    p = &j; // allowed because p is pointer to const int so p can be changed.

    int * const p2 = &i;
    (*p2)++;
    //p2 = &j; // not allowed p2 is a constant pointer so p2 can't be changed.

    int const * const p3 = &i; 
    //(*p3)++;   // not allowed as p3 is const pointer to const int
    //p3 = &j;
}

int main(){
    
    // cout << "a in main() : " << a << endl;

    // problem1();

    // assignment1();

    // assignment2();

    // assignment3();

    // problem2();

    // problem3();

    // problem4();

    problem5();
    
    return 0;
}