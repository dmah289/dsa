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

// counts the number of positive int less than of equal to n that are coprime to n 
// phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ...           #[pi : prime factor]
ll totient_func(ll n){
    ll res = n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            res -= res / i;
        }
    }
    if(n > 1) res -= res / n;

    return res;
}


int main(){
    fast_io

    // int n; cin >> n;
    // vector<int> v(n);
    // for(int &x : v) cin >> x;

    cout << totient_func(12);

    return 0;
}