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

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> v(n);
        for(int &x : v) cin >> x;

        int l,r;
        for(int i = 0; i < n-1; i++){
            if(v[i] > v[i+1]){
                l = i; break;
            }
        }

        for(int j = n-1; j > 0; j--){
            if(v[j] < v[j-1]){
                r = j; break;
            }
        }

        int minVal = *min_element(v.begin() + l, v.begin() + r + 1);
        int maxVal = *max_element(v.begin() + l, v.begin() + r + 1);

        for(int i = 0; i < l; i++){
            if(v[i] > minVal){
                l = i;
                break;
            }
        }

        for(int i = n-1; i > r; i--){
            if(v[i] < maxVal){
                r = i;
                break;
            }
        }

        cout << l << " " << r << endl;
    }


    return 0;
}

/*
3
11
10 12 20 30 25 40 32 31 35 50 60
12
10 12 20 30 25 40 19 32 31 35 50 60
9
0 1 15 25 6 7 30 40 50

3 8
2 9
2 5
*/