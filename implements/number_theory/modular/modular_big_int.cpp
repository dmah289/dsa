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
        string s; cin >> s;
        ll m; cin >> m;
        ll r = 0;
        for(char c : s){
            r = r * 10 + (c - '0');
            r %= m;
        }
        cout << r << endl;
    }

    return 0;
}
/*
2
5689 123
5689 12

31
1
*/