#include<bits/stdc++.h>

using namespace std;

/**
 *  Convex Hull
 *  -   Given a set of points in the plane. the convex hull of the set is the 
 *      smallest convex polygon that contains all the points of it.
 *  -   Find out the convex hull for the given set of points.
 *  
 *  Input Format
 *      Integer N(Number Of points) 
 *      Array of X coordinates
 *      Array of Y coordinates
 *  Output Format
 *      X coordinate and Y coordinate of all the points seperated by space. 
 *      Order doesn't matter.
 *  Sample Testcase 
 *  
 *  Input
 *      7   
 *      2 1 6 5 3 7 9
 *      2 5 1 5 7 6 4
 *  Output
 *      1 5
 *      2 2
 *      6 1
 *      9 4
 *      7 6
 *      3 7
 */

struct Point{
    int x, y;
};

bool toChange(Point p, Point q, Point r){
    int x1 = q.x - p.x;
    int y1 = q.y - p.y;
    int x2 = r.x - q.x;
    int y2 = r.y - q.y;
    int value = x1*y2 - y1*x2;
    return value < 0;
}

void convexHull(Point *points, int n) {
    vector<Point> hull;
    int left = 0;
    for (int i = 1; i < n; i++){
        if (points[i].x < points[left].x){
            left = i;
        }
    }

    int p = left;
    do {
        hull.push_back(points[p]);
        int q = (p+1) % n;
        for (int i=0; i<n; i++){
            if (toChange(points[p], points[q], points[i])){
                q = i;
            }
        }
        p = q;
    } while (p != left);

    for (int i=0; i<hull.size(); i++){
        Point currPoint = hull.at(i);
        cout << currPoint.x << " " << currPoint.y << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int* arrX = new int[n];
    int* arrY = new int[n];
    for (int i=0; i<n; i++){
        cin >> arrX[i];
    }
    for (int i=0; i<n; i++){
        cin >> arrY[i];
    }
    Point *points = new Point[n];
    for (int i=0; i<n; i++){
        Point p;
        p.x = arrX[i];
        p.y = arrY[i];
        points[i] = p;
    }
    convexHull(points, n);
}