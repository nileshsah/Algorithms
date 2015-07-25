#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll n; cin >> n;
	vector< pair<ll,ll> > v;
	ll maxx = -1, sum = 0;
	FOR(i,1,n) {
	  ll x; cin >> x;
	  v.pb( mp(x,i) );
	  maxx = max( maxx, x );
	  sum += x;
	}
	
	sort( all(v) );
	vector<ll> p, q;
	
	FOR(i,0,n-1)
	 if(i%2)
	  p.pb(v[i].S);
	 else
	  q.pb(v[i].S);
	
	cout << p.size() << "\n";
	repVector(p)
	 cout << (*it) << " ";
	cout << '\n';
	cout << q.size() << "\n";
	repVector(q)
	 cout << (*it) << " ";
}
