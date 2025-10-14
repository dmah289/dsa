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

    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int maxEndingHere = 0;
    int maxSoFar = INT_MIN;
    int start = 0, end = 0;
    int tmpStart = 0;
    for(int i = 0; i < n; i++){
        maxEndingHere += a[i];

        if(maxEndingHere > maxSoFar){
            maxSoFar = maxEndingHere;
            start = tmpStart;
            end = i;
        }

        if(maxEndingHere < 0){
            maxEndingHere = 0;
            tmpStart = i+1;
        }
    }

    cout << maxSoFar << " (" << start << " - " << end << ")";

    return 0;
}

/*
5
1 2 -9 3 5

8 (3 - 4)
*/