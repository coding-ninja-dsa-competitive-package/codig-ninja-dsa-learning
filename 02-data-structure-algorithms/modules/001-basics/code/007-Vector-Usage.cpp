#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    //dynamic allocation
    vector<int> *vp= new vector<int>();  
    delete vp;
    //static allocation
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //square brackets to be used for only get or update operation
    v[3] = 50;
    v[5] = 90;
    //v.push_back(70);
    //v.push_back(80);

    cout << "v[0] : " << v[0] << endl;
    //at is much safer than square brackets as we get error if we go out of range.
    cout << "v.at(3) : " << v.at(3) << endl;
    cout << "size : " << v.size() << endl;
    print(v);

    v.pop_back();
    print(v);
}