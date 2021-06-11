#include<iostream>
#include<cstring>
using namespace std;

/**
 *  1-D Char array - String
 */
void problem1(){
    // char name[100];
    // cout << "Enter your name : ";
    // cin >> name;
    // cout << "Name : " << name << endl;
    // name[4] = 'x';
    // cout << "Name : " << name << endl;
    // name[3] = 'd' ;
    // cout << "Name : " << name << endl;
    // name[1] = '\0';
    // cout << "Name : " << name << endl;
    // cout << "======================" << endl;

    char str[100];
    // cin.getline(str, 100);
    // cout << "output string : "<<str << endl;
    // cout << "======================" << endl;
    //delimiter
    cin.getline(str, 100, '9');
    cout << "output string : "<<str << endl;
    cout << "======================" << endl;
}

/**
 *  length of string
 */
int length(char input[]){
    int count = 0; 
    for(int i=0; input[i] != '\0'; i++){
        count++;
    }
    return count;
}

/**
 *  Check Palindrome
 *  ->  Given a string, determine if it is a palindrome, considering only alphanumeric characters.
 *  ->  A palindrome is a word, number, phrase, or other sequences of characters which read the 
 *      same backwards and forwards.
 */
bool checkPalindrome(char str[]) {
    int len = length(str);
    int start, end = len-1;
    for(start=0 ; start<end; start++, end--){
        if(str[start] != str[end]){
            return false;
        }
    }
    return true;
}
void problem2(){
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}

/**
 *  Replace Character
 *  ->  Given an input string S and two characters c1 and c2, you need to replace every occurrence 
 *      of character c1 with character c2 in the given string.
 */
void replaceCharacter(char input[], char c1, char c2) {
    int len = length(input), i=0;
    while(input[i] != '\0'){
        if(input[i] == c1){
            input[i] = c2;
        }
        i++;
    }
}
void problem3(){
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
}

/** 
 *  Trim Spaces
 *  ->  Given an input string S that contains multiple words, you need to 
 *      remove all the spaces present in the input string.
 */
void trimSpaces(char str[]) {
	int len = length(str), i=0 , j=0;
    while(str[j] != '\0'){
        if(str[j] != ' ' && str[i] != ' '){
            i++;
            j++;
        } else if(str[j] == ' ' && str[i] == ' '){
            j++;
        } else if(str[i] == ' ' && str[j] != ' '){
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        } else if (str[i] != ' ' && str[j] == ' '){
            i++;
            j++;
        }
    }
}
void problem4(){
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}

/**
 *  Reverse Word Wise:
 *  ->  Reverse the given string word wise. That is, the last word in given string should 
 *      come at 1st place, last second word at 2nd place and so on. Individual words should
 *      remain as it is.
 */
void reverse(char *str, int i, int j){
    while(i < j){
        char ch=str[i];
        str[i] = str[j];
        str[j] = ch;
        i++;
        j--;
    }
}
void reverseStringWordWise(char input[]) {
	int len = length(input);
    reverse(input, 0 , len-1);
    int i=0;
    int start, end;
    while(input[i] != '\0'){
		start=i;
        while(input[i] != ' ' && input[i] != '\0'){
            i++;
        }
        end = i-1;
        reverse(input, start, end);
        i++;
    }
}
void problem5(){
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}

int main(){
    // 1-D Char array - String
    // problem1();

    // Length of String
    // char name[10]="Tarun";
    // cout << length(name) << endl;

    // Check Palindrome
    // problem2(name);

    // Replace Character
    // problem3();

    // Trim Spaces
    // problem4();

    // Reverse Word Wise
    // problem5();

    return 0;
}
