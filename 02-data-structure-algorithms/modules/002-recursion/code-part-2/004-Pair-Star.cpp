#include<iostream>

using namespace std;

/**
 *  Pair Star
 *  -   Given a string S, compute recursively a new string where identical 
 *      chars that are adjacent in the original string are separated from 
 *      each other by a "*".
 *  
 *  Input format :
 *      String S
 *  Output format :
 *      Modified string
 *  Constraints :
 *      0 <= |S| <= 1000
 *      where |S| represents length of string S.
 *  
 *  Sample Input 1 :
 *      hello
 *  Sample Output 1:
 *      hel*lo
 *  
 *  Sample Input 2 :
 *      aaaa
 *  Sample Output 2 :
 *      a*a*a*a
 */
void pairStar(char input[]) {
    if(input[0] == '\0'){
        return;
    }
    pairStar(input+1);
    if(input[0] == input[1]){
        int len = strlen(input);
        input[len+1] ='\0';
        int i;
        for( i=len;i>1; i--){
            input[i] = input[i-1];
        }
        input[i] = '*';
    }
}

int main(){
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
}