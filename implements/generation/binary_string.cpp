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

    int n; cin >> n;
    bool isFinal;
    int curr[n+1];
    
    // init first configuration
    memset(curr, 0, sizeof(curr));

    while(!isFinal){
        for(int i = 1; i <= n; i++) cout << curr[i];
        cout << endl;

        int i = n;
        // loop until not final configuration
        // reverse all 1 after first 0 found + reverse first 0 found
        while(i >= 1 && curr[i] == 1){
            curr[i--] = 0;
        }
        if(i == 0) isFinal = true;
        else curr[i] = 1;
    }


    return 0;
}