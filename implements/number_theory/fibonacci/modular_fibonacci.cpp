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
void gen_fibo(){
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= 1e6; i++){
        f[i] = (f[i-1] + f[i-2]) % MOD;
    }
}

void multiply_2_matrices(ll a[2][2], ll b[2][2]){
    ll res[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            res[i][j] = 0;
            for(int k = 0; k < 2; k++){
                res[i][j] += a[i][k] * b[k][j] % MOD;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            a[i][j] = res[i][j];
        }
    }
}

/*
Fibonacci Matrix Formula:
|1 1|^n   |F(n+1) F(n)  |
|1 0|   = |F(n)   F(n-1)|
*/
void find_big_fibo_using_pow_mod(ll n){
    ll res[2][2] = {{1, 0}, {0, 1}};
    ll a[2][2] = {{1, 1}, {1, 0}};
    while(n){
        if(n & 1) multiply_2_matrices(res, a);
        multiply_2_matrices(a, a);
        n >>= 1;
    }
    cout << res[0][1] << " " << res[1][0] << endl;
}

int main(){
    fast_io

    // gen_fibo();
    // int t; cin >> t;
    // while(t--){
    //     int n; cin >> n;
    //     cout << f[n] << endl;
    // }

    ll n; cin >> n;
    find_big_fibo_using_pow_mod(n);

    return 0;
}