#include <bits/stdc++.h>
#define ll int
#define get(a) cin >> a;
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
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

bool compare( ll a[], ll b [] ) {
	for( ll i = 200; i >= 0; i-- )
		if( a[i] > b[i] )
			return 1;
		else if( b[i] > a[i] )
			return 0;
			
	return 1;
}

int c[300] = {0};

void add( ll a[], ll b[] ) {
	int carry = 0;
	
	FOR(i,0,205) {
	 c[i] = ( a[i] + b[i] + carry )%10;
	 carry = ( a[i] + b[i] + carry )/10;
	}	 
}

void sub( ll a[], ll b[] ) {
	FOR(i,0,205)
	 if( a[i] >= b[i] )
	  { c[i] = a[i] - b[i]; }
	 else
	  { a[i] += 10; a[i+1]--; c[i] = a[i] - b[i]; }
}

void display() {
	bool flag = 0;
	for( ll i = 205; i >= 0; i-- ) {
		if( c[i] != 0 )
			flag = 1;
		if( flag )
		 printf("%d", c[i]);
	}
	
	if(!flag)
	 printf("0");
}

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		string s;
		cin >> s;
		
		vector<int> a, b;
		int aa[300] = {0}, bb[300] = {0};
		char op;	
		ll i = 0;
	
		for( ; i < s.size(); i++ )
		 if( s[i] == '-' )
		  { op = '-'; i++; break; }
		 else if( s[i] == '+' )
		  { op = '+'; i++; break; }
		 else if( isdigit(s[i]) )
		  a.pb(s[i]-'0');
		
		for( ; i < s.size(); i++ )
			b.pb(s[i]-'0');
		
		reverse( all(a) );
		reverse( all(b) );
		
		FOR(i,0,a.size()-1)
		 aa[i] = a[i];
		FOR(i,0,b.size()-1)
		 bb[i] = b[i];
		
		memset( c, 0, sizeof c );
		 
		if( op == '-' ) {
		 if( compare( aa, bb ) )
		  sub( aa, bb );
		 else 
		  { sub( bb, aa ); printf("-"); }
		}
		else
		  add(aa,bb);
		
		display();
		printf("\n");
		 	
		 
	}
}
