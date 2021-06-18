#include<iostream>

using namespace std;

void basics(){
    int i=65;
    char c = i;  // implicit typecasting
    cout << c << endl;

    int *p = &i;
    char *pc = (char*)p;  //explicit typecastings

    cout << *p << endl;         // 65
    cout << *pc << endl;        // A  - integer is stored in reverse order i.e. least significant bytes
    cout << *(pc+1) << endl;    // nullpoiinter
    cout << *(pc+2) << endl;    // nullpoiinter
    cout << *(pc+3) << endl;    // nullpoiinter
}

/**
 *  Void pointer can be of which type :
 *  1.  int
 *  2.  double 
 *  3.  float 
 *  4.  all
 *  Ans : 4(all)
 */

/**
 *  What is the output
 *  Ans : A
 */
void problem1(){
    int d = 65;
    int i = d;
    char ch = i;
    cout << ch << endl;
}

/**
 *  What is the output
 *  Ans : d
 */
void updateValue(int *p){
    *p = 610 % 255;
}
void problem2(){
    char ch = 'A';
    updateValue((int*)&ch);
    cout << ch;
}

int main() {
    
    basics();
    problem1();
    problem2();

    return 0;
}