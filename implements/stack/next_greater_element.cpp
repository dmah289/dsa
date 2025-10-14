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

    int n; cin >> n;
    int a[n], b[n];
    for(int &x : a) cin >> x;

    stack<int> st;
    for(int i = 0; i < n; i++){
        if(st.empty()) st.push(i);
        else{
            // consider before elements if they are less than current
            while(!st.empty() && a[i] > a[st.top()]){
                // current is its next greater
                b[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    // remaining elements in stack are decremental
    while(!st.empty()){
        b[st.top()] = -1;
        st.pop();
    }
    for(int i = 0; i < n; i++) cout << b[i] << " ";

    return 0;
}