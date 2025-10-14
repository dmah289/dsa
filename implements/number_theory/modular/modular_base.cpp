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

/*
(a + b) % m = (a % m + b % m) % m
(a * b) % m = ((a % m) * (b % m)) % m
a^b % m = ((a % m) ^ b) % m
*/

ll remainder_of_multiplication(vector<ll> &v){
    ll res = 1;
    for(int x : v){
        res *= (x % INF);
        res %= INF;
    }
    return res;
}

int main(){
    fast_io

    int n; cin >> n;
    vector<ll> v(n);
    for(ll &x : v) cin >> x;

    cout << remainder_of_multiplication(v);

    return 0;
}