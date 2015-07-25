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
	INPFILE;
	ll t; get(t);
	while(t--) {	
		ll n, D; get(n);
		vector<ll> A, B;
		
		FOR(i,1,n)
		 { ll x; get(x); A.pb(x); }
		FOR(i,1,n)
		 { ll x; get(x); B.pb(x); }
		
		get(D);
		
		vector< pair<ll,ll> > v;
		
		FOR(i,0,n-1) {
		   ll steps =  D/(A[i]-B[i]);
		   steps *= A[i]+B[i];
		   cout << "ST: " << steps << endl;
		   v.pb( mp(steps,i) );
		}
		
		sort( all(v) );
		cout << v[0].F << " " << v[0].S+1 << endl;	
	}
}
