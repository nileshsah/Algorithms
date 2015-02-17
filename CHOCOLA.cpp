#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
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
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll gcd( ll a, ll b ) {  return ( b == 0 ? a : gcd( b, a%b ) ); }

int main() {
	ll t; get(t);
	
   while(t--) {
   	 ll n, m;
   	 vector< pair<ll,char> > v;
   	 get(m); get(n);
   	 
   	 rep(m-1)
   	  { ll x; get(x); v.pb( mp(x,'x') ); }
   	 rep(n-1)
   	  { ll x; get(x); v.pb( mp(x,'y') ); }
   	 sort( all(v) , greater< pair<ll,char> >() );
   	 
   	 ll xc = 1, yc = 1;
   	 ll sum = 0;
   	 
   	 FOR(i,0,v.size()) {
   	 	if( v[i].second == 'x' )
   	 	 { sum += v[i].first * xc; yc++; }
   	 	else 
   	 	 {  sum += v[i].first * yc; xc++; }
	 }
	 
	 	printf("%ld\n", sum);
	 
   	 
   	 
   }
   
}
