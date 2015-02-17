#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<double> >
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

vector<int> v[10];
char arr[] = { 'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D' };
string a;
int ans[100000+5] = {0};

int dfs( int init, int pos ) {
	if( pos == a.size() )
		return 1;
	//cout << " REC: " << a << endl;
	
	ll p1 = a[pos] - 'A', p2 = a[pos] - 'A' + 5;
	if( find( all(v[init]), p1 )  != v[init].end() )
	  {  ans[pos] = p1; return dfs( p1, pos+1 ); }
	else if( find( all(v[init]), p2 ) != v[init].end() )
	  { ans[pos] = p2; return dfs( p2, pos+1 ); }
	else
		return -1;
}

int main() {
	v[0].pb(4); v[0].pb(1); v[0].pb(5);
	v[1].pb(0); v[1].pb(6); v[1].pb(2);
	v[2].pb(1); v[2].pb(3); v[2].pb(7);
	v[3].pb(2); v[3].pb(4); v[3].pb(8);
	v[4].pb(3); v[4].pb(0); v[4].pb(9);
	v[5].pb(0); v[5].pb(8); v[5].pb(7);
	v[6].pb(9); v[6].pb(8); v[6].pb(1);
	v[7].pb(2); v[7].pb(9); v[7].pb(5);
	v[8].pb(3); v[8].pb(6); v[8].pb(5);
	v[9].pb(4); v[9].pb(6); v[9].pb(7);
	
	
	ll t; get(t);
	while(t--) {
		string pp; cin >> a;
		pp = a;
		ll p1 = a[0] - 'A', p2 = a[0] - 'A' + 5;
		
		ans[0] = p1;
		
		
		if( dfs( p1, 1 ) == 1 )
		 FOR(i,0,a.size())
		  printf("%d", ans[i]);
		else {
			ans[0] = p2;
			if( dfs( p2, 1 ) == 1 )
		 		FOR(i,0,a.size())
		  			printf("%d", ans[i]);
		  	else
		  		printf("-1");
		}
		
		printf("\n");
		
	}
	
}
