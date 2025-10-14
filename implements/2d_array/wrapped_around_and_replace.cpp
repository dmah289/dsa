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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n,m;
char a[401][401];

bool isInBound(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

void floodFill(int i, int j){
    a[i][j] = '*';
    for(int k = 0; k < 4; k++){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(isInBound(ni, nj) && a[ni][nj] == 'O')
            floodFill(ni, nj);
    }
}

int main(){
    fast_io

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // Spread from edge
            if((i == 0 || i == n-1 || j == 0 || j == m-1) && a[i][j] == 'O') 
                floodFill(i, j);
        }
    }


    // Remaing 'O' can't be reached -> replaced by 'X'
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'O') a[i][j] = 'X';
            else if(a[i][j] == '*') a[i][j] = 'O';

            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
6 6
O O O X X X
X X X O O X
X O X O X X
O X X X X O
O O O O X X
X X X X X O

O O O X X X
X X X X X X
X X X X X X
O X X X X O
O O O O X X
X X X X X O
*/