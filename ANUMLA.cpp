#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
using namespace std;
 
ll gcd( ll a, ll b ) { return ( ( b == 0 ) ? a : gcd( b, a%b ) ); }
 
 
int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		ll m = pow(2,n);
		
		vector<ll> v;
		
		rep(m)
		 { ll x; get(x); v.pb(x); }
		
		sort( all(v) );
		
		multiset<ll> s;
		vector<ll> ans, sum;
		ll count = 1;
		ll lcount = 0;
		
		FOR(i,1,v.size()) {
		//	cout << i << endl;
			if( v[i-1] == v[i] ) lcount++;
			else lcount = 1;
			
			ll cc = s.count(v[i]);
			if( cc != 0 )
				if( lcount <= cc ) continue;
		
			 ll tcount = sum.size();
			 FOR(j,0,tcount)
				{  sum.pb( sum[j]+v[i] ); s.insert(sum[j]+v[i]); }
			 s.insert(v[i]); sum.pb(v[i]);
		    
		    
		     ans.pb(v[i]);	
		     if( ans.size() == n ) break;
		}
		
		FOR(i,0,n)
		 printf("%lld ", ans[i]);
		printf("\n");
	}
} 
