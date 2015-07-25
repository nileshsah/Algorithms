#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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
	ll t; cin >> t;
	while(t--) {
		string s; cin >> s;
		ll c[305] = {0};
		queue<char> q;
		
		sort( all(s) );
		set< pair<ll,ll> > idx;
		
		FOR(i,0,s.size()-1) {
		  c[ s[i] ]++;
		}
		
		bool flag = 1;
		
		FOR(i,'a','z') {
		 if( c[i] != 0 )
		  idx.insert( mp(-c[i],i) );
		 if( c[i] != 0 && c[i] - 1 > s.size() - c[i] )
		  flag = 0;
		}
		
		if( !flag )
		 { cout << "-1\n"; continue; }
		
		char last = '*';
		
		while(!idx.empty())
		 if( last != idx.begin()->S ) {
		  cout << char(idx.begin()->S);
		  last = char(idx.begin()->S);
		  ll cc = idx.begin()->F + 1;
		  idx.erase(idx.begin());
		  if( cc != 0 )
		  idx.insert( mp(cc,last) );
		 }
		 else {
		 	set< pair<ll,ll> >::iterator it = idx.begin();
		 	it++;
		 	cout << char(it->S);
		 	last = char(it->S);
			ll cc = it->F + 1;
			idx.erase(it);
			if( cc != 0 )
			idx.insert( mp(cc,last) );
		 }
		  
		
		cout << "\n";
	}
}
