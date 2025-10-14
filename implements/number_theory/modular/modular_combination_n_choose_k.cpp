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

// C[i][j] = iCj
int C[1001][1001];

/*
nCk = 1 if k == 0 || k == n
    = (n-1) C (k-1) + (n-1) C k
*/
void gen_comb(){
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i) C[i][j] = 1;
            else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
                C[i][j] %= MOD;
            }
        }
    }
}

ll pow_mod(ll a, ll b, ll m){
    ll res = 1;
    a %= m;
    while(b){
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll inverse_module(ll a, ll m){
    // make sure m is prime, otherwise must use extended euclid
    return pow_mod(a, m-2, m);
}


ll f[1000001];
void gen_factor(){
    f[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        f[i] = f[i-1] * i;
        f[i] %= MOD;
    }
}

/*
nCk % MOD = n! / ((n-k)! * k!) % MOD
        = (n! % MOD * ((n-k)! * k!)^-1 % MOD) % MOD
*/
void gen_big_comb(){
    gen_factor();
    int n, k; cin >> n >> k;
    cout << f[n] % MOD * inverse_module(f[n-k] * f[k] % MOD, MOD) % MOD;
}

int main(){
    fast_io

    gen_comb();
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        cout << C[a][b] << endl;
    }

    return 0;
}