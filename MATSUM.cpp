#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<double> >
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll tree[1030][1030] = {0}, mat[1030][1030];
int N;

void update( int i, int j, int val ) {
	for( int x = i; x <= N; x += x&(-x) )
	  for( int y = j; y <= N; y += y&(-y) )
	  		{  tree[x][y] += val; 
			//	printf("[%d][%d] = %d \n", x, y, tree[x][y]);  
			}
}

int sum( int i, int j ) {
	ll ans = 0;
	for( int x = i; x > 0; x -= x&(-x) )
	 for( int y = j; y > 0; y -= y&(-y) )
	 	{ //printf("[%d][%d] = %d \n", x, y, tree[x][y]); 
		   ans += tree[x][y]; 
		}
	return ans;
}

int main() {
	int t;
	get(t);
	while(t--) {
		memset( tree, 0, sizeof tree );
		memset( mat, 0, sizeof mat );
		get(N);
		while(1) {
			char str[30];
			scanf("%s", &str);
			string opt(str);

			if( opt == "SET" ) {
				ll x, y, val;
				get(x); get(y); get(val);
				x++; y++;
				update( x, y, val - mat[x][y] );
				mat[x][y] = val;
			}
			else if( opt == "SUM" ) {
				ll x1, y1, x2, y2;
				get(x1); get(y1); get(x2); get(y2);
				x1++; x2++; y1++; y2++;
				
				ll ans = 0;
				ans += sum( x2, y2 );
				ans -= sum( x1-1, y2 );
				ans -= sum( x2, y1-1 );
				ans += sum( x1-1, y1-1 );
				
				printf("%ld\n", ans);
				
			}
			else if( opt == "END" ) { break; }
		}
		printf("\n");
	}
	
}
