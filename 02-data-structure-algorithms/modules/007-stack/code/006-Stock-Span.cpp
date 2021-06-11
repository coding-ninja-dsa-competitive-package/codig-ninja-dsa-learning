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
 * 
 *  Input Format:
 *      The first line of input contains an integer N, denoting the total number of days.
 *      The second line of input contains the stock prices of each day. A single space 
 *      will separate them.
 *  Output Format:
 *      The only line of output will print the span for each day's stock price. A 
 *      single space will separate them.
 * 
 *  Constraints:
 *      0 <= N <= 10^7
 *      1 <= X <= 10^9
 *      Where X denotes the stock's price for a day.
 *  
 *  Time Limit: 1 second
 * 
 *  Sample Input 1:
 *      4
 *      10 10 10 10
 *  Sample Output 1:
 *      1 1 1 1 
 * 
 *  Sample Input 2:
 *      8
 *      60 70 80 100 90 75 80 120
 *  Sample Output 2:
 *      1 2 3 4 1 1 2 8 
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

int main(){
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