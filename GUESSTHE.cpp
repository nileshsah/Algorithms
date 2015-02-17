#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,double> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 10000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll gcd( ll a, ll b ) { return ( b == 0 ? a : gcd(b,a%b) ); }

int main() {
	while(1) {
		string str;
		cin >> str;
		
		if( str[0] == '*' ) return 0;
		bool a[100] = {0};
		ll lcm = 1; bool flag = 1;
		
		FOR(i,0,str.size())
			if( str[i] == 'Y' ) {
				a[i+1] = 1;
				lcm = (lcm*(i+1))/gcd(lcm,i+1);
			}
		
		for( ll k = str.size(); k >= 1; k-- ) {
			if( a[k] == 0 ) continue;
			if( !flag ) break;
		  FOR(i,1,k)
		   if( k%i == 0 && a[i] == 0 )
		   	{ flag = 0; break; }
		}
		
		if( !flag )
			printf("-1\n");
		else if( lcm <= str.size() && a[lcm] == 0 )
			printf("-1\n");
		else 
			printf("%d\n",lcm);
				
	}
}


