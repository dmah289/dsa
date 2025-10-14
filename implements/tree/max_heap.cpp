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

// gen max heap (complete bin tree - fill leaves from left && par > left && par > right)
// left : 2*i+1 ; right : 2*i+2 ; parent : (i-1)/2
void heapify(vector<int> &v, int i){
    int largest = i;
    int l = 2*i+1, r = 2*i+2;

    // find larget in {l, r, par}
    if(l < v.size() && v[l] > v[largest]) largest = l;
    if(r < v.size() && v[r] > v[largest]) largest = r;

    if(largest != i){
        swap(v[i], v[largest]);
        // continue on subtree which start from largest (due to swapping process)
        heapify(v, largest);
    }
}

void build_max_heap(vector<int> &v){
    // loop through node isn't leaf
    for(int i = v.size()/2-1; i >= 0; i--){
        heapify(v, i);
    }
}

int main(){
    fast_io

    int n; cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    build_max_heap(v);

    for(int x : v) cout << x << " ";

    return 0;
}