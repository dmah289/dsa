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

    int n,m; cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int dp[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = a[i][j];
                continue;
            }

            if(a[i][j]){
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
            }
            else dp[i][j] = 0;
        }
    }

    int res = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dp[i][j] << " ";
            res = max(res, dp[i][j]);
        }
        cout << endl;
    }

    cout << res;

    return 0;
}

/*
6 5
0 1 1 0 1
1 1 0 1 0
0 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 0 0 1 0

3
*/