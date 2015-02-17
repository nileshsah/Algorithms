#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
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
	string s;
	cin >> s;
	s = " " + s;
	
	ll val[100005] = {0};
	val[s.size()] = INT_MAX;
	
	vector<ll> v,ans;
	
	ll idx = 0;
	
	FOR(i,1,s.size()-1) {
		if( s[i] == '(' )
			{ val[i] = 1 + val[i-1]; idx++; }
		else if( s[i] == ')' )
			{ val[i] = val[i-1] - 1; idx--; }
		else if( s[i] == '#' )
		  { val[i] = val[i-1]; v.pb(i); }
	}
	
	ll sumB = idx;
	ll hash = v.size();
	reverse(all(v));
	
	if( idx - hash < 0 )
	 { cout << "-1"; return 0; }
	
	ll last = val[s.size()-1];
	ll sum = 0;
	
	repVector(v) {
		ll ptr = *it;
		hash--;
		
		ll x = min( val[ptr-1], val[ptr+1] );
		
		if( x == 0 )
		 { cout << "-1"; return 0; }
		ll use = 0;
		
		if( x <= idx - hash )
			use = x;
		else
			use = idx - hash;
		
		sum += use;
		ans.pb(use);
		idx -= use;
		
	}
	
	if( sum != sumB )
	 { cout << "-1"; return 0; }
	
	reverse(all(ans));
	
	repVector(ans)
	 cout << *it << endl;
	
	  	
}
