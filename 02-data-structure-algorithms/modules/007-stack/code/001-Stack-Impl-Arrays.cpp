#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

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

int main(){
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

    return 0;
}