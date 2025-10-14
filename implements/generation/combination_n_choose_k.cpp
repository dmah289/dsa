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
        int n,k; cin >> n >> k;
        bool isFinal = false;

        int curr[k+1];
        // first configuration
        for(int i = 1; i <= k; i++){
            curr[i] = i;
        }

        while(!isFinal){
            for(int i = 1; i <= k; i++) cout << curr[i];
            cout << endl;
            
            int i = k;
            // skip if reach max at that pos
            while(i >= 1 && curr[i] == n-k+i) i--;

            if(i == 0) isFinal = true;
            else{
                // reset continuous imcrement substr after found pos
                curr[i]++;
                for(int j = i+1; j <= k; j++){
                    curr[j] = curr[j-1] + 1;
                }
            }
        }
    }

    return 0;
}