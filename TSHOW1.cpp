#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
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
		ll n; get(n);
		ll num = log2(n+1);
		ll val = n - pow(2,num) + 1;
		
	 	if( n == 1 ) val = 0;
		stack<int> q;
		
		for( ll i = 1, j = 1; j <= num; j++, i *= 2 ) {
			if( val & i )
				q.push(6);
			else
				q.push(5);
		}
		
		while(!q.empty())
		 { printf("%d",q.top()); q.pop(); }
		printf("\n");				
	
	}
}
