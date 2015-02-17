#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
using namespace std;

int main() {
    ll t;
    get(t);
    set<ll> all, unq;
    vector<ll> even, odd;
    ll ans = 0;
    
    while(t--) {
      ll n;
      get(n);
      ans = ans^n;          
    }
    
    printf("%ld", ans);
}
