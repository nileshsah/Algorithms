#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;


bool mark[105] = {0};
vector<ll> v[105], ans;
ll deg[105] = {0};
set<ll> s;

void solve() {
	
	while(!s.empty()) {
		ll top = *s.begin();
		s.erase(s.begin());
		ans.pb(top); mark[top] = 1;
		
		repVector(v[top]) {
		  deg[*it]--;
		  if(!deg[*it])
		 	s.insert(*it);
		}
	}
}

int main() {
//	INPFILE;
	ll n, m;
	get(n); get(m);
	
	rep(m) {
		ll p, q; get(p); get(q);
		FOR(i,1,q)
		 { ll x; get(x); v[x].pb(p); }
		deg[p] += q;
	}
		
	FOR(i,1,n)
	 if( !deg[i] )
	  s.insert(i);
	
	solve();
	FOR(i,0,ans.size()-1)
	 printf("%ld ", ans[i]);	
}
