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

const int MOD = 1e9 + 7;
const ll LINF = 1e18;
const ld EPS = 1e-9;

ll pow1(ll a, ll b){
    ll res = 1;
    a %= MOD;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res;
}

ll pow2(ll a, ll b){
    if(b == 0) return 1;
    a %= MOD;
    ll x = pow2(a, b/2);
    x = (x * x) % MOD;
    if(b & 1) x = (x * a) % MOD;
    return x;
}

int main(){
    fast_io

    cout << pow1(100, 2) << " " << pow2(100, 2);

    return 0;
}