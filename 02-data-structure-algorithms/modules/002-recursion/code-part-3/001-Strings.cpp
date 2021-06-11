#include<iostream>
using namespace std;

void problem1(){
    string *sp = new string;
    *sp = "def";
    cout << sp << endl;  // memory address - 0x1496067f0
    cout << *sp << endl; // def
    cout<<"========================"<<endl;

    string s= "abc";
    getline(cin, s);
    cout << s << endl; // whatever string is given as input
    cout<<"========================"<<endl;

    s = "defdef";
    cout << s[0] << endl; // d
    s[0] = 'a';
    string s1;
    s1= "nnb";

    string s2 = s + s1; 
    cout << s << endl; // aefdef
    cout << s1 << endl;  // nnb
    cout << s2 << endl;  // aefdefnnb
    cout<<"========================"<<endl;

    string s4 = "hshhudshs";
    cout << s4.size() << endl;  // 9
    cout << s4.substr(3) << endl;  // hudshs
    cout << s4.substr(3,4) << endl; // huds (starts with index 3 , length of 4)
    cout << s4.find("hh") << endl;  //  2 (index where string is found)
    cout<<"========================"<<endl;
}