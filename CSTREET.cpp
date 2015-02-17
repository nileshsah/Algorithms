#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

bool cyclic( vector<ll> v[], ll n ) {
	bool visit[1005] = {0};
	queue<int> q;
	
	FOR(i,1,n+1)
		if( visit[i] == 0 ) {
			q.push(i); visit[i] = 1;
			while( !q.empty() ) {
				ll c = 0;			
				repVector(v[q.front()])
					if( !visit[*it] )
					 { q.push(*it); visit[*it] = 1; }
					else c++;
				q.pop();
				if( c > 1 ) return true;
			}		
		}
	return 0;
}

int main() {
	ll t; get(t);
	
	while(t--) {
		ll p, n, m;
		get(p); get(n); get(m);
		
		vector< pair<ll, pair<ll,ll> > > v;
		
		rep(m) {
			ll a,b,c;
			get(a); get(b); get(c);
			v.pb( mp( c, mp(a,b) ) );
		}
		
		sort( all(v) );
		
		ll in = 0, i = 0 , ans = 0;
		vector<ll> adj[1005];
		
		while( in != n-1 ) {
			adj[ v[i].S.F ].pb( v[i].S.S );
			adj[ v[i].S.S ].pb( v[i].S.F );
			
			if( !cyclic( adj , n ) )
			  { ans += v[i].F; in++; }
			else {
			  adj[ v[i].S.F ].pop_back();
			  adj[ v[i].S.S ].pop_back();
			}
			i++;	
		}
		
		printf("%ld\n", p*ans);
	}
}
