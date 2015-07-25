#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define DEBUG(x) cout << "[DEBUG]" << #x << " " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll arr[2005][2005] = {0};
ll parent[2005] = {0};

ll find( ll x ) {
	if( parent[x] != x )
	  parent[x] = find( parent[x] );
	return parent[x];
}

bool join( ll x, ll y ) {
	ll p = find(x);
	ll q = find(y);
	
	if( p == q )
	 return false;
	
	parent[p] = parent[q];
	return true;
}

bool flag = 1;
vector<ll> idx[2005];
bool mark[2005] = {0};

void dfs( ll p, ll x, ll d ) {
	if( mark[x] )
		return;
	mark[x] = 1;
	
	if( d != arr[p][x] )
	 { cout << "NO"; exit(0); }
		
	repVector(idx[x])
	 if( !mark[*it] )
	  dfs( p, *it, d+arr[x][*it] );
	 
}


int main() {
//	INPFILE;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n; cin >> n;
	
	
	FOR(i,1,n) {
	 FOR(j,1,n) 
	  cin >> arr[i][j];
	 parent[i] = i;
    }
	  
	
	vector< pair< ll, pair<ll,ll> > > v;
	
	FOR(i,1,n)
	 FOR(j,i+1,n) {
	  if( arr[i][j] != arr[j][i] )
	  	{ cout << "NO"; return 0; }
	  if( arr[i][j] != 0 )
	  	v.pb( mp( arr[i][j], mp(i,j) ) );
	}
	
	sort( all(v) );
	ll edge = 0;
	
	repVector(v) {
		if( edge == n-1 )
		  break;
		if( join(it->S.F,it->S.S) ) {
		  idx[it->S.F].pb(it->S.S);
		  idx[it->S.S].pb(it->S.F);
		  
//		  cout << it->S.F << " " << it->S.S << endl;
		  edge++;
		}		
	}
	
	if( edge < n-1 )
	 { cout << "NO"; return 0; }
	
	FOR(i,1,n) {
	  memset( mark, 0, sizeof mark );
	  dfs( i, i, 0 );
	}
	
	cout << "YES";
	
	
	
}
