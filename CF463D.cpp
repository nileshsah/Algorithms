#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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

ll v[1005][1005] = {0};
ll pos[6][1005] = {0};
bool mark[1005] = {0};
vector<ll> adj[1005];

ll Ans = 0;
ll Best[1010] = {0};

void DFS(int Node)
{
    mark[Node] = 1;
    for(int i = 0; i < adj[Node].size(); ++ i)
    {
        if(!mark[adj[Node][i]])
            DFS(adj[Node][i]);
        Best[Node] = max(Best[Node], Best[ adj[Node][i] ] + 1);
    }
    Best[Node] = max(Best[Node], 1);
    Ans = max(Ans, Best[Node]);
}

void dfs( ll x, ll d ) {

	Ans = max( Ans, d );
	
	mark[x] = 1;
		
	repVector(adj[x])
	 if( !mark[*it] )
	   dfs( *it, d+1 );
}	

int main() {
	ll n, k;
	cin >> n >> k;
	
	FOR(i,1,k)
	 FOR(j,1,n) {
	  cin >> v[i][j];
	  pos[i][ v[i][j] ] = j;
	}
	
	FOR(i,1,n)
	 FOR(j,1,n) {
	 	
	 	if( i == j ) continue;
	 	bool flag = 1;
	 	
	 	FOR(p,1,k)
	 	 if( pos[p][i] >= pos[p][j] )
	 	   { flag = 0; break; }
	 	
	 	if(flag)
	 	 adj[i].pb(j);
		   
	 }
	 
	 FOR(i,1,n) {
	  memset( mark, 0, sizeof mark );
	  DFS(i);
	 }
	 
	 cout << Ans;
}
