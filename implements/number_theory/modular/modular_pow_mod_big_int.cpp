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

ll big_int_modulo(string num, ll m){
    ll r = 0;
    for(char c : num){
        r = r * 10 + (c - '0');
        r %= m;
    }
    return r;
}

ll bin_pow_mod(ll a, ll b, ll m){
    ll res = 1;
    a %= m;
    while(b){
        if(b&1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

/*  (a ^ b) % M
    = (a % M) ^ b % M
*/

int main(){
    fast_io

    int t; cin >> t;
    while(t--){
        string a;
        ll b,m; cin >> a >> b >> m;
        ll r = big_int_modulo(a, m);
        cout << bin_pow_mod(r, b, m) << endl;
    }

    return 0;
}

/*
2
3 2 4
34643523417687134146 1000 10

1
6
*/