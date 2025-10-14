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

template<typename Iterator, typename T>
bool binarySearch(Iterator first, Iterator last, const T& x){
    int size = distance(first, last);
    int l = 0, r = size - 1;

    int mid;
    while(l <= r){
        mid = l + (r - l) / 2;          // avoid overflow
        if(*(first + mid) == x) return true;
        else if(x < *(first + mid)) r = mid-1;
        else l = mid+1;
    }

    return false;
}

template<typename Iterator, typename T>
bool binarySearchRecursion(Iterator first, Iterator last, const T& x, int l, int r){
    if(l > r) return false;

    int mid = l + (r - l) / 2;
    if(*(first + mid) == x) return true;
    else if(x < *(first + mid)) return binarySearchRecursion(first, last, x, l, mid-1);
    return binarySearchRecursion(first, last, x, mid+1, r);
}

int main(){
    fast_io

    int n, x; cin >> n >> x;
    vector<int> v(n);
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> v[i];
        a[i] = v[i];
    }
    sort(all(v));
    sort(a, a + n);

    cout << binarySearch(a, a + n, x) << endl;
    cout << binarySearch(all(v), x) << endl;

    cout << binarySearchRecursion(a, a + n, x, 0, n-1) << endl;
    cout << binarySearchRecursion(all(v), x, 0, n-1) << endl;

    return 0;
}