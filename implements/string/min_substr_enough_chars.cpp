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


// find min window that contains enough unique characters
int main(){
    fast_io

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        map<char, int> mp;
        for(char c : s) mp[c]++;
        int dem[256] = {0};
        int cnt = 0;
        int left = 0, idx = -1, res = INT_MAX;

        // find first window that contains enough unique characters
        for(int i = 0; i < s.length(); i++){
            dem[s[i]]++;
            if(dem[s[i]] == 1) cnt++;
            if(cnt == mp.size()){
                while(dem[s[left]] > 1) {
                    dem[s[left]]--;
                    left++;
                }
                if(res >= i - left + 1){
                    res = i-left+1;
                    idx = left;
                }
                // remove element at left pos
                dem[s[left]]--;
                left++;
                cnt--;
            }
        }

        if(idx == -1) cout << "-1\n";
        else cout << s.substr(idx, res) << endl;
    }

    return 0;
}

/*
3
aaabcba
aabcbcdbca
aaab

cba
dbca
ab
*/