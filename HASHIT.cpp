#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( multiset<ll>::iterator it = s.begin(); it != s.end(); it++ )
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

ll getkey( string s ) {
	ll ans = 0;
	FOR(i,0,s.size()-1)
		{ ans += s[i]*(i+1); ans %= 101; }
	ans *= 19; ans %= 101;
	return ans;
}


int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		string hash[101];
		ll count = 0;
		
		rep(n) {
			char str[100];
			scanf("%s", &str);
			string s(str);
			
			if( s.substr(0,3) == "ADD" ) {
				string a = s.substr(4);
				ll key = getkey(a)%101;
				bool flag = 0;
				
				FOR(j,0,19) {
					ll x = ( key+j*j+23*j )%101;
				  if( !hash[x].empty() && hash[x] == a )
				  	{ flag = 1; break; }
				}
				
				if( !flag )
				 FOR(j,0,19) {
					ll x = ( key+j*j+23*j )%101;
				    if( hash[x].empty() )
				    	{  hash[x] = a; count++; break; }
				 }
			}
			else if( s.substr(0,3) == "DEL" ) {
				string a = s.substr(4);
				ll key = getkey(a)%101;
				FOR(j,0,19) {
					ll x = ( key+j*j+23*j )%101;
				  if( !hash[x].empty() && hash[x] == a )
				  	{ hash[x].clear(); count--; break; }
				}
			}
				
		}
		
		printf("%ld\n", count);
		FOR(i,0,100)
		  if( !hash[i].empty() )
		  	printf("%ld:%s\n",i,hash[i].c_str());
		
	}
}
