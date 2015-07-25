#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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

int main() {
	string s, t, c;
	cin >> s >> t;
	
	c = s;
	
	ll i = s.size()-1;
	bool flag = 1;
	s[i]++;
	
	while( i >= 0 && s[i] > 'z' ) {
	  if( s[i] >= 'a' && s[i] <= 'z' )
	  	{ flag = 1; break; }
	  	
	  s[i] = 'a';
	  if( i-1 >= 0 )
	  	s[i-1]++;
	  else
	    { flag = 0; break; }

	  i--;
	}
	
//	cout << s << flag;
	
	if( flag && s > c && s < t  )
	 cout << s;
	else
	 cout << "No such string";
}

