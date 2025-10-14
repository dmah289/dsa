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

    int n, q; cin >> n >> q;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    ll ps[n+1] = {0};
    for(int i = 1; i <= n; i++) ps[i] = ps[i-1] + v[i];

    int a,b;
    while(q--){
        cin >> a >> b;
        cout << ps[b] - ps[a-1] << endl;
    }

    return 0;
}