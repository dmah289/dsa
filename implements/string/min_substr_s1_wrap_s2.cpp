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
        string s1, s2; cin >> s1 >> s2;
        int freq1[256] = {0}, freq2[256] = {0};
        for(char c : s2) freq2[c]++;
        int cnt = 0;
        int left = 0, len = INT_MAX, idx = -1;
        for(int i = 0; i < s1.length(); i++){
            freq1[s1[i]]++;
            if(freq1[s1[i]] <= freq2[s1[i]]) cnt++;
            if(cnt == s2.length()){
                while(freq1[s1[left]] > freq2[s1[left]] || freq2[s1[left]] == 0){
                    if(freq1[s1[left]] > freq2[s1[left]]) freq1[s1[left]]--;
                    left++;
                }
                if(len > i - left + 1){
                    len = i - left + 1;
                    idx = left;
                }
                if(freq1[s1[left]] == freq2[s1[left]]) {
                    freq1[s1[left]]--;
                    left++;
                    cnt--;
                }
            }
        }
        if(idx == -1) cout << "-1\n";
        else cout << s1.substr(idx, len) << endl;
    }

    return 0;
}

/*
3
timetopractice
toc
timetopractoc
toc
zoomlazapzo
oza

toprac
cto
apzo
*/