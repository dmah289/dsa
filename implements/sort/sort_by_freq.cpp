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

map<int, int> mp;

void solve1(){
    vector<pair<int, int>> v(all(mp));
    sort(all(v), [](const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    for(auto x : v){
        for(int i = 0; i < x.se; i++) cout << x.first << " ";
    }
}

void solve2(vector<int>& v){
    sort(all(v), [](const int& a, const int& b){
        if(mp[a] == mp[b])
            return a < b;
        return mp[a] > mp[b];
    });
    for(int x : v) cout << x << " ";
}

int main(){
    fast_io

    int n; cin >> n;
    vector<int> v(n);
    for(int &x : v) {
        cin >> x; mp[x]++;
    }

    solve2(v);

    return 0;
}

/*
5 
5 5 4 6 4

4 4 5 5 6
*/