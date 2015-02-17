#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

struct node {
	ll p, c, f;
};

ll p, f, c;
vector<node> v;
bool flag = 0;

void rec( ll x, node q ) {
	if( flag )
		return;
	if( q.p == p && q.f == f && q.c == c )
		{ flag = 1; return; }
	if( q.p > p || q.f > f || q.c > c )
		return;
	if( x >= v.size() )
		return;
	
	node a;
	a.p = q.p + v[x].p; a.f = q.f + v[x].f; a.c = q.c + v[x].c;
	rec( x+1, a );
	rec( x+1, q );
}

int main() {
	INPFILE;
	ll t, itr = 1; get(t);
	while(t--) {
		get(p); get(c); get(f);
		ll n; get(n);
		v.clear();
		flag = 0;
		
		rep(n) {
		   ll pp, ff, cc;
		   get(pp); get(cc); get(ff);
		   
		   node q;
		   q.p = pp; q.f = ff; q.c = cc;
		   v.pb(q);	   
		}
		
		node q;
		q.p = q.f = q.c = 0;
		rec( 0, q );
		
		if(flag)
		 printf("Case #%ld: yes\n", itr++ );
		else
		 printf("Case #%ld: no\n", itr++ );
		
	}
}
