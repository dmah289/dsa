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


// left subarr <= pivot && right subarr >= pivot
int lomuto_partition(vector<int> &v, int l, int r){
    int pivot = v[r];
    int i = l-1;
    for(int j = l; j < r; j++){
        if(v[j] <= pivot) swap(v[j], v[++i]);
    }
    // move pivot to middle
    swap(v[++i], v[r]);

    return i;
}

int hoare_partition(vector<int> &v, int l, int r){
    int pivot = v[l];
    int i = l-1, j = r+1;
    while(true){
        // find inversion pair
        do {i++;} while(v[i] < pivot);    // find a[i] >= pivot
        do {j--;} while(v[j] > pivot);    // find a[j] <= pivot

        if(i < j) swap(v[i],v[j]);
        else return j;
    }
}

void quick_sort(vector<int> &v, int l, int r){
    if(l >= r) return;

    int pivot = hoare_partition(v, l, r);
    quick_sort(v, l, pivot);
    quick_sort(v, pivot+1, r);

    // int pivot = lomuto_partition(v, l, r);
    // quick_sort(v, l, pivot-1);
    // quick_sort(v, pivot+1, r);
}

int main(){
    fast_io

    int n; cin >> n;
    vector<int>v(n);

    for(int &x : v) cin >> x;

    // quick_sort(v, 0, n-1);
    cout << hoare_partition(v, 0, n-1) << endl;
    for(int x : v) cout << x << " ";

    return 0;
}