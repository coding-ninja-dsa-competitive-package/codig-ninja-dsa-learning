#include<iostream>
using namespace std;

void updateValue(int *p){
    *p = 610 % 255;
}

//typecasting
void problem1(){
    int i=65;
    char c=i;
    cout << "c : " << c << endl; // A
    cout<<"========================"<<endl;

    int *p = &i;
    char *pc = (char*)p;
    cout << "p : " << p << endl;  //memory address
    cout << "pc : " << pc << endl; // A
    cout<<"========================"<<endl;

    cout << "*p : " << *p << endl; // 65
    cout << "*pc : " << *pc << endl; // A
    cout << "*(pc+1) : " << *(pc+1) << endl;
    cout << "*(pc+2) : " << *(pc+2) << endl;
    cout << "*(pc+3) : " << *(pc+3) << endl;
    cout<<"========================"<<endl;

    char ch = 'A';
    updateValue((int*)&ch);
    cout << ch << endl; //d
    cout<<"========================"<<endl;
}

int main(){
    //TypeCasting 
    problem1();
    
    return 0;
}