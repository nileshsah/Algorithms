#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;
#define gc getchar_unlocked

ll n;
vector<ll> idx;
bool mark[205] = {0};


ll gcd(ll a, ll b)
{
  if (a < b)
  {
    a += b;
    b = a - b;
    a -= b;
  }
      
  if (b == 0) return a;
 
  while ( a % b != 0 )
  {
    a += b;
    b = a - b;
    a -= b;
    b %= a;
  }
  return b;
}

ll solve( ll num ) {
	queue<ll> q;
	q.push(num);
	
	ll val = num;
	
	while(!q.empty()) {
	 ll top = q.front();
	 q.pop();
	 
	 FOR(i,0,n-1)
	  if( !mark[i] && gcd(top,idx[i]) > 1 ) {
	  	val = max(val,idx[i]);
	  	q.push(idx[i]);
	  	mark[i] = 1;
	  }
	  
	}
	
	return val;
}

int main() {
	ll t; get(t);
	while(t--) {
		get(n);
		idx.clear();
		memset( mark, 0, sizeof mark );
		 
		FOR(i,1,n)
		 { ll x; get(x); idx.pb(x); }
		
		ll c = 1;
//		sort( all(idx) );
	
		long long ans = 1;
		
		FOR(i,0,n-1)
		 if( !mark[i] )
		 	{ mark[i] = 1; ans *= solve(idx[i]); while( ans >= MOD ) ans -= MOD; }
			
		printf("%lld\n", ans);
		
	}
}
