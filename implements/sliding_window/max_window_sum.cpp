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

int main(){
    fast_io

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        int w_sum = 0;
        for(int i = 0; i < k; i++){
            w_sum += v[i];
        }

        ll res = 0, res_idx = 0;
        for(int i = k; i < n; i++){
            w_sum = w_sum + v[i] - v[i-k];

            if(w_sum > res){
                res_idx = i-k+1;
                res = w_sum;
            }
        }

        for(int i = 0; i < k; i++){
            cout << v[i + res_idx] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
2
5 2
10 4 5 15 20
4 2
-12 34 56 7

15 20
34 56
*/