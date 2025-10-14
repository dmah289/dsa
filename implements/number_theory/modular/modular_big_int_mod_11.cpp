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

/*  abcd % 11  = (a * 1000 + b * 100 + c * 10 + d) % 11
    1000 % 11 = -1 ; 100 % 11 = 1 ; 10 % 11 = -1
    => (a * -1 + b * 1 + c * -1 + d) % 11
*/

int main(){
    fast_io

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int r = 0;
        for(int i = 0; i < s.length(); i++){
            if(i&1) r -= s[i] - '0';
            else r += s[i] - '0';
        }
        cout << ((r % 11 == 0) ? "YES" : "NO") << endl;
    }

    return 0;
}