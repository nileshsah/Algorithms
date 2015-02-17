#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

struct node {
	ll dest;
	ll L;
	ll T;
};


int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n, m, r;
		get(m); get(n); get(r);
		vector<node> v[105];
		
		rep(r) {
			ll x; node p;
			get(x); get(p.dest); get(p.L); get(p.T);
			v[x].pb(p);
		}
		
		vector<ll> D(n+1,INT_MAX);
		vector<ll> R(n+1,INT_MAX);
		D[1] = 0; R[1] = 0;
		set< pair< pair<ll,ll>, ll > > s;
		s.insert( mp( mp(D[1],R[1]), 1 ) );
		
		while(!s.empty()) {
			ll ptr = s.begin()->S;
			ll rate = s.begin()->F.S;
			ll dist = s.begin()->F.F;
			s.erase(s.begin());
			
			if( ptr == n )
			  { D[n] = dist; break;	}		
		//	cout << " FOR:" << ptr << endl;
						
			repVector(v[ptr])
			  if( rate + it->T <= m  ) {
				R[it->dest] = rate + it->T;
			  	D[it->dest] = dist + it->L;
		//	 	cout << " NEW: " << it->dest << " " << D[it->dest] << endl;
			  	s.insert( mp( mp( D[it->dest], R[it->dest] ), it->dest ) );
			  }
		}
		
		if( D[n] == INT_MAX ) D[n] = -1;
		
		printf("%ld\n", D[n]);
	}
}
