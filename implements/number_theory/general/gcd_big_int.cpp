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

ll modulo_big_int(string a, ll m){
    ll r = 0;
    for(char c : a){
        r = r * 10 + (c - '0');
        r %= m;
    }
    return r;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    fast_io

    int t; cin >> t;
    while(t--){
        ll a; string b;
        cin >> a >> b;
        ll r = modulo_big_int(b, a);
        cout << gcd(a, r) << endl;  // gcd(a, b%a)
    }

    return 0;
}