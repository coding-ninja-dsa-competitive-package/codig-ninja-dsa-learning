#include<bits/stdc++.h>

using namespace std;

/**
 *  Calculate Area of two rectangles intersecting each other.
 * 
 *  Input Format : Coordinates are provided for both the rectangles
 *      x1 y1 x2 y2 
 *      x3 y3 x4 y4
 *  Output Format : 
 *      Area of Rectangle
 *  
 *  -   For Example : 
 *          1 1 3 4 
 *          2 3 6 7
 *      Output : 21
 */

int main() {
    freopen("../io/areain.txt", "r", stdin);
    freopen("../io/areaout.txt", "w", stdout);
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2>> y2;
    int x3, y3, x4 , y4;
    cin >> x3 >> y3 >> x4 >> y4;

    int area1 = (x2-x1)*(y2-y1);
    int area2 = (x4-x3)*(y4-y3);

    int left = max(x1, x3);
    int right = min (x2, x4);
    int bottom = max (y1, y3);
    int top = min(y2, y4);

    int area_intr = 0;
    if(left < right && bottom < top){
        area_intr = (right-left) * (top-bottom);
    }

    int area = area1+area2 - area_intr;
    cout << area << endl;

    return 0;
}