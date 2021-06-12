#include<iostream>
#include<cstring>
using namespace std;

/**
 *  1-D Char array - String
 */
int main(){
    char name[100];
    cout << "Enter your name : ";
    cin >> name;
    cout << "Name : " << name << endl;
    name[4] = 'x';
    cout << "Name : " << name << endl;
    name[3] = 'd' ;
    cout << "Name : " << name << endl;
    name[1] = '\0';
    cout << "Name : " << name << endl;
    cout << "======================" << endl;

    char str[100];
    cin.getline(str, 100);
    cout << "output string : "<<str << endl;
    cout << "======================" << endl;
    // delimiter
    cin.getline(str, 100, '9');
    cout << "output string : "<<str << endl;
    cout << "======================" << endl;
}