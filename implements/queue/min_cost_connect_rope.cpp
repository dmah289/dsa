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
        vector<int> v(n);
        for(int &x : v) cin >> x;

        int res = 0;
        priority_queue<int, vector<int>, greater<int>> pq(all(v));
        while(pq.size() > 1){
            // get 2 shortest rope
            int top1 = pq.top(); pq.pop();
            int top2 = pq.top(); pq.pop();
            int tmp = top1 + top2;
            res += tmp;
            // push new rope
            pq.push(tmp);
        }
        cout << res << endl;
    }

    return 0;
}

/*
2
4
4 3 2 6
5
4 2 7 6 9

29
62
*/