#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll c[100005] = {0};
ll r[100005] = {0};
ll parent[100005] = {0};
ll arr[100005] = {0};
bool mark[100005] = {0};
bool cycle[100005] = {0};
bool chk[100005] = {0};


ll find( ll x ) {
  if( parent[x] == x ) 
   return x;
  else
   return parent[x] = find( parent[x] );
}

ll join( ll x, ll y ) {
	ll p = find(x);
	ll q = find(y);
	
	parent[p] = parent[q];
	r[ find(p) ] = r[p] + r[q];
}

void dfs( ll x ) {
	stack<ll> s;
	cycle[x] = 1;
	chk[x] = 1;
	s.push(x);
	
	while(!s.empty()) {
	  if( cycle[ arr[x] ] ) {
	  	while( s.size() > 0 && !(s.top() == arr[x]) ) {
	  	 join(arr[x],s.top());
	  	 s.pop();
	  	}
	  	return;
	  }
	  
	  s.push( arr[s.top()] );
	  cycle[s.top()] = 1;
	  chk[s.top()] = 1;
	}	   
}

ll mx = 0;

ll getCost( ll x ) {
	x = find(x);
	
	if( mark[x] )
	 return 0;
	mark[x] = 1;
//	cout << "R: " << x << " -- \n";
    if( c[x] != -1 )
     return c[x];
 	
    ll q = getCost(arr[x]);
    mx = max( r[x]+q, max(mx,q) );
    
  //  cout << "R: " << x << " Q: " << q << "\n";
    return c[x] = q+r[x];
}




int main() {
	ll tt; get(tt);
	
	while(tt--) {
		memset( mark, 0, sizeof mark );
		memset( c, -1, sizeof c );
		memset( cycle, 0, sizeof cycle );
		memset( chk, 0, sizeof chk );
		ll n; get(n);
		
		FOR(i,1,n) {
		 get(arr[i]);
		 parent[i] = i;
		}
	
		FOR(i,1,n)
		 get(r[i]);
		
		ll sum = 0;
		
		FOR(i,1,n) {
		   ll k = find(i);
		 if( mark[k] )
		  continue;
		 if(!chk[k])
		  dfs(k);
		 mx = 0;
		 ll x = getCost(k);
		 sum += mx;
		}
		
		cout << sum << "\n";
				
	//	debug(t); 
	}
}
