#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define L 2*r
#define R 2*r+1
using namespace std;

vector<ll> p, adj[10000];

void sieve() {
	bool prime[10000] = {0};
	
	FOR(i,2,10000)
	 if( prime[i] == 0 ) {
	 	if( i >= 1000 )
	 		p.pb(i);
		for( ll k = i*i; k < 10000; k += i )
		 prime[k] = 1;
	 }
}

bool check( ll a, ll b ) {
	ll count = 0;
	FOR(i,0,4) {
	 if( a%10 != b%10 )
	 	count++;
	  a /= 10; b /= 10;
    }
    
    if( count == 1 )
    	return true;
    else 
    	return false;
}

ll dp[10000];
bool explore[10000] = {0};

void dijkstra( ll a ) {
	repVector( adj[a] )
	 if( dp[*it] > dp[a]+1 ) {
	 	dp[*it] = dp[a]+1;
	 	dijkstra(*it);
	 }
}



int main() {
	sieve();
	FOR(i,0,p.size())
	 FOR(j,i+1,p.size())
	 	if( check(p[i],p[j]) )
	 		{ adj[p[i]].pb(p[j]); adj[p[j]].pb(p[i]); }
	ll n;
	get(n);
		
	while(n--) {
		ll a, b;
		get(a); get(b);
		memset( dp, 1e4 , sizeof dp );
		memset( explore, 0, sizeof explore );
		dp[a] = 0;
		explore[a] = 1;
		queue<ll> q;
	    repVector( adj[a] )
	     q.push(*it);
		
		dijkstra(a);
		printf("%ld\n", dp[b]);		
	}
}
