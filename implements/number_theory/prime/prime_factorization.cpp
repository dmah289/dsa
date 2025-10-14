#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast_io ios::sync_with_stdio(false); cin.tie(0);

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const ld EPS = 1e-9;

void factorize1(ll n){
    for(int i = 2; i*i <= n; i++){
        while(n%i == 0){
            cout << i << " ";
            n/=i;
        }
    }
    if(n > 1) cout << n << " ";
}

int main(){
    fast_io

    factorize1(20);

    return 0;
}