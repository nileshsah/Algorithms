#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll arr[2005][2005] = {0};

int main() {
//	INPFILE;
	ll n; cin >> n;
	
	FOR(i,1,n)
	 FOR(j,1,n)
	  cin >> arr[i][j];
	
	FOR(i,1,n)
	 if( arr[i][i] != 0 )
	  { cout << "NO"; return 0; }
	
	FOR(i,1,n) {
	  ll deg = 0;
	 FOR(j,1,n)
	  if( arr[i][j] != 0 )
	  	{ deg = 1; break; }
	 if( !deg )
	  { cout << "NO"; return 0; }
	}
	
	FOR(i,1,n) 
	 FOR(j,i+1,n) {
	    	
	  if( arr[i][j] != 0 )
	   FOR(k,j+1,n)
	    if( arr[j][k] != arr[i][j] + arr[i][k] )
	     { cout << "NO"; return 0; }
    
	  if( arr[i][j] != arr[j][i] )
      	{ cout << "NO"; return 0; }
   }
	  
	
	cout << "YES";
}
