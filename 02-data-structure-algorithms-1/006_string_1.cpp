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

/**
 *  All subsequences of a string
 */
int subsequences(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    int smallOutputSize = subsequences(input.substr(1), output);
    for(int i=0; i<smallOutputSize; i++){
        output[i+smallOutputSize] = input[0] + output[i];
    }
    return 2*smallOutputSize;
}
void print_subs(string input, string output){
    if(input.empty()){
        cout << output << endl;
        return;
    }
    print_subs(input.substr(1), output);
    print_subs(input.substr(1), output+input[0]);
}
void problem2(){
    string input;
    cin >> input;
    string *output = new string[1000];
    int count = subsequences(input, output);
    for(int i=0; i<count; i++){
        cout << output[i] << endl;
    }
    cout<<"========================"<<endl;
    string out="";
    print_subs(input, out);
    cout<<"========================"<<endl;
}

/**
 *  Return Keypad Code
 *  -   Given an integer n, using phone keypad find out all the possible 
 *      strings that can be made using digits of input n. Return empty string 
 *      for numbers 0 and 1.
 *  Note : 
 *      1. The order of strings are not important.
 *      2. Input and output has already been managed for you. 
 */
int keypad(int num, string output[]){
    if(num == 0 || num == 1){
        output[0] = "";
        return 1;
    }
    int smallerOutputSize = keypad(num/10, output);
    string arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string str = arr[num%10];
    for(int i=0; i<smallerOutputSize ; i++){
        string out = output[i];
        for(int j=0; j<str.size(); j++){
            output[i + (j*smallerOutputSize)] =  out+str[j]; 
        }
    }
    return smallerOutputSize*str.size();
}
void problem3(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << " ";
    }
}

/**
 *  Print Keypad Combinations Code
 *  -   Given an integer n, using phone keypad find out and print all the 
 *      possible strings that can be made using digits of input n.
 *  -   Note : The order of strings are not important. Just print different 
 *      strings in new lines.
 */
void print_keypad(int num, string output){
    if(num == 0){
        cout << output << endl;
        return;
    }
    string arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string str = arr[num%10];
    for(int i=0; i<str.size(); i++){
        print_keypad(num/10, str[i]+output);
    }
}
void printKeypad(int num){
	string out;
    print_keypad(num, out);
}
void problem4(){
    int num;
    cin >> num;
    printKeypad(num);
}

int main(){
    // basics of string data type
    // problem1();

    // subsequences of a string
    // problem2();

    // keypad subsequences combination
    // problem3();

    // Print Keypad Combinations Code
    problem4();

    return 0;
}