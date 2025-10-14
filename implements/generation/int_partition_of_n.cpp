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
        int curr[n+1];

        // first configuration : n
        curr[1] = n;

        int noSummand = 1;
        bool isFinal = false;
        while(!isFinal){
            for(int i = 1; i <= noSummand; i++) cout << curr[i];
            cout << endl;

            int i = noSummand;
            // skip all summands that equal to 1
            while(i >= 1 && curr[i] == 1) i--;

            if(i == 0) isFinal = true;
            else
            {
                // decrease found element to try to reach final configuration
                curr[i]--;
                int noNum1Skipped = noSummand - i + 1;
                noSummand = i;

                // fill remain part by curr[i]
                int q = noNum1Skipped / curr[i];
                int r = noNum1Skipped % curr[i];

                for(int j = 1; j <= q; j++) curr[++noSummand] = curr[i];
                if(r) curr[++noSummand] = r;
            }
        }
    }

    return 0;
}

/*
6
51
42
411
33
321
3111
222
2211
21111
111111
*/