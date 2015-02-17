#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll p[100005] = {0};
vector<ll> adj[100005];

void conq( ll, ll, vector< pair<ll,ll> >& );

void divide( ll start, ll end, vector< pair<ll,ll> >& v ) {
	if( start >= end )
		return;
	ll mid = ( start + end )/2;
	divide( start, mid, v );
	divide( mid+1, end, v );
	conq( start, end, v );
}

void conq( ll start, ll end, vector< pair<ll,ll> >& v ) {
	
	ll mid = ( start + end )/2;
	vector< pair<ll,ll> > fa, la;

	FOR(i,start,mid)
	 fa.pb( v[i] );
	fa.pb( mp(-1,-1) );
   
    FOR(i,mid+1,end)
     la.pb( v[i] );
	la.pb( mp(-1,-1) );
	
	ll f, l; f = l = 0;
	
	FOR(i,start,end)
	 if( fa[f].F > la[l].F ) {
	   p[fa[f].S] += la.size()-l-1;
	   FOR(k,l,la.size()-2)
		adj[fa[f].S].pb(la[k].S);	   
	   v[i] = fa[f++];
	 }
	 else 
	 	v[i] = la[l++];
}


int main() {
	ll n; get(n);
	vector< pair<ll,ll> > v;
	
	FOR(i,1,n)
	 { ll x; get(x); v.pb( mp(x,i) ); }
	divide( 0, n-1, v );
	
	ll ans = 0;
	
	FOR(i,1,n) {
//	 cout << "LVL: " << i << " = ";
	 repVector(adj[i])
	 	{ ans += p[*it]; }
//	 cout << "  ANS: " << ans << endl;
	}	
	
	cout << ans;
	
}
