#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define repSTL(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

double a[105][105];

int main() {
	ll t; get(t);
	while(t--) {
		ll s, c;
		get(s); get(c);
		
		memset( a, 0, sizeof a );
		rep(s) scanf("%lf", &a[i][0]);
		
		FOR(i,1,s-1) {
		  FOR(j,i,s) {
		  	a[j][i] = -double( a[j-1][i-1] - a[j][i-1] )/double(i) ;
		    //cout << a[j][i] << " ";
		  }
		//cout << "\n";
		}
		
		rep(c) {
			ll x = s + i + 1;
			double mul = 1;
			double ans = 0;
			
			FOR(j,0,s-1) {
				ans += double(mul)*a[j][j];
				mul *= double(x - j - 1);
			}
			
			cout << ans << " ";
			
		}
		
		printf("\n");
		
		 
	}	
}
