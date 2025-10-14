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
int first_pos(Iterator first, Iterator last, const T& x){
    int res = -1;
    int size = distance(first, last);
    int l = 0, r = size-1;
    while(l <= r){
        int mid = l + (r-l) / 2;
        if(*(first + mid) == x) {
            res = mid;
            r = mid - 1;        // continue on the leftside
            // l = mid+1;       // continue on the right to find last position
        }
        else if(x < *(first + mid)) r = mid-1;
        else l = mid+1;
    }
    return res;
}

template<typename Iterator, typename T>
int last_pos(Iterator first, Iterator last, const T& x){
    int res = -1;
    int size = distance(first, last);
    int l = 0, r = size-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(*(first + mid) == x){
            res = mid;
            l = mid+1;
        }
        else if(*(first + mid) < x) l = mid+1;
        else r = mid-1;
    }
    return res;
}

int last_pos_less_than_x(vector<int> v, int l, int r, int x){
    int mid;
    int res = -1;
    while(l <= r){
        mid = (l+r) / 2;
        if(v[mid] < x){
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return res;
}

int main(){
    fast_io

    int n, x; cin >> n >> x;
    int a[n];
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        v[i] = a[i];
    }
    sort(a, a+n); sort(all(v));

    cout << first_pos(a, a+n, x) << endl;
    cout << first_pos(all(v), x) << endl;

    cout << last_pos(a, a+n, x) << endl;
    cout << last_pos(all(v), x) << endl;

    return 0;
}