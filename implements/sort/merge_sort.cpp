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

void merge(int a[], int l, int m, int r){
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);

    int i = 0, j = 0;
    while(i < x.size() || j < y.size()){
        if(i == x.size()) a[l++] = y[j++];
        else if(j == y.size()) a[l++] = x[i++];
        else if(x[i] <= y[j]) a[l++] = x[i++];
        else a[l++] = y[j++];
    }
}

void merge_sort(int a[], int l, int r){
    if(l >= r) return;

    int m = (l+r)/2;
    merge_sort(a, l, m);
    merge_sort(a, m+1, r);
    
    merge(a, l, m, r);
}



int main(){
    fast_io

    int n; cin >> n;
    int a[n];
    srand(time(NULL));
    for(int &x : a) {
        x = rand() % 1000;
    }

    merge_sort(a, 0, n-1);

    for(int x : a) cout << x << " ";

    return 0;
}