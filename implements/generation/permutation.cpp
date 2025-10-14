#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast_io ios::sync_with_stdio(false); cin.tie(0);

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const ld EPS = 1e-9;

int main(){
    fast_io

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int curr[n+1];

        for(int i = 1; i <= n; i++) curr[i] = i;

        bool isFinal = false;
        while(!isFinal){
            for(int i = 1; i <= n; i++) cout << curr[i];
            cout << endl;

            int i = n-1;
            // skip inversion pair -> receive decremental sub-array
            while(i >= 1 && curr[i] > curr[i+1]) i--;

            if(i == 0) isFinal = true;
            else{
                int j = n;
                // first element > curr[i]
                while(curr[i] > curr[j]) j--;
                swap(curr[i], curr[j]);
                
                // reverse decremental array after element at index i
                int l = i+1, r = n;
                while(l < r) swap(curr[l++], curr[r--]);
            }
        }
    }

    return 0;
}