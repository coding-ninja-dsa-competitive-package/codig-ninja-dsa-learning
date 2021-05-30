#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/**
 *  Default priority queue usage present in queue.h
 */
void problem1(){
    // max priority queue
    priority_queue<int> pq;
    // min priority queue
    priority_queue<int, vector<int>, greater<int> > min_pq;

    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);    
    cout << "Size : " << pq.size() << endl;
    cout << "Top : " << pq.top() << endl;
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

/**
 *  K-sorted Array
 *  -   If it takes only less than k moves to place element in its correct position.
 *  -   i.e. element can move k-1 in left or in right for its correct position.
 * 
 *  Sort the k-sorted array in decreasing order. 
 *  Input :     12 15 7 4 9 
 *  Output :    15 12 9 7 4
 * 
 *  Time Complexity : 
 *      T(n)  =  klogk + 2(n-k)logk + klogk
 *            =  2nlogk 
 *            =  O(n)  , if k is very small.
 */
void kSortedArray(int arr[], int n, int k){
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    int j=0;
    for(int i=k ; i<n; i++){
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }
    while (!pq.empty()){
        arr[j++] = pq.top();
        pq.pop();
    }
}
void problem2(){
    int n;
    cin >> n;
    int arr[1000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    kSortedArray(arr, n, k);
    for(int i=0; i<n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 *  Code : K smallest Elements
 *  -   You are given with an integer k and an array of integers that 
 *      contain numbers in random order. Write a program to find k smallest 
 *      numbers from given array. You need to save them in an array and return it.
 *  -   Time complexity should be O(n * logk) and space complexity should not 
 *      be more than O(k).
 *  -   Note: Order of elements in the output is not important.
 */
vector<int> kSmallest(int arr[], int n, int k) {
    priority_queue<int> pq;
    vector<int> res;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    for(int i=k; i<n; i++){
        int max = pq.top();
        if(arr[i] < max){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
void problem3(){
    int size;
    cin >> size;
    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }
    int k;
    cin >> k;
    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    delete[] input;
}

/**
 *  Code : K largest elements
 *  -   You are given with an integer k and an array of integers that 
 *      contain numbers in random order. Write a program to find k largest 
 *      numbers from given array. You need to save them in an array and return it.
 *  -   Time complexity should be O(nlogk) and space complexity should 
 *      be not more than O(k).
 */
vector<int> kLargest(int input[], int n, int k){
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> res;
    for(int i=0; i<k ; i++){
        pq.push(input[i]);
    }
    for(int i=k; i<n; i++){
        int min = pq.top();
        if(input[i] > min){
            pq.pop();
            pq.push(input[i]);
        }
    }
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
void problem4(){
    int size;
	cin >> size;
	int *input = new int[1 + size];
	for(int i = 0; i < size; i++)
		cin >> input[i];
    int k;
    cin >> k;
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
}

/**
 *  Check Max-Heap
 *  -   Given an array of integers, check whether it represents max-heap 
 *      or not. Return true if the given array represents max-heap, else 
 *      return false.
 */
bool isMaxHeap(int arr[], int n) {
    for(int i=1; i<n; i++){
        int child = arr[i];
        int parent = arr[(i-1)/2];
        if(parent<child){
            return false;
        }
    }
    return true;
}
void assignment1(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");
    delete[] arr;
}

/**
 *  Kth largest element
 *  -   Given an array A of random integers and an integer k, find and 
 *      return the kth largest element in the array.
 *  -   Note: Try to do this question in less than O(N * logN) time.
 */
int kthLargest(int* arr, int n, int k) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<k ; i++){
        pq.push(arr[i]);
    }
    for(int i=k; i<n; i++){
        int min = pq.top();
        if(arr[i] > min){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
void assignment2(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << kthLargest(arr, n, k);
    delete[] arr;
}

/**
 *  Merge K sorted arrays
 *  -   Given k different arrays, which are sorted individually (in 
 *      ascending order). You need to merge all the given arrays such 
 *      that output array should be sorted (in ascending order).
 *  -   Hint : Use Heaps.
 */
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
   	priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<input.size(); i++){
        vector<int>* arr = input.at(i);
        for(int j=0; j<arr->size(); j++){
            pq.push(arr->at(j));
        }
    }
    vector<int> res;
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
void assignment3(){
    int k;
    cin >> k;
    vector<vector<int> *> input;
    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }
        input.push_back(current);
    }
    vector<int> output = mergeKSortedArrays(input);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
}

/**
 *  Running Median
 *  -   You are given a stream of N integers. For every i-th integer added 
 *      to the running list of integers, print the resulting median.
 *  -   Print only the integer part of the median.
 */
#include<cmath>
void printRunningMedian(int *arr, int n) {
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int> > min_pq;
    for(int i=0; i<n; i++){
        if(min_pq.empty() && max_pq.empty()){
            max_pq.push(arr[i]);
        } else if(!max_pq.empty() && arr[i] < max_pq.top()){
            max_pq.push(arr[i]);
        } else{
            min_pq.push(arr[i]);
        }
        
        if(abs(max_pq.size() - min_pq.size() > 1)){
            if(max_pq.size() > min_pq.size()){
                min_pq.push(max_pq.top());
                max_pq.pop();
            } else {
                max_pq.push(min_pq.top());
                min_pq.pop();
            }
        }
        
        if(max_pq.size() > min_pq.size()){
            cout << max_pq.top() << " ";
        } else if(max_pq.size() < min_pq.size()){
            cout << min_pq.top() << " ";
        } else {
            int median = (max_pq.top() + min_pq.top())/2;
            cout << median << " ";
        }
    }
}


void assignment4(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    printRunningMedian(arr, n);
    delete[] arr;
}

/**
 *  Buy the ticket
 *  -   You want to buy a ticket for a well-known concert which is happening in 
 *      your city. But the number of tickets available is limited. Hence the 
 *      sponsors of the concert decided to sell tickets to customers based on 
 *      some priority.
 *  -   A queue is maintained for buying the tickets and every person is attached 
 *      with a priority (an integer, 1 being the lowest priority).
 *  -   The tickets are sold in the following manner -
 *      1.  The first person (pi) in the queue requests for the ticket.
 *      2.  If there is another person present in the queue who has higher priority 
 *          than pi, then ask pi to move at end of the queue without giving him the 
 *          ticket.
 *      3.  Otherwise, give him the ticket (and don't make him stand in queue again).
 *  -   Giving a ticket to a person takes exactly 1 minute and it takes no time for 
 *      removing and adding a person to the queue. And you can assume that no new 
 *      person joins the queue.
 *  -   Given a list of priorities of N persons standing in the queue and the index 
 *      of your priority (indexing starts from 0). Find and return the time it will 
 *      take until you get the ticket.
 *  Input : 
 *          3
 *          3 9 4
 *          2
 *  Output :    2
 */
void leftRotateByOne(int* arr, int n){
    int temp = arr[0];
    for(int i=0; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}
int buyTicket(int *arr, int n, int k) {
    priority_queue<int> pq;
    for(int i=0 ; i<n; i++){
        pq.push(arr[i]);
    }
    int time = 0;
    int size = n;
    while(true){
        if(pq.top() == arr[0] && k==0){
            time++;
            break;
        } else if (pq.top() == arr[0] && k != 0){
            time++;
            pq.pop();
            leftRotateByOne(arr, size);
            size--;
            k--;
        } else if(pq.top() != arr[0] && k == 0){
            leftRotateByOne(arr, size);
            k = size-1;
        } else{
            leftRotateByOne(arr, size);
            k--;
        }
    }
    return time;
}
void assignment5(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << buyTicket(arr, n, k);
    delete[] arr;
}

int main() {
    // default priority queue - max/min priority queue
    // problem1();

    // Sort the k-sorted array
    // problem2();

    // Code : K smallest Elements
    // problem3();

    // Code : K largest elements
    // problem4();

    // Check Max-Heap
    // assignment1();

    // Kth largest element
    // assignment2();

    // merge k sorted arrays
    // assignment3();

    // Running Median
    assignment4();

    // Buy the ticket
    // assignment5();

    return 0;
}