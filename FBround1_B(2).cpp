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
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll lcp( string a, string b ) {
	
	ll idx = 0;
	FOR(i,0,min(a.size(),b.size())-1)
	 if( a[i] == b[i] )
	 	idx++;
	 else
	 	break;
	
	return idx;
}

int main() {
	INPFILE;
	ll t, w = 1; get(t);
	while(t--) {
		ll n; get(n);
		ll ans = 0;
		set<string> v;
		string s;
		
		FOR(i,1,n) {
			cin >> s;
			
			if(v.find(s) != v.end() )
			  { ans += s.size(); continue; }
			v.insert(s);
			
			set<string>::iterator xt, pt, it = v.find(s);
			xt = pt = it; xt++;
			ll val = 1;
			
			if( xt != v.end() ) {
				ll x = lcp( *xt, s );
				
				if( x == s.size() )
				  val = max(val,x);
				else
				  val = max(val,x+1);
				
			}
			
			if( it != v.begin() ) {
				pt--;
				ll x = lcp( *pt, s );
				
				if( x == s.size() )
				 val = max( val, x );
				else
				 val = max( val, x+1 );
			}
					
			ans += val;   
		
	//		cout << " M: " << ans << endl;
		}
		
		printf("Case #%lld: %lld\n", w++, ans );
	}
}
