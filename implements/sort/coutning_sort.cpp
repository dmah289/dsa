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

int cnt[(int)1e7 + 1];

int main(){
    fast_io

    int n; cin >> n;
    vector<int> v(n);
    int m = INT_MIN;
    for(int &x : v){
        cin >> x;
        cnt[x]++;
        m = max(m, x);
    }

    for(int i = 0; i <= m; i++){
        if(cnt[i] != 0){
            for(int j = 0; j < cnt[i]; j++)
                cout << i << " ";
        }
    }
    
    return 0;
}