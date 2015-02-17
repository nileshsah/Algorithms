#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
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
#define mp make_pair
using namespace std;

int main() {
	freopen("input.in","r",stdin);
	ll t; get(t);
	while(t--) {
		ll n, m;
		get(n); get(m);
		
		ll time[105][105] = {0}, risk[105][105] = {0};
		
		FOR(i,0,n)
		 FOR(j,0,n)
		  get(time[i][j]);
		
		FOR(i,0,n)
		 FOR(j,0,n)
		  get(risk[i][j]);
		
		set< pair< pair<ll,ll>, ll > > s;
		vector<ll> D(n+1,INT_MAX);
		vector<ll> R(n+1,INT_MAX);
		
		s.insert( mp( mp(0,0), 0 ) );
		bool flag = 0;
		
		D[0] = 0; R[0] = 0;
		while( !s.empty() ) {
			pair< pair<ll,ll>, ll > node = *s.begin();
			s.erase(s.begin());	
			
			if( node.F.S > m )
				continue;	
			if( node.S == n-1 )
				{ flag = 1; printf("%ld %ld\n", node.F.F, node.F.S); break; } 		
			
			ll ptr = node.S;
			
			FOR(i,0,n)
			 if( ptr == i ) continue;
			 else if( D[ptr] + risk[ptr][i] < D[i] ) 
			 { 
				s.erase( mp( mp(D[i],R[i]), i ) );
				D[i] = D[ptr] + risk[ptr][i];
				R[i] = R[ptr] + time[ptr][i];
				s.insert( mp( mp(D[i],R[i]), i ) );
			}
		}
		
		if(!flag )
			printf("-1\n");
			

	}
}
