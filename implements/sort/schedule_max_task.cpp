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

bool comp(pair<int, int> a, pair<int, int> b){
    return a.se < b.se;
}

int main(){
    fast_io

    int n; cin >> n;
    vector<pair<int, int>> v(n);
    int a,b;
    for(auto &x : v) cin >> x.first >> x.second;

    // sort by end time
    sort(all(v), comp);
    for(auto it : v) cout << it.fi << " " << it.se << endl;

    int res = 1;
    int tmp = v[0].second;
    for(int i = 1; i < n; i++){
        // starts after selected task ends
        if(v[i].fi > tmp){
            res++;
            tmp = v[i].second;
        }
    }

    cout << res << endl;

    return 0;
}

/*
6
3 8
9 12
6 10
1 4
2 7
11 14

1 4
2 7
3 8
6 10
9 12
11 14
3
*/