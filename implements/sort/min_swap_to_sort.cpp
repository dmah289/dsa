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

int minSwapToSort(vector<pair<int, int>> &v){
    int n = v.size();
    
    vector<bool> visited(n, false);
    int res = 0;

    for(int i = 0; i < n; i++){
        if(visited[i] || v[i].second == i) 
            continue;

        // Current element isn't in appropriate pos && doesn't belong to any cycle.
        int curCycleSize = 0;
        int j = i;

        // find cycle group of k elements
        while(!visited[j]){
            // stop when reach first pos in group
            visited[j] = true;
            j = v[j].second;        // try to move to where this element came from
            curCycleSize++;
        }

        // A cycle of size k needs (k-1) swaps
        if(curCycleSize > 1) 
            res += curCycleSize-1;      
    }

    return res;
}

int main(){
    fast_io

    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back({x,i});
    }
    sort(all(v));

    cout << minSwapToSort(v);

    return 0;
}