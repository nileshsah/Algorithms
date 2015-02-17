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

ll n, m;
int tur[105][105] = {0};
char s[205][205];

ll getTur( ll x, ll y, ll c ) {
	if( tur[x][y] == -1 )
		return -1;
	ll q = tur[x][y];
	c %= 4;
	return ( q + 90*c )%360;
}

bool check( ll x, ll y, ll c ) {
	if( s[x][y] != '.' )
		return false;
	
	FOR(i,x+1,n) {
	 if( s[i][y] == '#' )
	 	break;
	 if( getTur(i,y,c) != -1 )
	 	if( getTur(i,y,c) == 0 )
		 return false;
		else break;
	}
	
	for( ll i = x-1; i >= 1; i-- ) {
	 if( s[i][y] == '#' )
	 	break;
	 if( getTur(i,y,c) != -1 )
	 	if( getTur(i,y,c) == 180 )
		 return false;
		else break;
	}
	
	FOR(i,y+1,m) {
	 if( s[x][i] == '#' )
	 	break;
	 if( getTur(x,i,c) != -1 )
	 	if( getTur(x,i,c) == 270 )
		 return false;
		else break;
	}
	
	for( ll i = y-1; i >= 1; i-- ) {
	 if( s[x][i] == '#' )
	 	break;
	 if( getTur(x,i,c) != -1 )
	 	if( getTur(x,i,c) == 90 )
		 return false;
		else break;
	}
	
	return true;
}

ll ans, finalx, finaly;
set< pair<ll, pair<ll,ll> > > dp;

ll bfs( ll xx, ll yy ) {
	set< pair<ll, pair<ll,ll> > > s;
	s.insert( { 0, {xx,yy} } );
	
	while( !s.empty() ) {
		ll x = s.begin()->S.F;
		ll y = s.begin()->S.S;
		ll c = s.begin()->F;
		s.erase(s.begin());
		
		if( dp.count( { c%4, {x,y} } ) == 0 )
			dp.insert({ c%4, {x,y} });
		else
			continue;
		
		if( x == finalx && y == finaly )
			return c;
		
		if( check(x+1,y,c+1) )
			s.insert( { c+1, { x+1, y } } );
		if( check(x,y+1,c+1) )
			s.insert( { c+1, { x, y+1 } } );
		if( check(x-1,y,c+1) )
			s.insert( { c+1, { x-1, y } } );
		if( check(x,y-1,c+1) )
			s.insert( { c+1, { x, y-1 } } );
		
	}
	
	return -1;
}


int main() {
	INPFILE;
	ll w = 1, t; get(t);
	while(t--) {
		get(n); get(m);
		char str[205][205] = {0};
		dp.clear();
		
		memset( tur, -1, sizeof tur );
		memset( s, 0, sizeof s );
		
		FOR(i,0,n-1)
		  cin >> str[i];
		
		finalx = -1, finaly = -1;
		ll xx = -1, yy = -1;
		
		FOR(i,1,n)
		 FOR(j,1,m) {
		  s[i][j] = str[i-1][j-1];
		  		  
		  if( s[i][j] == '^' )
			tur[i][j] = 0;
		  else if( s[i][j] == '>' )
			tur[i][j] = 90;
		  else if( s[i][j] == '<' )
			tur[i][j] = 270;
		  else if( s[i][j] == 'v' )
			tur[i][j] = 180;
		  else if( s[i][j] == 'S' )
		   { xx = i; yy = j; s[i][j] = '.'; }
		  else if( s[i][j] == 'G' )
		   { finalx = i; finaly = j; s[i][j] = '.'; }	
		}
		
		ll ans = bfs( xx, yy );
		
		printf("Case #%ld: ", w++);
		
		if( ans == -1 )
		 printf("impossible\n");
		else
		 printf("%ld\n", ans);
				
	}
}
