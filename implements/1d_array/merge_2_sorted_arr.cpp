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

int main(){
    fast_io

    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    int i = 0, j = 0;
    vector<int> res;
    while(i < n || j < m){
        if(i == n) res.push_back(b[j++]);
        else if(j == m) res.push_back(a[i++]);
        else if(a[i] <= b[j]) res.push_back(a[i++]);
        else res.push_back(b[j++]);
    }

    for(int x : res) cout << x << " ";

    return 0;
}