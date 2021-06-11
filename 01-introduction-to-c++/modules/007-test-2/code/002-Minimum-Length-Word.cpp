#include<iostream>

using namespace std;

/**
 *  Minimum Length Word
 *  -   Given a string S (that can contain multiple words), you need to 
 *      find the word which has minimum length.
 *  Note : If multiple words are of same length, then answer will be first 
 *      minimum length word in the string.
 *      Words are seperated by single space only.
 * 
 *  Input Format :
 *      String S
 *  Output Format :
 *      Minimum length word
 *  Constraints :
 *      1 <= Length of String S <= 10^5
 * 
 *  Sample Input 1 :
 *      this is test string
 *  Sample Output 1 :
 *      is
 *  
 *  Sample Input 2 :
 *      abc de ghihjk a uvw h j
 *  Sample Output 2 :
 *      a
 */
void minLengthWord(char input[], char output[]){
	int i, j=0, min = INT_MAX;
    while(input[j] != '\0'){
        i = j;
        while(input[j] != ' ' && input[j] != '\0'){
        	j++;
    	}
        if(min > j-i){
            min = j-i;
            int k;
            for(k=0; k<min; k++){
                output[k] = input[i];
                i++;
            }
            output[k] ='\0';
        }
        j++;
    }
}

int main(){
    char ch[10000], output[10000];
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << output << endl;
}