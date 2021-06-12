#include<iostream>

using namespace std;

/** 
 *  Trim Spaces
 *  -   Given an input string S that contains multiple words, you need to 
 *      remove all the spaces present in the input string.
 *  -   There can be multiple spaces present after any word.
 *  
 *  Input Format :
 *      String S
 *  Output Format :
 *      Updated string
 *  
 *  Constraints :
 *      1 <= Length of string S <= 10^6
 *  
 *  Sample Input :
 *      abc def g hi
 *  Sample Output :
 *      abcdefghi
 */
int length(char str[]){
    int count=0, i=0;
    while(str[i] != '\0'){
        count++;
        i++;
    }
    return count;
}
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