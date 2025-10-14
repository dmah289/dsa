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

int x, y, d;

/*  Extended Euclid :   a * x + b * y = gcd(a, b)
when b == 0, a == g -> euclid algo stops
=> g * 1 + 0 * 0 = gcd(a, b)    => found coefficients (x, y) = (1, 0)
=> Euclid transformation: b * x1 + (a mod b) * y1 = g
                        => b * x1 + (a - a / b * b) * y1 = g
                        => g = a * y1 + b * (x1 - y1 * (a / b))
=> x = y1
   y = x1 - y1 * (a / b)
*/
void extended_euclid(ll a, ll b){
    if(b == 0) {
        x = 1;
        y = 0;
        d = a;
    }
    else{
        // if the euqation at the base step is correct, and the transformation formula is correct
        // => The equation at the larger step is also correct
        extended_euclid(b, a % b);
        int tmp = x;
        x = y;
        y = tmp - a / b * y;
    }
}

int main(){
    fast_io

    int a, b; cin >> a >> b;
    extended_euclid(a, b);
    cout << x << " " << y << " " << d;

    return 0;
}

/*
extended_euclid(30, 18):
extended_euclid(18, 12):
extended_euclid(12, 6):
    extended_euclid(6, 0):
    // Base: x=1, y=0, d=6
    // Nghĩa là: 6*1 + 0*0 = 6 ✓
    
    // Quay lui về (12, 6):
    // Cần: 12*x + 6*y = 6
    // Có: 6*1 + 0*0 = 6
    // Áp dụng: x = y1 = 0, y = x1 - (12/6)*y1 = 1 - 2*0 = 1
    // Kết quả: x=0, y=1 → 12*0 + 6*1 = 6 ✓

// Quay lui về (18, 12):
// Cần: 18*x + 12*y = 6  
// Có: 12*0 + 6*1 = 6
// Áp dụng: x = y1 = 1, y = x1 - (18/12)*y1 = 0 - 1*1 = -1
// Kết quả: x=1, y=-1 → 18*1 + 12*(-1) = 6 ✓

// Quay lui về (30, 18):
// Cần: 30*x + 18*y = 6
// Có: 18*1 + 12*(-1) = 6  
// Áp dụng: x = y1 = -1, y = x1 - (30/18)*y1 = 1 - 1*(-1) = 2
// Kết quả: x=-1, y=2 → 30*(-1) + 18*2 = 6 ✓
*/