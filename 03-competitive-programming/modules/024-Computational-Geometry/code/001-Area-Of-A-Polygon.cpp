#include<bits/stdc++.h>

using namespace std;

class Point{
    public:
        double x, y;
};

class Polygon{
    public:
        Point* points;

        Polygon(int nPoints){
            points = new Point[nPoints];
        }

};

double area(Polygon p, int n){
    double totalArea=0;
    for(int i=1; i<n-1; i++){
        double x1=p.points[i].x-p.points[0].x;
        double y1=p.points[i].y-p.points[0].y;
        double x2=p.points[i+1].x-p.points[0].x;
        double y2=p.points[i+1].y-p.points[0].y;
        double crossProduct=x1*y2 - y1*x2;
        totalArea += crossProduct;
    }
    return abs(totalArea/2);
}

int main(){
    cout << "Enter the number of points in Polygon" << endl;
    int n;
    cin >> n;
    Polygon p(n);
    cout << "Enter the coordinates of Polygon" << endl;
    for(int i=0; i<n; i++){
        cin >> p.points[i].x >> p.points[i].y;
    }
    cout << "Area of Polygon is " << area(p, n) << endl;
}