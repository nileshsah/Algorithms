#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

bool nn[105] = {0};
bool mm[105] = {0};

int main() {
	ll n, m;
	cin >> n >> m;
	
	ll x; cin >> x;
	rep(x) {
	   ll p; cin >> p; nn[p] = 1;
	}
	ll y; cin >> y;
	rep(y) {
		ll p; cin >> p; mm[p] = 1;
	}
	
	ll q = max(n,m);
	
	FOR(i,0, q*q*q) {
	 if( mm[i%m] )
	 	nn[i%n] = 1;
	 if( nn[i%n] )
	 	mm[i%m] = 1;
    }
    
    FOR(i,0,n-1)
     if( !nn[i] )
      { cout << "No"; return 0; }
    FOR(i,0,m-1)
     if( !mm[i] )
      { cout << "No"; return 0; }
    
    cout << "Yes";
}
