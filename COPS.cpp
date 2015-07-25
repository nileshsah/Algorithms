#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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
	ll t; cin >> t;
	while(t--) {
		ll m, x, y;
		cin >> m >> x >> y;
		vector<ll> v;
		bool explore[105] = {0};
		FOR(i,1,m) { 
		  ll p; cin >> p;
		  ll start = max(1ll,p-x*y); ll end = min(100ll,p+x*y);
		  FOR(k,start,end )
		   explore[k] = 1;
		}
		
		ll ptr = 0;
		FOR(i,1,100)
		 if( !explore[i] )
		  { ptr++; }
		
		cout << ptr << "\n";
		
		 
	}
}
