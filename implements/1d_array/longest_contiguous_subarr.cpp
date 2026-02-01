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

        int currLen = 1, res = 1;
        for(int i = 1; i < n; i++){
           if(v[i] == v[i-1]) currLen++;
           else currLen = 1;

           res = max(res, currLen);
        }

        cout << res << endl;
    }

    return 0;
}

/*
2
4
1 2 3 4
5
1 2 2 1 2

1
2
*/