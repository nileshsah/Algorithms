#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
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

int main() {
//	INPFILE;
	ll t; cin >> t;
	while(t--) {
		string s;
		cin >> s;
		ll len = s.size()-1;
		
	
		bool flag = 1;
		
		ll win = 0, lose = 0;
		FOR(i,0,len) {
		 if( s[i] == '0' )
		  lose++;
		 else if( s[i] == '1' )
		  win++;
		 if( win >= 11 && lose <= win-2 )
		  { cout << "WIN\n"; flag = 0; break; }
		 if( lose >= 11 && win <= lose-2 )
		  { cout << "LOSE\n"; flag = 0; break; }
//		 debug(win); debug(lose);
		}
		
		if(flag)
		 cout << "LOSE\n";
		
	}
}
