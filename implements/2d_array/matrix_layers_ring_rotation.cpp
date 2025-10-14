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

    int h1 = 0, h2 = n-1, c1 = 0, c2 = m-1;
    int prev, cur;

    // sprial matrix varient
    while(h1 < h2 && c1 < c2){
        // save last element in ring
        prev = a[h1+1][c1];
        // top edge
        for(int i = c1; i <= c2; i++){
            cur = a[h1][i];
            a[h1][i] = prev;
            prev = cur;
        }
        h1++;
        // right edge 
        for(int i = h1; i <= h2; i++){
            cur = a[i][c2];
            a[i][c2] = prev;
            prev = cur;
        }
        c2--;
        // bottom edge
        if(h1 <= h2){
            for(int i = c2; i >= c1; i--){
                cur = a[h2][i];
                a[h2][i] = prev;
                prev = cur;
            }
            h2--;
        }
        // left edge
        if(c1 <= c2){
            for(int i = h2; i >= h1; i--){
                cur = a[i][c1];
                a[i][c1] = prev;
                prev = cur;
            }
            c1++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}

/*
In:
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Out:
5 1 2 3 
9 10 6 4 
13 11 7 8 
14 15 16 12 
*/