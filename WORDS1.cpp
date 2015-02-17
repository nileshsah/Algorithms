#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a)
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

bool isConnected( set<ll> s, vector<ll> v[] ) {
	queue<ll> q; 
	q.push(*s.begin());
	bool visit[200] = {0};
	visit[*s.begin()] = 1;
	
	while(!q.empty()) {
		repVector( v[q.front()] )
			if( !visit[*it] )
				{ visit[*it] = 1; q.push(*it); }
		q.pop();
	}
	
	s.erase( *s.begin() );
	
	repSet(s)
		if( visit[*it] == 0 )
			return 0;
	return 1;
}

int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		ll sa[200] = {0}, ea[200] = {0}, ca[200] = {0};
		set<ll> s; vector<ll> v[200];
		
		rep(n)
		 { string a; cin >> a;
		   char p = a[0], q = a[a.size()-1];
		   sa[p]++; ea[q]++;
		   
		   v[p].pb(q);
		   v[q].pb(p);
		   s.insert(p); s.insert(q);
		   
		   if( a[0] == a[a.size()-1] ) ca[a[0]]++;
		 }
		
		ll lc = 0, sc = 0;
		bool flag = 1;
		
		 if( !isConnected( s, v ) )
		  { printf("The door cannot be opened.\n"); continue; }
		
		
		FOR(i,'a','z'+1) {
			bool tflag = 1;
			
			if( sa[i] == ea[i] + 1  ) sc++;
			else if( ea[i] == sa[i] + 1  ) lc++;
			else if( sa[i] != ea[i] ) tflag = 0; 
		
			if( sc > 1 || lc > 1 || !tflag )
				{ flag = 0; break; }
			
		}
		
		if( flag && ( sc + lc == 0 || ( sc == 1 && lc == 1 ) ) )
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
		
	}
}
