#include <bits/stdc++.h>
#define ll long
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


char A[305][305];

inline void swap( ll &a, ll &b ) {
	ll temp = a;
	a = b;
	b = temp;
}

bool mark[305] = {0};
ll n;
vector<ll> v;


void createSet( vector<ll>& adj, vector<ll>& pos,  ll r ) {
	mark[r] = 1;
	
	FOR(i,1,n)
	 if( !mark[i] && A[r][i] == '1' ) {
	   adj.pb(v[i]); 
	   pos.pb(i);
	   createSet( adj, pos, i );
	 }
 	
}

int main() {
//	INPFILE;
	cin >> n;
	vector<ll> G[305], P[305];
	v.pb(0);
	
	rep(n) { ll x; cin >> x; v.pb(x); }
	
	cin.ignore();
	
	FOR(i,1,n) {
     FOR(j,1,n)
      cin >> A[i][j];
	 }
	 
	
	ll count = 0;
	
	FOR(i,1,n)
	 if( !mark[i] ) {
	 	G[count].pb(v[i]); P[count].pb(i);
	 	
	 	createSet( G[count], P[count], i ); 
	 	
		sort( all(G[count]) );		
		sort( all(P[count]) );
		count++;	
	 }
	 	

	ll ans[500];
	bool visit[400] = {0};
	
	FOR(i,0,count-1) {
		ll c = 0;
	 repVector(G[i])
	 	{  ans[ P[i][c++] ] = *it; }
	}
	
	FOR(i,1,n)
	 cout << ans[i] << " ";
	 
	
	
	
}
