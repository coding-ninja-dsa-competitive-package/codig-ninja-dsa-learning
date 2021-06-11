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
    char ch8[] = "Tarun";
    problem1(ch8);
}