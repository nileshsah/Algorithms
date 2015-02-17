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

ll tree[10005][3] = {0};
ll maxdp[10005][2] = {0};
ll mindp[10005][2] = {0};

string s;

ll maxdfs( ll r = 1, bool incl = 0 ) {
	if( r == 0 )
		return 0;
	if( maxdp[r][incl] != -1 )
		return maxdp[r][incl];
		
	ll val = 0;
	
	if( incl == 1 )
	  val = 1 + maxdfs( tree[r][0] ) + maxdfs( tree[r][1]) ;
	else
	  val = max(  maxdfs( tree[r][0] ) + maxdfs( tree[r][1], 1 ) , 
	              maxdfs( tree[r][1] ) + maxdfs( tree[r][0], 1 )
			 );
	
//	printf(" REC: %ld - %ld = %ld\n", r, incl, val );
	maxdp[r][incl] = val;
	return val;
}

ll mindfs( ll r = 1, bool incl = 0 ) {
	if( r == 0 )
		return 0;
		
	if( mindp[r][incl] != -1 )
		return mindp[r][incl];
		
	ll val = 0;
	
	if( incl == 1 )	
	   val = 1 + mindfs( tree[r][0] ) + mindfs( tree[r][1]);
	else 
	   val = min(  mindfs( tree[r][0] ) + mindfs( tree[r][1], 1 ) , 
	              mindfs( tree[r][1] ) + mindfs( tree[r][0], 1 )
			 );	
	
//	printf(" REC: %ld - %ld = %ld\n", r, incl, val );
	mindp[r][incl] = val;
	return val;
}


int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		cin >> s;
		s = "0" + s;
		
		memset( maxdp, -1, sizeof maxdp );
		memset( mindp, -1, sizeof mindp );
		memset( tree, 0, sizeof tree );
		
		ll j = 1;
		
		stack< pair<ll,ll> > idx;
		idx.push( mp(1,s[1]-'0') );
		
		while( !idx.empty() ) {
			pair<ll,ll> p = idx.top();
			idx.pop();
			
			if( p.S > 0 ) {
				p.S--;
				idx.push(p);
				tree[p.F][1-p.S] = ++j;
//				cout << char( p.F + 'A' - 1 ) << " " << char(j-1+'A') << endl;
				idx.push( mp(j, s[j]-'0') );
			}
		}
		
		 printf("%ld %ld\n", max(maxdfs(1),maxdfs(1,1)), min(mindfs(1),mindfs(1,1)) );
	}
	
}
