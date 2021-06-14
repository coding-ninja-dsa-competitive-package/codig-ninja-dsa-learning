#include<iostream>

using namespace std;

/**
 *  Quadruplet Sum
 *  -   Given an array nums of n integers and integer x, return an array of all 
 *      the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *          0 <= a, b, c, d < n
 *          a, b, c, and d are distinct.
 *          nums[a] + nums[b] + nums[c] + nums[d] == x
 *  -   Store all such possible quadruplets in an 2D array, and return it. The 
 *      order of the quadruplets does not matter.
 *  
 *  Input Format:
 *      First line of input contains an integer n, representing the size of the array.
 *      Second line of input contains n space separated integers.
 *      Third line of input contains an integer x.
 *  
 *  Constraints:
 *      1 <= nums.length <= 200
 *      -10^9 <= nums[i] <= 10^9
 *      -10^9 <= target <= 10^9
 *  
 *  Output Format:
 *      Return all possible quadruplets
 *  
 *  Sample Input 1:
 *      6
 *      1 0 -1 0 -2 2 
 *      0
 *  Sample Output1:
 *      -2 -1 1 2   
 *      -2 0 0 2
 *      -1 0 0 1
 */
#include<vector>

vector<vector<int> > quadruplets(vector<int>& nums, int target) {

}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int x;
    cin >> x;
	vector<vector<int> > answer = quadruplets(arr, x);
    for (int p = 0; p < answer.size(); p++){
        for (int q = 0; q < 4; q++){
            cout << answer[p][q] << " ";
        }
        cout << endl;
    }
    
}