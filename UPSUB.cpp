#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
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

set<string> ans;
ll maxx = 0;
string s;
ll arr[105] = {0};


void rec( ll r, ll x, string idx ) {
//	cout << " REC: " << r << " " << x << " = " << idx << endl;
	
	if( idx.size() == maxx )
	 { ans.insert(idx); return; }
	 
	FOR(i,x,s.size()-1)
     if( idx[idx.size()-1] <= s[i] && arr[i] == r ) {
	 	string temp = idx;
	 	temp.pb(s[i]);
	 	rec( r+1, i+1, temp );
	 }
	 	
}

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		char str[105];
		scanf("%s", str);
		
		s = string(str);
		arr[0] = 1; maxx = 0;
		ans.clear();
		memset( arr, 0, sizeof arr );
		
		FOR(i,0,s.size()-1) {
		  arr[i] = 1; ll mx = 0;
		 for( ll j = i-1; j >= 0; j-- )
		 	if( s[i] >= s[j] )
		 	  mx = max( mx, arr[j]);
		  arr[i] += mx;
		 maxx = max( maxx, arr[i] );
//		 cout << arr[i] << " ";
		}
		
		FOR(i,0,s.size()-1)
		 if( arr[i] == 1 ) {
		 	string temp; temp.pb(s[i]);
		 	rec( 2, i+1, temp );
		 }
		 
		repSet(ans)
		 printf("%s\n", it->c_str());
		
	}
}
