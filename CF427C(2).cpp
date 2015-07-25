#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
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

stack<ll> s;
ll parent[100005] = {0};
ll index[100005] = {0}, ptr = 0, ans = 1, sum = 0;
ll cost[100005] = {0};
bool cycle[100005] = {0};
vector<ll> v[100005];

void dfs( ll x ) {
    parent[x] = index[x] = ++ptr;
    cycle[x] = 1;
    s.push(x);
    
    repVector(v[x])
     if( index[*it] == 0 ) {
     	dfs(*it);
     	parent[x] = min(parent[x],parent[*it]);
	 }
	 else if( cycle[*it] ) 
		parent[x] = min(parent[x],parent[*it]);
	 
	 if( parent[x] == index[x] ) {
	 	ll val = LONG_MAX, cnt = 0;
	 	vector<ll> p;
	   while(1) {
	   	  p.pb(s.top());
	   	  cycle[s.top()] = 0;
	   	  s.pop();
	   	  val = min(val,cost[p.back()]);
	   	  if( p.back() == x )
	   	   break;
	   }
	    sum += val;
		repVector(p)
		 if( cost[*it] == val )
		  cnt++;
		ans *= cnt;
		ans %= MOD;
	}
	   
	 
}


int main() {
//	INPFILE;
	
	ll n; cin >> n;
	
	FOR(i,1,n)
	 cin >> cost[i];
	
	ll m; cin >> m;
	while(m--) {
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
	}
	
	FOR(i,1,n)
	 if( index[i] == 0 ) {
	  dfs(i);
	 }
	
	
	cout << sum << " " << ans;
}
