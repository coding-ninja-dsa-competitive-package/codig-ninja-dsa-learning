#include<bits/stdc++.h>

using namespace std;

/**
 *  Rectangular Area
 *  -   CodingNinjas has given you N rectangles, which are centered in the center of the
 *      Cartesian coordinate system and their sidea are parallel to the coordinate axes.
 *      Each rectangle is uniquely identified with its width ( along the x-axis ). Navdeep 
 *      has coloured each rectangle in a certain colour and now wants to know the area
 *      of coloured part of paper.
 * 
 *  Input Format:
 *      The first line of the input contains the integer N (1 <= N <= 1000000), the number
 *      of rectangles. Each of the following N lines contains even integers X and Y
 *      (2 <= X,Y <= 10^7) dimensions (width and height, respectively) of rectangles.
 *  Output Format:
 *      The first and only line of output must contain the required area.
 * 
 *  Sample Input1:
 *      3
 *      8 2 
 *      4 4 
 *      2 6
 *  Sample Output1:
 *      28
 * 
 *  Sample Input2:
 *      5
 *      2 10 
 *      4 4
 *      2 2
 *      8 8
 *      6 6
 *  Sample Output2:
 *      68
 */

int main() {
    int n;
    cin >> n;

    int* height = new int[50000002];
    int max_x=0;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        if(height[x/2] < y){
            height[x/2] = y;
        }
        if((x/2) > max_x){
            max_x = x/2;
        }
    }
    long area = 0;
    for(int i=max_x; i>0; i--){
        if(height[i] <height[i+1]){
            height[i] = height[i+1];
        }
        area += height[i];
    }
    cout << 2*area << endl;

    return 0;
}