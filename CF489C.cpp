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

ll n, s;

string rec( ll ptr, ll sum ) {
	if( ptr == 0 )
		return "";
	FOR(i,0,9)
	 if( sum - i >= 0 && sum - i  <= 9*( ptr - 1 ) && !( i == 0 && ptr == n )  )
	 	return  char(i + '0') + rec( ptr-1, sum - i );
	return "";
	   
}

string high( ll ptr, ll sum ) {
	if( ptr == 0 )
	  return "";
	ROF(i,9,0)
	 if( sum - i >= 0 && sum - i <= 9*( ptr - 1 ) && !( i == 0 && ptr == n )  )
	  return char(i+'0') + high( ptr-1, sum-i );
	return "";
}

int main() {
	cin >> n >> s;
	
	string x = rec(n,s);
	string y = high(n,s);
	
	if( n == 1 && s == 0 )
	 { cout << "0 0"; return 0; }
	
	if( x.size() == n  )
	  cout << x << " ";
	else
	  cout << "-1 ";
	
	if( y.size() == n )
	 cout << y << " ";
	else
	 cout << "-1 ";
	 	
}
