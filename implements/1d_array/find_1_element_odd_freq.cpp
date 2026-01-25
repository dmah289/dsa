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
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        int res = v[0];
        for(int i = 1; i < n; i++){
            res ^= v[i];
        }
        cout << res << endl;
    }

    return 0;
}

/*
Find only 1 element having odd frequency
2
7
2 2 3 4 2 2 4
5
1 1 3 3 2

3
2
*/