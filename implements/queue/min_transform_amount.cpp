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

// Action 1 : s--
// Action 2 : s *= 2
// Min steps to transform from s -> t

int main(){
    fast_io

    int tc; cin >> tc;
    while(tc--){
        int s,t; cin >> s >> t;

        // BFS
        queue<pair<int, int>> q;
        q.push(make_pair(s, 0));
        set<int> old_states;
        old_states.insert(s);

        while(!q.empty()){
            auto front = q.front(); q.pop();

            if(front.first == t){
                cout << front.second << endl;
                break;
            }

            if(front.first * 2 == t || front.first - 1 == t){
                cout << front.second+1;
                break;
            }

            if(old_states.find(front.first-1) == old_states.end() && front.first > 1){
                q.push(make_pair(front.first-1, front.second+1));
                old_states.insert(front.first-1);
            }
            if(old_states.find(front.first*2) == old_states.end() && front.first < t) {
                q.push(make_pair(front.first*2, front.second+1));
                old_states.insert(front.first*2);
            }
        }
    }

    /*
    if (s >= t) { 
        cout << s - t; 
        return 0; 
    }

    int steps = 0;
    while (t > s) {
        ++steps;
        if (t & 1) t++;   // t lẻ: đảo của s--
        else       t >>= 1; // t chẵn: đảo của s*=2
    }
    cout << steps + (s - t);
    */

    return 0;
}

/*
3
2 5
3 7
7 4

4
4
3
*/