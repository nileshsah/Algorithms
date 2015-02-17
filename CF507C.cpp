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
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll h, n;
	cin >> h >> n;
	
	ll temp = n + pow(2,h) - 1;
	string s;
	
	while( temp > 1 ) {
		if( temp%2 == 0 )
			s.pb('L');
		else
			s.pb('R');
		temp /= 2;
	}
	
	reverse( all(s) );
	ll ans = 0;
	
//	cout << s << endl;
	
	FOR(i,0,s.size()-1)
	 if( i == 0 ) {
	  if( s[i] == 'L' )
	  	ans++;
	  else if( s[i] == 'R' )
	  	ans += pow(2,s.size()-i);
	 }
	 else {
	 	if( ( s[i] == 'L' &&s[i-1] == 'R' ) || ( s[i] == 'R' && s[i-1] == 'L' ) )
	 		ans++;
	 	else 
	 		ans += pow(2,s.size()-i);
	 	
//	 	cout << " ANS: " << ans << endl;
	 }
	 
	 cout << ans;
}
