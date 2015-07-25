#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main() {
	vector<ll> a;
	FOR(i,1,6)
	 { ll x; cin >> x; a.pb(x); }
	ll val = 0;

  FOR(k,1,6) {	
    ll ans = ( 2*a[0] + a[5] )*a[5] + ( a[3] + a[0] + a[5] )*a[4];
	val = max(val,ans);
	a.insert( a.begin(), a.back() ); a.erase(--a.end());
   }
   	
   	cout << val;
	 
}
