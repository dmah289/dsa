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

    int n,k; cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;

    deque<int> dq;
    for(int i = 0; i < n; i++){
        // push possible max element in next window 
        // (pop all elements that are smaller than it)
        while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);

        // remove element that is out of window
        if(i >= k && dq.front() <= i-k) dq.pop_front();

        // front : max elemet in win
        if(i >= k-1) cout << a[dq.front()] << " ";
    }

    return 0;
}

/*
9 3
7 3 1 2 8 6 4 1 0

7 3 8 8 8 6 4 
*/