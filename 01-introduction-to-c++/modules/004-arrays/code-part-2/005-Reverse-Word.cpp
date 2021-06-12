#include<iostream>

using namespace std;

/**
 *  Reverse Word Wise:
 *  ->  Reverse the given string word wise. That is, the last word in given string should 
 *      come at 1st place, last second word at 2nd place and so on. Individual words should
 *      remain as it is.
 */
int length(char input[]){
    int count = 0; 
    for(int i=0; input[i] != '\0'; i++){
        count++;
    }
    return count;
}
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
int main(){
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}