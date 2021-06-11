#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

/**
 *  Queue implementation using array
 */
template <typename T>
class QueueUsingArray{
    T *data;
    int size;
    int capacity;
    int nextIndex;
    int firstIndex;

    public:
        QueueUsingArray(){
            data = new int[4];
            size=0;
            capacity=4;
            firstIndex=-1;
            nextIndex=0;
        }

        void ensureCapacity(){
            T *newData = new T[2*capacity];
            int k=0;
            for(int i=firstIndex; i<capacity; i++){
                newData[k++] = data[i];
            }
            for(int i=0; i<firstIndex; i++){
                newData[k++] = data[i];
            }
            delete data;
            data = newData;
            firstIndex =0;
            nextIndex = capacity;
            capacity *= 2;
        }

        void enqueue(T element){
            if(size == capacity){
                ensureCapacity();
                //cout << "Queue is full." << endl;
                //return;
            }
            data[nextIndex] = element;
            nextIndex = (nextIndex+1) % capacity;
            size++;
            if(firstIndex == -1){
                firstIndex = 0;
            }
        }

        T dequeue(){
            if(size == 0){
                cout << " Queue is empty." << endl;
                return -1;
            }
            T temp =  data[firstIndex];
            firstIndex = (firstIndex + 1) % capacity;
            size--;
            if(size==0){
                firstIndex=-1;
                nextIndex=0;
            }
            return temp;
        }

        T front(){
            if(size == 0){
                cout << " Queue is empty." << endl;
                return -1;
            }
            return data[firstIndex];
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size==0;
        }
};

int main(){
    QueueUsingArray<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(45);
    //q.enqueue(4); // queue is full
    q.enqueue(4);

    cout << q.dequeue() << endl;  // 10
    cout << q.front() << endl; // 20
    cout << q.getSize() << endl; // 4
    cout << q.isEmpty() << endl; //0
    q.enqueue(23);
    cout << q.getSize() << endl; // 5
}