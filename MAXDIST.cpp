#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) ;//cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<ll> v[10005];
ll init = 1, initlvl = 1;
ll depth[10005] = {0};
bool explore[10005] = {0};

#define MAXN 10005
#define LOGMAX 14
 
ll n,dep[MAXN],P[MAXN][LOGMAX+1],T[MAXN];
 
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

ll dfs( ll x, ll lvl = 1 ) {
	explore[x] = 1;
	depth[x] = lvl;
	
	
	if( lvl > initlvl )
	 { init = x; initlvl = lvl; }
	 
	repVector(v[x])
	 if( !explore[*it] || lvl < depth[*it] )
	  dfs( *it, lvl+1 );
}


int main() {
//	INPFILE;
	ll t; cin >> t;
	while(t--) {
	  init = 1; initlvl = 0;
		memset( depth, 0, sizeof depth );
		memset( dep, 0, sizeof depth );
		memset( T, 0, sizeof depth );
		memset( P, 0, sizeof depth );
		memset( explore, 0, sizeof depth );
		
	  cin >> n;
	  FOR(i,1,n-1) {
	  	ll x, y;
	  	cin >> x >> y;
	  	v[x].pb(y);
	  	v[y].pb(x);
	  }
	  
	  vector<ll> pos;
	  pos.pb(1);
	  
	  dfs( 1, 1 );  
	 
	  ll inix = init;
	  	 
	  memset( explore, 0, sizeof explore );
	  initlvl = 0;
	  dfs( inix, 1 );
		  
	  One(init,0,0);
	  Build();
	  
	  debug(inix);
	  
	  ll o = LCA(inix,v[inix][0]);
	  ll maxc = v[o].size(),  f = inix;
	  
	  debug(maxc);
	  	  
	  FOR(i,1,n) {
//	  	cout << "\n R: " << i <<  " " <<  depth[i] << " " << v[ LCA(i,v[i][0]) ].size();
	   if( depth[i] == initlvl && v[ LCA(i,v[i][0]) ].size() < maxc )
	    { maxc =  v[ LCA(i,v[i][0]) ].size(); f = i; }
	  }
	  
	  if( f != inix ) {
	  	inix = f;
	  	memset( explore, 0, sizeof explore );
	    initlvl = 0;
	    dfs( inix, 1 );
	   
	   One(inix,0,0);
	   Build();
	
	 }
	
	  	     
	  vector<ll> vec;
	  ll maxdepth = 0;
	  
/*	  FOR(i,1,n)
	   cout << depth[i] << " ";
	  cout << "\n";
*/
	  
	  FOR(i,1,n)
	   if( depth[i] > maxdepth ) {
	   	vec.clear();
	   	vec.pb(i);
	   	maxdepth = depth[i];
	   }
	   else if( depth[i] == maxdepth )
	    vec.pb(i);
	  
	  debug(vec.size());
	  
	  if( vec.size() == 1 && depth[vec[0]] > 2 )
	   printf("YES\n");
	  else if( vec.size() == 1 && depth[vec[0]] == 2 )
	   printf("NO\n");
	  else {
	  	
	  	ll p = LCA(vec[0],vec[1]);
	  	FOR(i,2,vec.size()-1)
	      p = LCA(vec[i],p);
	    
	    if( depth[p] > 2 )
	     printf("YES\n");
	    else
	     printf("NO\n");

	     
	  }
	  
	  FOR(i,1,n)
	   v[i].clear();
	  
	}
}
