#include<bits/stdc++.h>

using namespace std;

class Triplet{
    public:
        int x, y, gcd;
};

Triplet extendedEuclid(int a, int b){
    if (b == 0){
        Triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }
    Triplet smallAns = extendedEuclid(b, a % b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - smallAns.y*(a/b);
    return ans;
}

int multiplicativeModuloInverse(int a, int m){
    Triplet ans = extendedEuclid(a, m);
    return ans.x;
}

int main(){
    int a=5;
    int m=12;
    int ans = multiplicativeModuloInverse(a, m);
    cout << ans << endl;
}