#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define MOD 1000007
using namespace std;

int main() {
    ll t;
    get(t);
    
    while(t--) {
       ll n;
       get(n);
       
       ll ans = 0;
       ans += n*(n+1);
       ans %= MOD;
       ans +=  ( ( n*(n-1) )/2 )%MOD;
       ans %= MOD;
       
       printf("%lld\n", ans);
    }
}
    
