#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

vector<ll> v[2000+5];
bool flag = true;
bool explore[2000+5] = {0};

void dfs( int x ) {
	ll count = 0;
	explore[x] = 1;
	for( int i = 0; i < v[x].size(); i++ ) {
		if( flag && !explore[v[x][i]] )
		 { explore[v[x][i]] = 1; dfs(v[x][i]); }
		else {
		 	count++;
			if( count > 1 )
		 		{ flag = false; break; }
		}
	}
}

int main() {
	ll t, count = 1;
	get(t);
	
	while(t--) {
		flag = 1;
		ll n, m;		
		get(n); get(m);
		set<ll> s;
		memset( explore, 0, sizeof explore );
		
		
		while(m--) {
			ll x, y;
			get(x); get(y);
			v[x].pb(y);
			v[y].pb(x);
			s.insert(x); s.insert(y);			
		}
		
		repSet(s)
		 if( !explore[*it] )
		 	dfs(*it);
		
		printf("Scenario #%ld:\n", count++ );
		if( !flag )
		 printf("Suspicious bugs found!\n");
		else
		 printf("No suspicious bugs found!\n");
		
		rep(2000+5)
			v[i].clear();
				
	}
}
