#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
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
	//INPFILE;
	ll n, m;
	cin >> n >> m;
	char str[105][105] = {0};
	char dp[105][105] = {0};
	
	FOR(i,1,n)
	 FOR(j,1,m)
	  cin >> str[i][j];	 
	
	ll count = 0;
	
	FOR(i,1,n) {
	 FOR(j,1,m) {
	 	count++;
	  if( str[i][j] == '.' ) {
	  	if( count%2 != 0 )
	  		cout <<"B";
	  	else
	  		cout <<"W";
	  }
	  else
	    cout << "-";
	   }
	   if( m%2 == 0 )
	    count++;
	   cout <<endl;
	}
	  	
	
}

