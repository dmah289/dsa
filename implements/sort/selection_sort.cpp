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

template<typename Iterator, typename Compare>
void selection_sort(Iterator first, Iterator last, Compare comp){
    int n = distance(first, last);

    for(int i = 0; i < n-1; i++){
        int idxOfMin = i;
        for(int j = i+1; j < n; j++){
            if(comp(*(first + idxOfMin), *(first + j)))
                idxOfMin = j;
        }
        if(i != idxOfMin)
            swap(*(first + i), *(first + idxOfMin));
    }
}

bool comp(int a, int b){ return a > b;}

int main(){
    fast_io

    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    selection_sort(all(v), comp);

    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}