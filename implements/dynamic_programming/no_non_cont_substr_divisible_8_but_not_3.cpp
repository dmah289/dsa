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
        int len = s.length();

        // dp[i][j] : The number of substrings start from idx 0, ends at index < i which divided by 3 and the remainder is j.
        int dp[len+1][3];

        // Sum of substring ends at i divided by 3, the remainder is pre[i]
        int preRemainder[len+1];

        memset(dp, 0, sizeof(dp));
        memset(preRemainder, 0, sizeof(preRemainder));

        int sumMod = 0;
        dp[0][0] = 1;       // empty string

        for(int i = 1; i <= len; i++){
            sumMod += s[i-1] - '0';
            sumMod %= 3;
            preRemainder[i] = sumMod;

            dp[i][sumMod]++;
            for(int j = 0; j < 3; j++)
                dp[i][j] += dp[i-1][j];
        }

        // for(int i = 0; i <= len; i++){
        //     for(int j = 0; j < 3; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int ans = 0;
        for(int i = 1; i <= len; i++){
            int num = s[i-1] - '0';

            if(num == 8) ans++;

            if(i >= 2){
                int tmp = (s[i-2] - '0') * 10 + (s[i-1] - '0');
                if(tmp % 8 == 0 && tmp % 3 != 0)
                    ans++;
            }

            if(i >= 3){
                int tmp = (s[i-3] - '0') * 100 + (s[i-2] - '0') * 10 + (s[i-1] - '0');
                if(tmp % 8 == 0){
                    // number of substrings end with [i-3][i-2][i-1]
                    ans += i-2;
                    // number of substrings that end at index i-3 and the same remainder with preRemainder[i]
                    // 77278
                    ans -= dp[i-3][preRemainder[i]];
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}

/* dp
7727891240

1 0 0 
1 1 0 
1 1 1 
1 2 1 
1 2 2 
1 3 2 
1 4 2 
1 4 3 
1 5 3 
1 5 4 
1 5 5 
*/

/*
2
888
6564525600

5
15
*/