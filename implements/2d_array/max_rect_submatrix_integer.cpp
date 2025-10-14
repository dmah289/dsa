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

int kadane(int a[], int n){
    int sum = 0;
    int res = INT_MIN;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(sum < 0) sum = 0;
        res = max(res, sum);
    }
    return res;
}

int main(){
    fast_io

    int n, m; cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    int res = INT_MIN;
    int tmp[n];
    for(int l = 0; l < m; l++){
        memset(tmp, 0, sizeof(tmp));
        for(int r = l; r < m; r++){
            for(int i = 0; i < n; i++){
                tmp[i] += a[i][r];
            }
            res = max(res, kadane(tmp, n));
        }
    }

    cout << res;

    return 0;
}

/*
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6

29
*/