#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>

using namespace std;

/**
 *  Dynamic Stack Using Array Implementation - Using templates i.e. generic class
 */
template<typename T>
class StackUsingArray{
    private:
        T *data;
        int nextIndex;
        int capacity;
    public:
        StackUsingArray(){
            data = new T[4];
            nextIndex = 0;
            capacity = 4;
        }

        int size(){
            return nextIndex;
        }

        bool isEmpty(){
            return nextIndex == 0;
        }

        void ensureCapacity(){
            T *newData = new T[2*capacity];
            for(int i=0; i<capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete data;
            data = newData;
        }

        void push(T element){
            if(nextIndex == capacity){
                //cout << "Stack is full." << endl;
                //return;
                ensureCapacity();
            }
            data[nextIndex] = element;
            nextIndex++;
        }

        T pop(){
            if(isEmpty()){
                cout << "Stack is Empty." << endl;
                return 0;
            }
            nextIndex--;
            return data[nextIndex];
        }

        T top(){
            if(isEmpty()){
                cout << "Stack is Empty." << endl;
                return 0;
            }
            return data[nextIndex-1];
        }
};
void problem1(){
    StackUsingArray<int> s;
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    
    cout << s.top() << endl; // 10

    cout << s.pop() << endl;  // 10 , delete 
    cout << s.pop() << endl;   // 10 , delete
    cout << s.pop() << endl;  // 10, delete

    cout << s.size() << endl;  // 2
    cout << s.isEmpty() << endl;  // false - 0
}

/**
 *  Stack Implementation using Linked List
 */
template <typename T>
class Node{
    public:
        T data;
        Node* next;

        Node(T val){
            this->data = val;
            this->next = NULL;
        }
};

template<typename T>
class StackUsingLinkedList{
    Node<T>* head;
    int numOfElems;
    public:
        StackUsingLinkedList(){
            this->head = NULL;
            this->numOfElems = 0;
        }
        void push(T element){
            Node<T>* newNode = new Node<T>(element);
            newNode->next = head;
            head = newNode;
            numOfElems++;
        }
        T pop(){
            if(head == NULL){
                return 0;
            }
            T d = head->data;
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            numOfElems--;
            return d;
        }
        T top(){
            if(head == NULL){
                return 0;
            }
            return head->data;
        }
        int size(){
            return this->numOfElems;
        }
        bool isEmpty(){
            return (size()==0);
        }
};
void problem2(){
    StackUsingLinkedList<int> s;
    s.push(3);
    s.push(12);
    s.push(289);
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
}

/**
 *  Code : Balanced Parenthesis
 *  -   For a given a string expression containing only round brackets or 
 *      parentheses, check if they are balanced or not. Brackets are said 
 *      to be balanced if the bracket which opens last, closes first.
 *  -   You need to return a boolean value indicating whether the expression 
 *      is balanced or not.
 */
bool isBalanced(string expression) 
{
    int len = expression.length();
    stack<char> s;
    for(int i=0; i<len; i++){
        if(expression[i] == '('){
            s.push(expression[i]);
        } else{
            if(s.empty()){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}
void assignment1(){
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false") << endl;
}

/**
 *  Reverse a Stack
 *  -   You have been given two stacks that can store integers as the data. 
 *      Out of the two given stacks, one is populated and the other one is 
 *      empty. You are required to write a function that reverses the populated 
 *      stack using the one which is empty.
 */
void reverseStack(stack<int> &input, stack<int> &extra) {
	if(input.empty()){
        return;
    }
    int temp = input.top();
    input.pop();
    reverseStack(input, extra);
    while(!input.empty()){
        int t = input.top();
        input.pop();
        extra.push(t);
    }
    input.push(temp);
    while(!extra.empty()){
        int t = extra.top();
        extra.pop();
        input.push(t);
    }
}
void assignment2(){
    stack<int> input, extra;
    int size;
    cin >> size;
    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }
    reverseStack(input, extra);
    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}

/**
 *  Check redundant brackets
 *  -   For a given expression in the form of a string, find if there exist 
 *      any redundant brackets or not. It is given that the expression contains 
 *      only rounded brackets or parenthesis and the input expression will 
 *      always be balanced.
 *  -   A pair of the bracket is said to be redundant when a sub-expression is 
 *      surrounded by unnecessary or needless brackets.
 */
bool checkRedundantBrackets(string expression) {
	stack<char> s;
    for(int i=0; i<expression.length() ; i++){
        if(expression[i] != ')'){
            s.push(expression[i]);
        } else {
            int count=0;
            while(s.top() != '('){
                count++;
                s.pop();
            }
            if(count<=1){
                return true;
            }
            s.pop();
        }
    }
    return false;
}
void assignment3(){
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}

/**
 *  Stock Span
 *  -   Afzal has been working with an organization called 'Money Traders' 
 *      for the past few years. The organization is into the money trading 
 *      business. His manager assigned him a task. For a given array/list 
 *      of stock's prices for N days, find the stock's span for each day.
 *  -   The span of the stock's price today is defined as the maximum number 
 *      of consecutive days(starting from today and going backwards) for which 
 *      the price of the stock was less than today's price.
 *  -   For example, if the price of a stock over a period of 7 days are 
 *      [100, 80, 60, 70, 60, 75, 85], then the stock spans will be 
 *      [1, 1, 1, 2, 1, 4, 6].
 */
int* stockSpan(int *price, int size)  {
    stack<int> s;
    int count;
    int* res = new int[size];
    for(int i=0; i<size; i++){
        if(s.empty()){
            res[i] = 1;
            s.push(i);
        } else {
            if(price[i] > price[s.top()]){
                count = 1;
            	while(!s.empty() && price[i] > price[s.top()]){
                    count = count+res[s.top()];
                    s.pop();
                }
                res[i] = count;
                s.push(i);
            } else {
                res[i] = i-(s.top());
                s.push(i);
            }
        }
    }
    return res;
}
void assignment4(){
    int size;
    cin >> size;
    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    delete[] input;
    delete[] output;
}

/**
 *  Minimum bracket Reversal
 *  -   For a given expression in the form of a string, find the minimum 
 *      number of brackets that can be reversed in order to make the expression 
 *      balanced. The expression will only contain curly brackets.
 *  -   If the expression can't be balanced, return -1.
 */
int countBracketReversals(string input) {
    if(input.size() % 2 != 0){
        return -1;
    }
    stack<char> s;
    int count=0;
	for(int i=0; i<input.length() ; i++){
        if(input[i] == '{'){
            s.push('{');
        } else {
            if(s.empty()){
                count++;
                s.push('{');
            } else{
                s.pop();
            }
        }
    }
    if(!s.empty()){
        count += s.size()/2;
    }
    return count;
}
void assignment5(){
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}

int main() {
    //Stack using array
    //problem1();

    //Stack using Linked List
    //problem2();

    //balanced brackets
    //assignment1();

    //reverse stack
    //assignment2();

    //Check redundant brackets
    //assignment3();

    //Stock Span
    //assignment4();

    //Minimum bracket Reversal
    assignment5();

    return 0;
}