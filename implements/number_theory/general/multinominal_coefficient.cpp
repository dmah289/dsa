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

/*  create string size of n and at least r 'R', g 'G', b 'B'   (r + g + b <= n)
    The number of ways to divide n elements into subsets of size k1,k2,...
    Formula : n! / (k1! * k2! * ...)
*/

ll factor[22];
void gen_factor(){
    factor[0] = 1;
    for(int i = 1; i <= 20; i++){
        factor[i] = factor[i-1] * i;
    }
}

int main(){
    fast_io

    gen_factor();
    int t; cin >> t;
    while(t--){
        int n, r, g, b;
        cin >> n >> r >> g >> b;
        int res = 0;
        for(int R = n; R >= r; R--){
            for(int G = n-R; G >= g; G--){
                int B = n - R - G;
                if(B >= b) res += factor[n] / (factor[R] * factor[G] * factor[B]);
            }
        }

        cout << res << endl;
    }

    return 0;
}

/*
2
4 1 1 1
4 2 0 1

36
22
*/