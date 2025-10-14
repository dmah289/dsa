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

    int n, m; cin >> n >> m;
    int a[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    // clockwise
    int h1 = 0, h2 = n-1, c1 = 0, c2 = m-1;
    while(h1 <= h2 && c1 <= c2){
        // top edge
        for(int i = c1; i <= c2; i++) cout << a[h1][i] << " ";
        h1++;
        // right edge
        for(int i = h1; i <= h2; i++) cout << a[i][c2] << " ";
        c2--;
        // h1 and c2 changed -> check again
        // bottom edge
        if(h1 <= h2){
            for(int i = c2; i >= c1; i--) cout << a[h2][i] << " ";
            h2--;
        }
        // left edge
        if(c1 <= c2){
            for(int i = h2; i >= h1; i--) cout << a[i][c1] << " ";
            c1++;
        }
    }

    return 0;
}