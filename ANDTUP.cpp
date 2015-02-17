#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
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
#include <conio.h>

int main() {
	ll  m = 3;
  FOR(n,0,30) {
  	cout << "\n\nFOR n = " << n <<endl;
	
  	
  	 ll c = 0;
	FOR(i,0,n+1)
	 FOR(j,0,n+1)
	 	FOR(k,0,n+1) 
		  FOR(l,0,n+1){ 
		  
		  if( (i&j) == j && (j&k) == k && (k&l) == l && (i+j+k+l) == n)
		   { c++; cout << i << " " << j << " "<< k << " " << l << "\n"; }

		}
		if( n%1 == 0 ) {
		//cout << "\n\nFOR n = " << n << endl;
		//cout << " " <<"<" << n << "> " << c;
		}
		getch();
 }
}
