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

int main(){
    fast_io
    
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    multiset<int> ms;
    for(int i = 0; i < k; i++) ms.insert(a[i]);
    for(int i = k; i < n; i++){
        cout << *ms.rbegin() << " ";
        ms.erase(ms.find(a[i-k]));
        ms.insert(a[i]);
    }

    cout << *ms.rbegin();

    return 0;
}

/*
10 3
1 2 3 1 4 5 1 8 9 10

3 3 4 5 5 8 9 10
*/