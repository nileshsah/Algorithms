#include <bits/stdc++.h>
#define ll long long
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
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

	string s[500];
	ll arr[200][200] = {0};


ll check( ll x, ll y ) {
	
	if( s[x][y] != 'S')
	 return 0;
	 
	set<ll> s;
	s.insert(arr[x-1][y]);
	s.insert(arr[x+1][y]);
	s.insert(arr[x][y+1]);
	s.insert(arr[x][y-1]);
	
	if( *s.begin() == 0 && s.size() == 2 )
	 return *(++s.begin());
	else
	 return 0;
}

int main() {
	ll n, k;
	cin >> n >> k;
	
	bool m = 1;
	
	ll maxx = ceil(1.0*n*n/2);
	
	if( k > maxx )
	 { cout << "NO"; return 0; }
	
	if( k == 0 ) {
	  cout << "YES\n";
	  FOR(i,1,n) {
	   FOR(j,1,n) 
	    cout << "S";
	    cout << "\n";
	   }
	   
	   return 0;
	}
	
	ll i, j, ptr = 0;
	
	for( i = 1; i <= n; i++ )
	 for( j = 0; j < n; j++ ) {
	 //	debug(i); debug(j); debug(m);
	  if( s[i-1][j] != 'L' && s[i][j-1] != 'L')
	   { s[i] += 'L'; ptr++; arr[i][j] = ptr; if(ptr==k) goto bye; }
	  else
	   { s[i] += 'S'; }
	   
	   m = !m;
	 }


bye:
	
	j++;
	
	for( ; i <= n; i++ ) {
	 for( ; j < n; j++ )
	  if( ( s[i-1][j] == 'L' || s[i][j-1] == 'L' ) && ( arr[i-1][j]*arr[i][j-1] == 0 || arr[i-1][j] == arr[i][j-1] )  )
	   { s[i] += 'L'; arr[i][j] = max(arr[i-1][j],arr[i][j-1]); }
	  else
	   s[i] += 'S';
	 j = 0;
	}

	for( i = 1; i <= n; i++ ) {
	 for( j = 0; j < n; j++ )
	  if( check(i,j)  )
	   { arr[i][j] = check(i,j); s[i][j] = 'L'; }
	 j = 0;
	}
	
	cout << "YES\n";	
	FOR(i,1,n) {
	 FOR(j,0,n-1) 
	  cout << s[i][j];
	  cout << "\n";
	}
   	   
	 
}
