#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast_io ios::sync_with_stdio(false); cin.tie(0);

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const ld EPS = 1e-9;

ll gcd1(ll a, ll b){
    if(a == 0 || b == 0) return a + b;
    while(a != b){
        if(a > b) a -= b;
        else b -= a;
    }
    return a;
}

ll gcd2(ll a, ll b){
    if(a * b == 0) return a + b;
    while(a * b != 0){
        if(a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

ll euclid_gcd(ll a, ll b){
    if(b == 0) return a;
    euclid_gcd(b, a % b);
}

ll gcd4(ll a, ll b){
    while(b != 0){
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll lcm(ll a, ll b){
    return (a * b) / euclid_gcd(a, b);
}

int main(){
    fast_io

    int n; cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    cout << gcd4(25, 10);

    return 0;
}