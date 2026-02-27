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

        int s2CharAmountAppearedInS1 = 0;
        int left = 0, currLen = INT_MAX, idx = -1;

        for(int i = 0; i < s1.length(); i++){
            freq1[s1[i]]++;
            if(freq1[s1[i]] <= freq2[s1[i]]) s2CharAmountAppearedInS1++;

            if(s2CharAmountAppearedInS1 == s2.length()){
                while(freq1[s1[left]] > freq2[s1[left]] || freq2[s1[left]] == 0){
                    if(freq1[s1[left]] > freq2[s1[left]])
                        freq1[s1[left]]--;

                    left++;
                }

                if(currLen > i - left + 1){
                    currLen = i - left + 1;
                    idx = left;
                }

                if(freq1[s1[left]] == freq2[s1[left]]){
                    freq1[s1[left]]--;
                    left++;
                    s2CharAmountAppearedInS1--;
                }
            }
        }
        if(idx == -1) cout << "-1\n";
        else cout << s1.substr(idx, currLen) << endl;
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