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

ll f[1000001];
void gen_fact(){
    f[0] = 1;
    for(int i = 1; i < 1000000; i++){
        f[i] = f[i-1] * i % MOD;
    }
}

ll pow_mod(ll a, ll b){
    ll res = 1;
    a %= MOD;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll inverse_module(ll a){
    return pow_mod(a, MOD-2);
}

/*  Distribute n candies among k children so that each child gets at least 1 candy
    n elements are distributed to k groups => (n-1)C(k-1)
    Stars & bars technique (n = 5; k =) => **|**|*
*/
void solve1(int n, int k){
    cout << f[n-1] % MOD * inverse_module(f[n-k] * f[k-1] % MOD) % MOD << endl;
}

/*  Distribute n candies among k children, it is possible that one child has no candy
    => ||***** => (n+k-1)C(k-1)
*/
void solve2(int n, int k){
    cout << f[n+k-1] % MOD * inverse_module(f[n] * f[k-1] % MOD) % MOD << endl;
}



int main(){
    fast_io

    gen_fact();
    solve1(5,3);
    solve2(2,3);

    return 0;
}