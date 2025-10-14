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

// 

int main(){
    fast_io

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<int> st;
        string res = "";
        for(int i = 0; i <= s.length(); i++){
            st.push(i+1);   // push new value

            // the end of string || the end of the increasion chain
            if(i == s.length() || s[i] == 'I'){
                while(!st.empty()){
                    // get increasion chains
                    res += to_string(st.top()); st.pop();
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}

/*
4
I
D
DD
DDIDDIID

12
21
321
321654798
*/