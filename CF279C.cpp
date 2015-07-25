#include <bits/stdc++.h>
#define ll long
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



int main() {
//	INPFILE;
	ll n, m;
	cin >> n >> m;

	ll v[100005] = {0};
	ll inc[100005] = {0};
	ll dec[100005] = {0};
	ll equ[100005] = {0};
	
	FOR(i,1,n) {
	 cin >> v[i];
	 inc[i] = i;
	 dec[i] = i;
	 equ[i] = i;
	}
	
	ROF(i,n-1,1)
	 if( v[i] <= v[i+1] )
	  inc[i] = inc[i+1];
	FOR(i,2,n) {
	 if( v[i] <= v[i-1] )
	  dec[i] = dec[i-1];
     if( v[i] == v[i-1] )
      equ[i] = equ[i-1];
  	}
	  
/*	FOR(i,1,n)
	 cout << inc[i] << " ";
	cout << "\n";
	FOR(i,1,n) 
	 cout << dec[i] << " ";
	cout << "\n";
*/	 
	while(m--) {
	   ll l, r;
	   cin >> l >> r;
	   if( inc[l] >= dec[r] || equ[l] == equ[r] )
	    cout << "Yes\n";
	   else
	    cout << "No\n";
	}
}
