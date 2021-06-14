/**
 *  Jumping Ninja
 *  -   Given the heights of N valleys arranged in consecutive manner and an 
 *      integer M. In one step, Ninja can jump from valley i to valley
 *      1.  i + j where, i + j < number of valleys and 0 < j <= M
 *      2.  i - j where, i - j >= 0 and 0 < j <= M
 *  -   Also, you are allowed to jump from valley i to valley j if 
 *      height[i] > height[j] and height[i] > height[k] for valleys k between 
 *      valley i and valley j. Ninja can start from any valley and start 
 *      jumping. Determine the maximum number of valleys he can visit.
 *  Note: Ninja is not allowed to jump to the right of Nth valley and left of 
 *      1st valley. (Stay within boundaries).
 *      
 *  Input Format:
 *      First line contains an integer t, representing number of test cases
 *      Second line contains two space separated integers N and M.
 *      Third line contains N space separated integers denoting the heights of N valleys.   
 * 
 *  Constraints:
 *      1 <= N <= 10^4
 *      1 <= Height[i] <= 10^5
 *      1 <= M <= N
 *  Time Limit: 1.5 seconds
 * 
 *  Output Format:
 *  Determine the maximum number of valleys Ninja can visit.
 * 
 *  Sample Input 1:
 *      1
 *      11 2
 *      6 4 14 6 8 13 9 7 10 6 12
 *  Sample Output 1:
 *      4
 *  Explanation 1:
 *      You can start at valley 11 with height 12. You can jump from valley 
 *      11 --> 9 --> 7 --> 8.
 */

#include<bits/stdc++.h>
using namespace std;

int main(){

    return 0;
}