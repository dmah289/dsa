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

const int INF = 1e7;
const ll LINF = 1e18;
const ld EPS = 1e-9;

bool isPrime[INF+1];

void gen_primes(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= sqrt(INF); i++){
        if(isPrime[i]){
            for(int j = i * i; j <= INF; j += i){
                isPrime[j] = false;
            }
        }
    }
}

void sieve_on_segment(int l, int r){
    int size = r-l+1;
    int prime[size];
    fill(prime, prime+size+1, 1);

    for(int i = 2; i*i <= r; i++){
        for(int j = max(i*i, (l+i-1)/i*i); j <= r; j += i)
            prime[j-l] = 0;
    }

    for(int i = max(l, 2); i <= r; i++){
        if(prime[i-l]) cout << i << ' ';
    }
}

int main(){
    fast_io

    sieve_on_segment(10, 100);

    return 0;
}