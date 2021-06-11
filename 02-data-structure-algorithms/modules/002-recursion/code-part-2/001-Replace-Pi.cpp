#include<iostream>

using namespace std;

/**
 *  Replace pi (recursive)
 *  -   Given a string, compute recursively a new string where all 
 *      appearances of "pi" have been replaced by "3.14".
 * 
 *  Sample Input 1 :
 *      xpix
 *  Sample Output :
 *      x3.14x
 * 
 *  Sample Input 2 :
 *      pipi
 *  Sample Output :
 *      3.143.14
 *  
 *  Sample Input 3 :
 *      pip
 *  Sample Output :
 *      3.14p
 */
// Approach 1
void replacePi(char input[]) {
	if(input[0] == '\0'){
        return;
    }
    replacePi(input+1);
    int len = strlen(input);
    if(input[0] == 'p' && input[1] == 'i'){
        for(int i=len+1; i>3; i--){
            input[i] = input[i-2];
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }
}
// Approach 2
string replacePiV2(string input) {
	if(input.empty()){
        return "";
    }
    string res = replacePiV2(input.substr(1));
    if(input[0] == 'p' && res[0] == 'i'){
        return "3.14" + res.substr(1);
    }
    return input[0]+res;
}

int main(){
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}