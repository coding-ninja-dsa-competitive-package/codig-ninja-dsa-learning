#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef complex<double> base;

vector<base> initOmega(ll n){
    vector<base> omega(n);
    double PI = acos(-1);
    double angle = 2*(PI/n);
    for (ll i=0; i<n; i++){
        omega[i] = base(cos(angle*i), sin(angle*i));
    }
    return omega;
}

vector<base> fft(vector<base> &a, vector<base> &omega){
    ll n = (ll)a.size();
    if (n == 1){
        return a;
    }
    ll half = n>>1;
    vector<base> aEven(half);
    vector<base> aOdd(half);
    for (ll i=0, j=0; i<n; i+=2, j++){
        aEven[j] = a[i];
        aOdd[j] = a[i+1];
    }
    vector<base> yEven = fft(aEven, omega);
    vector<base> yOdd = fft(aOdd, omega);
    vector<base> y(n);
    for (ll i=0; i<half; i++){
        y[i] = yEven[i] + omega[i]*yOdd[i];
        y[i+half] = yEven[i] - omega[i]*yOdd[i];
    }
    return y;
}

int main(){
    vector<base> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    vector<base> omega = initOmega(a.size());
    vector<base> y = fft(a, omega);
    for (ll i = 0; i < y.size(); i++){
        cout << y[i] << endl;
    }
    return 0;
}