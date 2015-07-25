#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
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
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<ll> s[1000000];

int main() {
	ll n, m;
	cin >> n >> m;
	
	FOR(i,1,n)
	 s[i].pb(i);
	
	while(m--) {
		string str; ll a, b;
		cin >> str >> a >> b;
		
		if( str == "UNION" ) {
			n++;	
			s[n].resize( s[a].size() + s[b].size() );
			merge( all(s[a]), all(s[b]), s[n].begin() );
		}
		else 
		 cout << s[a][b-1] << "\n";
		
	}
}
