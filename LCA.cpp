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
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;
#define MAXN 10005
#define LOGMAX 14

ll n,dep[MAXN],P[MAXN][LOGMAX+1],T[MAXN];
vector<ll> v[10000+5];
bool explore[10000+5] = {0};
ll maxdepth = 0;

void dfs( ll r = 1, ll depth = 0 ) {
	explore[r] = 1;
	dep[r] = depth;
	maxdepth = max( maxdepth, depth );
	
	repVector(v[r])
	  if( !explore[*it] )
	  	{ T[*it] = r; dfs(*it,depth+1); }	
}

 
void Build() {
	memset(P,-1,sizeof P);
	
	for (int i=1;i<=n;i++)
		P[i][0]=T[i];
	
	for (int j=1;j<=log2(n)+1;j++) {
		for (int i=1;i<=n;i++) {
			if (P[i][j-1]!=-1)
				P[i][j]=P[ P[i][j-1] ][j-1];
		}
	}
}
 
int LCA(int v,int u) {
	if (dep[v]>dep[u])
		swap(v,u);
	
	
	ll up = dep[u] - dep[v];
	for( ll i = log2(n) + 1; i >= 0; i-- )
		if( (1<<i) <= up )
		 { up -= (1<<i); u = P[u][i]; }
		
	
	if (v==u)
		return u;
	
	ll i = 0;
	while( P[u][i] != P[v][i] )
	    i++;
	
	return P[u][i]; 
}

int main() {
	ll t, c = 1; get(t);
	while(t--) {
		get(n);
		ll N = n;
		
		rep(n) {
		   v[i].clear();
		   ll len; get(len);
		   FOR(j,1,len)
		    { ll x; get(x); v[x].pb(i); v[i].pb(x); }
		}
		
	
		memset( dep, 0, sizeof dep );
		memset( T, 0, sizeof T );
		memset( explore, 0, sizeof explore );
		maxdepth = 0;
		//One( 1,0,0 );
		dfs();
		Build();
		
		ll m; get(m);
		printf("Case %ld:\n", c++);
		
		rep(m) {
			ll x, y;
			get(x); get(y);
			printf("%ld\n", LCA(x,y));
		}
		
	}
}
