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

    int n; cin >> n;
    
    queue<string> q;
    vector<string> v;
    v.push_back("1");
    q.push("1");
    int cnt = 1;

    while(v.size() < n){
        string tmp = q.front(); q.pop();
        v.push_back(tmp+"0");
        cnt++;
        if(cnt >= n) break;
        v.push_back(tmp+"1");
        cnt++;
        if(cnt >= n) break;
        q.push(tmp+"0");
        q.push(tmp+"1");
    }

    for(string x : v) cout << x << " ";

    return 0;
}