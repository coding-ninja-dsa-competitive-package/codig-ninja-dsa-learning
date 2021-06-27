#include<bits/stdc++.h>

using namespace std;

/**
 *  Crossword Problem
 *  -   CodingNinjas has provided a crossword of 10*10 grid. The grid contains 
 *      '+' or '-' as its cell values. Now, you are also provided with a word 
 *      list that needs to placed accurately in the grid. Cells marked with '-' 
 *      are to be filled with word list.    
 *  -   For example, The following is an example for the input crossword grid and 
 *      the word list.
        +-++++++++
        +-++-+++++
        +-------++
        +-++-+++++
        +-++-+++++
        +-++-+++++
        ++++-+++++
        ++++-+++++
        ++++++++++
        ----------
        CALIFORNIA;NIGERIA;CANADA;TELAVIV
    Output for the given input should be:
        +C++++++++
        +A++T+++++
        +NIGERIA++
        +A++L+++++
        +D++A+++++
        +A++V+++++
        ++++I+++++
        ++++V+++++
        ++++++++++
        CALIFORNIA
 *  Note: We have provided such test cases that there is only one solution for the 
 *  given input.
 *  
 *  Input format:
 *      The first 10 lines of input contain crossword. Each of 10 lines has a 
 *      character array of size 10. Input characters are either '+' or '-'.
 *      The next line of input contains the word list, in which each word is 
 *      separated by ';'. 
 *  Output format:
 *      Print the crossword grid, after placing the words of word list in '-' cells.  
 *  Sample Test Cases:
 *  
 *  Sample Input 1:
        +-++++++++
        +-++-+++++
        +-------++
        +-++-+++++
        +-++-+++++
        +-++-+++++
        ++++-+++++
        ++++-+++++
        ++++++++++
        ----------
        CALIFORNIA;NIGERIA;CANADA;TELAVIV
 *  Sample Output 1:
        +C++++++++
        +A++T+++++
        +NIGERIA++
        +A++L+++++
        +D++A+++++
        +A++V+++++
        ++++I+++++
        ++++V+++++
        ++++++++++
        CALIFORNIA
 */

void print(char arr[][10]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << arr[i][j] ;
        }
        cout << endl;
    }
    cout << endl;
}

bool isValidHorizontal(char arr[][10], string currWord, int x, int y){
    if(currWord.empty()){
        return true;
    }
    if(y >= 10){
        return false;
    }
    if(arr[x][y] == '-' || arr[x][y] == currWord[0]){
        return isValidHorizontal(arr, currWord.substr(1), x, y+1);
    }
    return false;
}

void setHorizontal(char arr[][10], bool updated[], int size, string currWord, int x, int y, int idx){
    if(idx == size){
        return;
    }
    if(arr[x][y] == '-'){
        arr[x][y] = currWord[idx];
        updated[idx] = true;
    }
    setHorizontal(arr, updated, size, currWord, x, y+1, idx+1);
}

void resetHorizontal(char arr[][10], bool updated[], int size, int x, int y, int idx){
    if(idx == size){
        return;
    }
    if(updated[idx]){
        arr[x][y] = '-';
        updated[idx] = false;
    }
    resetHorizontal(arr, updated, size, x, y+1, idx+1);
}

bool isValidVertical(char arr[][10], string currWord, int x, int y){
    if(currWord.empty()){
        return true;
    }
    if(x >= 10){
        return false;
    }
    if(arr[x][y] == '-' || arr[x][y] == currWord[0]){
        return isValidVertical(arr, currWord.substr(1), x+1, y);
    }
    return false;
}

void setVertical(char arr[][10], bool updated[], int size, string currWord, int x, int y, int idx){
    if(idx == size){
        return;
    }
    if(arr[x][y] == '-'){
        arr[x][y] = currWord[idx];
        updated[idx] = true;
    }
    setVertical(arr, updated, size, currWord, x+1, y, idx+1);
}

void resetVertical(char arr[][10], bool updated[], int size, int x, int y, int idx){
    if(idx == size){
        return;
    }
    if(updated[idx]){
        arr[x][y] = '-';
        updated[idx] = false;
    }
    resetVertical(arr, updated, size, x+1, y, idx+1);
}

void crossword(char arr[][10], vector<string>& words, int index){
    if(index == words.size()){
        print(arr);
        return;
    }
    string currWord = words[index];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(arr[i][j] == '-' || arr[i][j] == currWord[0]){
                int wordSize = currWord.length();
                bool pos[10] = {false};
                if(isValidVertical(arr, currWord, i, j)){
                    setVertical(arr, pos, wordSize, currWord, i, j, 0);
                    crossword(arr, words, index+1);
                    resetVertical(arr, pos, wordSize, i, j, 0);
                }
                if(isValidHorizontal(arr, currWord, i, j)){
                    setHorizontal(arr, pos, wordSize, currWord, i, j, 0);
                    crossword(arr, words, index+1);
                    resetHorizontal(arr, pos, wordSize, i, j, 0);
                }
            }
        }
    }
}

int main() {
    char arr[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> arr[i][j];
        }
    }

    string str;
    cin >> str;
    vector<string> words;
    int i=0;
    while(i != -1){
        i = str.find(";");
        words.push_back(str.substr(0, i));
        str = str.substr(i+1);
    }
    crossword(arr, words, 0);

    return 0;
}