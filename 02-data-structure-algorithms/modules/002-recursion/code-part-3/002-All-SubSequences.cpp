#include<iostream>

using namespace std;

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

int main(){
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