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

    int n,m,l; cin >> n >> m >> l;
    vector<int> a(n), b(m), c(l);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    for(int &x : c) cin >> x;

    int i = 0, j = 0, k = 0;
    vector<int> res;
    while(i < n && j < m && k < l){
        if(a[i] == b[j] && b[j] == c[k]){
            res.push_back(a[i]);
            i++; j++; l++;
        }else if(a[i] <= b[j] && a[i] <= c[l]) i++;
        else if(b[j] <= a[i] && b[j] <= c[l]) j++;
        else k++;
    }
    if(res.size() == 0) cout << -1;
    else for(int x : res) cout << x << " ";

    return 0;
}

