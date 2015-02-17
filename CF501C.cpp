#include <bits/stdc++.h>
#define ll long long
#define get(a) cin >> a;
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<string>::iterator it = s.begin(); it != s.end(); it++ )
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
#define INF LONG_MAX
using namespace std;

int main() {
//	INPFILE;
	ll n; cin >> n;
	set< pair< pair<ll,ll>, ll > > v;
	vector< pair<ll,ll> > vex, ans;
	
	FOR(i,0,n-1) {
		ll deg, s;
		cin >> deg >> s;
		v.insert( mp( mp(deg,s), i  ) );
		vex.pb( mp( deg, s ) );
	}
	
	ll count = n;
	
	while( !v.empty() ) {
		pair< pair<ll,ll>, ll > p = *v.begin();
//		cout << "REC: " << p.S << " = " << p.F.F << " " << p.F.S << endl;
//		system("pause");
		if( p.F.F <= 0 )
		 { count--; v.erase(v.begin()); }
		else if( p.F.F == 1 ) {
		   ans.pb( mp(p.S, p.F.S) );
		   v.erase(v.begin());
		   vex[p.S] = mp(-1,-1);
		   
		   v.erase( mp( vex[ p.F.S ], p.F.S ) );
		   vex[ p.F.S ].S ^= p.S;
		   vex[ p.F.S ].F--;
		   
		   if( vex[p.F.S].F > 0 )
		    v.insert( mp( vex[p.F.S], p.F.S ) );
		}
	}
	
	
	cout << ans.size() << endl;
	repVector(ans)
	 cout << it->F << " " << it->S << endl;
		
	 	
	  
	
	
}
