#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

/**
 *  The recurrence relation capturing the optimal execution time of the 
 *  Towers of Hanoi problem with n discs is :
 *  1.  T(n) = 2T(n − 2) + 2
 *  2.  T(n) = 2T(n − 1) + n
 *  3.  T(n) = 2T(n/2) + 1
 *  4.  T(n) = 2T(n − 1) + 1       -- correct
 */

/**
 *  Complexity of different operations in a sorted array.
 *  Which of the following operations is not O(1) for an array of sorted 
 *  data. You may assume that array elements are distinct.
 *  1.  Find the ith largest element.
 *  2.  Delete an element          -- correct
 *  3.  Find the ith smallest element
 *  4.  All of the above
 */

/**
 *  Complexity of a Recurrence Relation
 *  Which one of the following correctly determines the solution of the recurrence 
 *  relation with T(1) = 1?
 *  1.  O(N)        -- correct
 *  2.  O(NlogN)
 *  3.  O(N^2)
 *  4.  O(logN)
 */

/**
 *  Does s contain t ?
 *  -   Given two string s and t, write a function to check if s contains all 
 *      characters of t (in the same order as they are in string t).
 *  -   Return true or false.
 *  -   Do it recursively.
 *      E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of 
 *             t=”coding” in the same order. So function will return true.
 */
bool checksequenece(char large[] , char*small) {
	if(small[0] == '\0'){
        return true;
    }
    if(large[0] == '\0'){
        return false;
    }
    if(large[0] == small[0]){
        return checksequenece(large+1, small+1);
    } else {
        return checksequenece(large+1, small);
    }
}
void problem1()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";
}

/**
 *  Maximum Profit on App
 *  -   You have made a smartphone app and want to set its subscription price 
 *      such that the profit earned is maximized. There are certain users who   
 *      will subscribe to your app only if their budget is greater than or equal 
 *      to your price.
 *  -   You will be provided with a list of size N having budgets of subscribers 
 *      and you need to return the maximum profit that you can earn.
 *  -   Lets say you decide that price of your app is Rs. x and there are N number 
 *      of subscribers. So maximum profit you can earn is :
 *           m * x
 *      where m is total number of subs whose budget is greater than or equal to x.
 *  -   Smaple Input : 
 *          4
 *          30 20 53 14
 *      Sample Output:
 *          60
 */
#include<algorithm>
int maximumProfit(int budget[], int n) {
    sort(budget, budget+n);
    int max=0;
    int len = n;
    for(int i=0; i<n; i++){
        if(max < budget[i]*len){
            max = budget[i]*len;
        }
        len -= 1;
    }
    return max;
}
void problem2(){
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    cout << maximumProfit(input, n) << endl;
}

/**
 *  Split Array
 *  -   Given an integer array A of size N, check if the input array can be splitted 
 *      in two parts such that -
 *      -   Sum of both parts is equal
 *      -   All elements in the input, which are divisible by 5 should be in same group.
 *      -   All elements in the input, which are divisible by 3 (but not divisible by 5) 
 *          should be in other group.
 *      -   Elements which are neither divisible by 5 nor by 3, can be put in any group.
 *  -   Groups can be made with any set of elements, i.e. elements need not to be 
 *      continuous. And you need to consider each and every element of input array 
 *      in some group.
 *  -   Return true, if array can be split according to the above rules, else return false.
 */ 
bool isSplitPossible(int *arr, int n, int start, int sumFive, int sumThree){
    if(start == n){
        return (sumFive == sumThree);
    }
    if(arr[start]%5 == 0){
        sumFive += arr[start];
    } else if(arr[start]%3 == 0){
        sumThree += arr[start];
    } else {
        bool ans1 = isSplitPossible(arr, n, start+1, sumFive+arr[start], sumThree);
        bool ans2 = isSplitPossible(arr, n, start+1, sumFive, sumThree+arr[start]);
        return ans1 || ans2;
    }
    return isSplitPossible(arr, n, start+1, sumFive, sumThree);
}

bool splitArray(int *input, int size) {
	return isSplitPossible(input, size, 0, 0, 0);
}

void problem3(){
    int size;
	cin>>size;
	int *input=new int[1+size];	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

int main() {
    
    //problem1();

    problem2();

    //problem3();

    return 0;
}