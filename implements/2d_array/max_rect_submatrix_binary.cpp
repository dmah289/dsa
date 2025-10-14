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

int area(int x[], int m){
    int res = INT_MIN;
    int i = 0;
    stack<int> st;
    while(i < m){
        if(st.empty() || x[i] >= x[st.top()]) st.push(i++);
        else{
            int top = st.top(); st.pop();
            if(st.empty()) res = max(res, i * x[top]);
            else res = max(res, x[top] * (i - st.top() - 1));
        }
    }

    while(!st.empty()){
        int top = st.top(); st.pop();
        if(st.empty()) res = max(res, i * x[top]);
        else res = max(res, x[top] * (i - st.top() - 1));
    }

    return res;
}

int main(){
    fast_io

    int n,m; cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int histogram[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0){
                histogram[i][j] = a[i][j];
                continue;
            }

            if(a[i][j] == 1) histogram[i][j] = histogram[i-1][j] + 1;
            else histogram[i][j] = 0;
        }
    }

    int res = INT_MIN;
    for(int i = 0; i < n; i++){
        res = max(res, area(histogram[i], m));
    }

    cout << res << endl;

    return 0;
}

/*
4 4
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0

8
*/