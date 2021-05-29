#include<iostream>
#include<cstring>
using namespace std;

/**
 *  Print All Substrings
 *  ->  For a given input string(str), write a function to print all the possible substrings. 
 */
void problem1(char input[]){
    int len = strlen(input);
    for(int i=0; i<len; i++){
        for(int j=i; j<len; j++){
            int k=i;
            while(k <= j){
                cout << input[k];
                k++;
            }
            cout << endl;
        }
    }
}

int main(){
    //length
    char ch1[] = "Tarun is here";
    cout << "length of the input string is : " << strlen(ch1) << endl;
    cout << "========================" << endl;

    //string compare
    char ch2[] = "Tarun";
    char ch3[] = "Tarun1";
    cout << "result of string compare : " << strcmp(ch2, ch3) << endl;
    cout << "========================" << endl;

    //string copy
    char ch4[100];
    char ch5[] = "Tarun1";
    strcpy(ch4, ch5);
    cout << "string ch4 : " << ch4 << endl;
    cout << "========================" << endl;

    //string copy
    char ch6[100] = "Varun";
    char ch7[] = "Tarun1";
    strncpy(ch6, ch7, 3);
    cout << "string ch6 : " << ch6 << endl;
    cout << "========================" << endl;

    char ch8[] = "Tarun";
    problem1(ch8);
    cout << "========================" << endl;

    return 0;
}