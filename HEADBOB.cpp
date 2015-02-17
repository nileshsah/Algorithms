#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll n;
		get(n);
		ll i = 0,y = 0;
		string a;
		cin >> a;
		
		FOR(k,0,a.size()) {
		 if( a[k] == 'I' ) i++;
		 else if( a[k] == 'Y') y++;
		}
		
		if( y == 0 && i == 0 )
			printf("NOT SURE\n");
		else if( y == 0 && i > 0 )
			printf("INDIAN\n");
		else if( i == 0 && y > 0 )
			printf("NOT INDIAN\n");
		else
			printf("NOT SURE\n");
		 
	}
}
