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

void traverse(int i, int j, int* a, int n, int m, bool* visited){
    if(i < 0 || i >= n || j < 0 || j >= m || *(visited + i*m + j) == true || *(a + i*m + j) == 0)
        return;

    *(visited + i*m + j) = true;

    for(int k = -1; k <= 1; k++){
        for(int l = -1; l <= 1; l++){
            traverse(i+k, j+l, a, n, m, visited);
        }
    }
}

int main(){
    fast_io

    int n,m; cin >> n >> m;
    int a[n][m];
    bool visited[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1 && !visited[i][j]){
                traverse(i, j, (int*)a, n, m, (bool*)visited);
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}

/*
4 4
1 1 0 0
0 0 1 0
0 0 0 1
0 1 0 0

2
*/