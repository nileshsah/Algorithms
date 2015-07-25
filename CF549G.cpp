#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
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
	ll n; cin >> n;
	vector<ll> v;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	FOR(i,0,n-1)
	 v[i] -= n - i;
	sort( all(v) );
	
	FOR(i,0,n-1)
	 v[i] += n - i;
	
	FOR(i,0,n-2)
	 if( v[i] < 0 || v[i] > v[i+1] )
	  { cout << ":("; return 0; }
	FOR(i,0,n-1)
	 cout << v[i] << " ";
}
