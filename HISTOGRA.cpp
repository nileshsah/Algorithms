#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<int>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define L 2*r
#define R 2*r+1
using namespace std;

int main() {
	while(1) {
		ll n;
		ll maxo = 0;
		get(n);
		vector< pair<ll,ll> > v;
		stack< pair<ll,ll> > s;
		
		if( n == 0 )
			return 0;
		
		rep(n) {
		 ll x; get(x);
		 v.pb( make_pair( x, i+1 ) );
		}
		
		v.pb( make_pair( -1, n+1 ) );
		s.push(v[0]);
		
		FOR(i,1,n+1) {
			if( s.top().first <= v[i].first )
				s.push(v[i]);
			else {
				pair<ll,ll> p;
				while( !s.empty() && s.top().first > v[i].first ) {
				    p = s.top(); s.pop(); 
					ll w = v[i].second - p.second;
					if( v[i].first >= p.first ) w++;
					ll ar = p.first*w;
					maxo = max( maxo, ar );
				}
				s.push(v[i]);
			}
			
		}	
		
		printf("%lld\n", maxo );
		
	}
}
