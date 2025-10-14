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

int merge(int a[], int l, int m, int r){
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);

    int cnt = 0;
    int i = 0, j = 0;
    while(i < x.size() || j < y.size()){
        if(i == x.size()) a[l++] = y[j++];
        else if(j == y.size()) a[l++] = x[i++];
        else if(x[i] <= y[j]) a[l++] = x[i++];
        else{
            a[l++] = y[j++];
            cnt += x.size() - i;
        }
    }
    return cnt;
}

int merge_sort(int a[], int l, int r){
    if(l >= r) return 0;

    int cnt = 0;
    int m = (l+r)/2;
    cnt += merge_sort(a, l, m);
    cnt += merge_sort(a, m+1, r);
    cnt += merge(a, l, m , r);

    return cnt;
}

int main(){
    fast_io

    int n = 7;
    int a[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand() % n;
        cout << a[i] << " ";
    }
    cout << endl;

    cout << merge_sort(a, 0, n-1) << endl;

    for(int x : a) cout << x << " ";

    return 0;
}