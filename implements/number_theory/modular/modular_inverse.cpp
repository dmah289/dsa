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

int x, y, d;

void extended_euclid(ll a, ll b){
    if(b == 0){
        x = 1;
        y = 0;
        d = a;
    }else{
        extended_euclid(b, a % b);
        int tmp = x;
        x = y;
        y = tmp - a / b * y;
    }
}

/*      (a1 / b) % m = ((a1 % m) * (b^-1 % m)) % m
VD : a * a^-1 % m = 1
a^-1 (inverse module) exists when gcd(a, m) = 1
    => a * x + m * y = 1
        (a * x + m * y) % m = 1 % m
        (a * x) % m + 0 = 1
*/

void inverse_module(ll a, ll m){
    extended_euclid(a, m);
    if(d != 1) cout << "!FOUND";
    else cout << (x % m + m) % m;
}

bool isPrime(ll m){
    for(int i = 2; i <= sqrt(m); i++){
        if(m % i == 0) return false;
    }
    return m > 1;
}

ll pow_mod(ll a, ll b, ll m){
    ll res = 1;
    a %= m;
    while(b){
        if(b & 1) res = (res * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return res;
}

/*
a^phi_euler(m) % m = 1
a^(m-1) % m = 1
a^(m-1) * a^-1 % m = a^-1
a^(m-2) % m = a^-1
*/
void inverse_module2(ll a, ll m){
    if(isPrime(m)){
        cout << pow_mod(a, m-2, m);
    }
    else inverse_module(a, m);
}

int main(){
    fast_io

    inverse_module(8, 17);
    inverse_module2(8, 17);

    return 0;
}