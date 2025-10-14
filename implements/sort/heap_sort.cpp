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

void heapify(vector<int> &v, int n, int i){
    int largest = i;
    int l = 2*i+1, r = 2*i+2;

    if(l < n && v[l] > v[largest]) largest = l;
    if(r < n && v[r] > v[largest]) largest = r;

    if(largest != i){
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void build_max_heap(vector<int> &v){
    for(int i = v.size()/2-1; i >= 0; i--){
        heapify(v, v.size(), i);
    }
}

void heap_sort(vector<int> &v, int n)
{
    build_max_heap(v);

    for (int i = n - 1; i >= 0; i--)
    {
        // move max val to the end of array
        swap(v[0], v[i]);
        // heapify root node to get new max (skip the final element)
        heapify(v, i, 0);
    }
}

int main(){
    fast_io

    int n; cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    heap_sort(v, n);

    for(int x : v) cout << x << " ";

    return 0;
}
