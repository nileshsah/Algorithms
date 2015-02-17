#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
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
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		string s[5];
		FOR(i,0,3) {
			char c[5];
			scanf("%s", &c);
			s[i] = string(c);
		}
		
		ll xc = 0, oc = 0;
		
		FOR(i,0,3)
		  FOR(j,0,3)
		  	if( s[i][j] == 'X' )
		  		xc++;
		  	else if( s[i][j] == 'O' )
		  		oc++;
		if( xc != oc && xc != oc+1 )
			{ printf("no\n"); continue; }
		
		ll xw = 0, ow = 0;
		
		FOR(i,0,3) {
			ll tmp = 0;
		 FOR(j,0,3)
		   if( s[i][j] == s[i][0] )
		   	tmp++;
		 if( tmp == 3 )
		 	if( s[i][2] == 'O' )
		 		ow++;
		 	else if( s[i][2] == 'X' )
		 		xw++;
		}
		
		FOR(i,0,3) {
			ll tmp = 0;
		 FOR(j,0,3)
		   if( s[j][i] == s[0][i] )
		   	tmp++;
		 if( tmp == 3 )
		 	if( s[2][i] == 'O' )
		 		ow++;
		 	else if( s[2][i] == 'X' )
		 		xw++;
		}
		
		if( s[0][0] == s[1][1] && s[0][0] == s[2][2] )
			if( s[0][0] == 'X' )
				xw++;
			else if( s[0][0] == 'O' )
				ow++;
		
		if( s[0][2] == s[1][1] && s[2][0] == s[0][2] )
			if( s[1][1] == 'X' )
				xw++;
			else if( s[1][1] == 'O' )
				ow++;
		
		if( ( ow > 0 && xw > 0 ) || ow > 1 || xw > 2 || ( ow == 1 && oc != xc ) || ( xw == 1 && xc != oc + 1 ) )
		  { printf("no\n"); continue; }
		else
		  { printf("yes\n"); continue; }
		
		
		 
	}
}

