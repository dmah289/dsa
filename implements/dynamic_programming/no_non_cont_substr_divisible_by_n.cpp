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

int num(char c){
    return c - '0';
}

int main(){
    fast_io

    int t; cin >> t;
    while(t--){
        int m,n; cin >> m >> n;
        string s; cin >> s;

        int len = s.length();
        // dp[i][j] : number of substring that ends at i mod n = j
        int dp[len][n];
        memset(dp, 0, sizeof(dp));
        dp[0][num(s[0]) % n] = 1;

        for(int i = 1; i < len; i++){
            dp[i][num(s[i]) % n]++;
            for(int j = 0; j < n; j++){
                // mandatory sync-down step
                dp[i][j] += dp[i-1][j];         // due to not being continuously
                // no substrs that ends at i-1 concatenate s[i] to mod n and the reamainder is (j*10 + num(s[i])
                dp[i][(j*10 + num(s[i])) % n] += dp[i-1][j];
            }
        }

        cout << dp[len-1][0] << endl;
    }

    return 0;
}

/*
2
4 4
1234
3 6
676

4
3
*/