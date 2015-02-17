#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
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

ll v[505] = {0};
ll adj[505][505] = {0};
vector<ll> edge[505];

double f( ll v, ll e ) {
	if( e == 0 )
		return 0;
	else
		return (v/double(e));
}

bool mark[505] = {0};

pair<ll,ll> dfs( ll r, ll vc, ll ec ) {
	mark[r] = 1;
	double cur = f(vc,ec);
	vector< pair<ll,ll> > idx;
	pair<ll,ll> cur_p = mp(vc,ec);
	
	repVector(edge[r]) 
	  if( !mark[*it] ) {
		 pair<ll,ll> p = dfs( *it, v[*it], adj[r][*it] );
		 idx.pb( mp( p.F, -p.S ) );
     }
     
     sort( all(idx), greater< pair<ll,ll> >() );
     
     repVector(idx) {
     	pair<ll,ll> p = *it;
     	p.S = -p.S;
       if( f( p.F + cur_p.F, p.S + cur_p.S ) > cur ) {
		 	cur = f( p.F + cur_p.F, p.S + cur_p.S );
		 	cur_p.F += p.F; cur_p.S += p.S;
		}
	 }
     
   cout << " REC: " << r << " " << vc << " " << ec << " = " << cur << endl;
    return cur_p;
}

int main() {
	INPFILE;
	ll n, m;
	cin >> n >> m;
	
	rep(n)
	 get(v[i]);
	rep(m) {
		ll x, y, c;
		cin >> x >> y >> c;
		adj[x][y] = adj[y][x] = c;
		edge[x].pb(y); edge[y].pb(x);
	}
	
	double ans = 0;
	
	FOR(i,1,n) {
	  memset( mark, 0, sizeof mark );
	  pair<ll,ll> tmp = dfs(i,v[i],0);
	  double temp = f(tmp.F,tmp.S);
	  ans = max( temp, ans );
	 }
	
	printf("%0.15lf", ans);
	
	
}

