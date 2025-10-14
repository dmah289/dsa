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

    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // incremental array
    stack<int> st;
    int i = 0;
    int res = INT_MIN;
    while(i < n){
        // current element is higher than current top -> can expand -> push
        if(st.empty() || a[i] >= a[st.top()]) st.push(i++);
        // current element is shorter than current top -> can't expand -> current is right bound
        else
        {
            int top = st.top(); st.pop();
            // left bound : element that shorter than last top
            // if stack empty -> there is no element that shorter than last top -> expand to head
            if(st.empty()) res = max(res, a[top] * i);
            else res = max(res, a[top] * (i - st.top() - 1));
        }
    }

    while(!st.empty()){
        int top = st.top(); st.pop();
        if(st.empty()) res = max(res, a[top] * i);
        else res = max(res, a[top] * (i - st.top() - 1));
    }

    cout << res << endl;

    return 0;
}

/*
7
6 2 5 4 5 1 6

12
*/