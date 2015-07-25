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
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
//	INPFILE;
	ll n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	
	ll start = p-2;
	
	ll ptr = p-1, lptr = n-p;
	ll ans = 0;
	set<ll> v;
	
	ll l, r;
	
	if( p <= n/2 )
	 { l = 0; r = (n-1)/2; }
	else {
	  l = (n-1)/2+1; r = n;
	}
	
	
	while(ptr != start) {
		start = p-1;		
		if( s[ptr] != s[lptr] && ptr >= l && ptr <= r ) 
		   v.insert(ptr);
		ans += min( abs(s[ptr]-s[lptr]), 26-abs(s[ptr]-s[lptr]) );
		ptr = ( ptr + 1 )%n;
		lptr = ( lptr - 1 + n )%n;
	}
	
	ans /= 2;
	if( v.empty() )
	 { cout << "0"; return 0; }
	ll a = *v.begin(); ll b = *v.rbegin();
//	cout << a << " " << b << endl;
	ans += min( abs(a-start), abs(b-start) ) + abs(b-a);
	
	cout << ans;
}
