#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
//	INPFILE;
  ll t; get(t);
  while(t--) {
	ll n, k;
	get(n); get(k);
	vector<ll> v;
	ll sum = 0;
  	
  	rep(k)
	   { ll x; get(x); v.pb(x); sum += x; } 
	
	ll arr[100005] = {0};
	
	if( !v.empty() )
	 { sort( all(v) ); arr[0] = v[0]; }
	
   if( !v.empty() )	
	FOR(i,1,v.size()-1)
	 	arr[i] = arr[i-1] + v[i];
	
	bool flag = 0;
	
	ll ans = 0;
	
   if( !v.empty() )
	FOR(i,0,v.size()-1)
	 if( v[i] > ( v[i]*(v[i]+1) )/2 - arr[i] )
	  { ans = v[i]; flag = 1; break; }
	
	if(!flag)
	  ans = (n*(n+1))/2 - sum + 1;
	
//	cout << ans;
	
	if( ans%2 == 0 )
		printf("Mom\n");
	else
		printf("Chef\n");
	 
  }
  
  
}
