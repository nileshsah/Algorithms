#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
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

void One(int root,int father,int depth) {
	dep[root]=depth;
	T[root]=father;
	
	for (int i=0;i< v[root].size();++i) {
		if (v[root][i]==father) continue;
		One(v[root][i],root,depth+1);
	}
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
	
	
	int up=dep[u]-dep[v];
	for (int i=LOGMAX;i>=0;i--) {
		if ((1<<i)<=up) {
			up-=(1<<i);
			u=P[u][i];
		}
	}
	
	if (v==u)
		return u;
	
	for (int i=log2(n)+1;i>=0;i--) {
		if (P[u][i]!=P[v][i])
			u=P[u][i],v=P[v][i];
	}
	
	return T[u];
}

int main() {
	ll ki;
	get(n); get(ki);
	ll b; get(b);
	
	vector<ll>  k[100+5];
	rep(n-1) { ll x, y; get(x); get(y); v[x].pb(y); v[y].pb(x); }
	
	rep(n) { ll x; get(x); k[x].pb(i+1); }

	//dfs(b);
	One(b,0,0);
	Build();
	
	ll q; get(q);
	while(q--) {
		ll a, p;
		get(a); get(p);
		
		vector< pair<ll,ll> > ptr;
	
		if( k[p].empty() )
		  { printf("-1\n"); continue; }
		  
		bool flag = 0;
		
		FOR(i,0,k[p].size()-1) 
			ptr.pb( mp( dep[ LCA(a,k[p][i]) ], k[p][i] ) );		
		
		 if( !ptr.empty() ) {		
			sort( all(ptr), greater< pair<ll,ll> >() );
			ll e = 0;
			while( e != ptr.size() && ptr[e].F == ptr[0].F )
			  e++;
			  
			printf("%ld\n", ptr[e-1].S);
		}
		else {
			printf("-1\n");
		}
		
		
	}
	
}

