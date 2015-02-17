#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
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
	while(1) {
		ll n, m;
		get(n); get(m);
		
		if( n == 0 && m == 0 )
			return 0;
		
		map<string,ll> idx;
		
		rep(n) {
			char str[25];
			scanf("%s", &str);
			string a(str);
			idx[a]++;
		}
		
		ll count[20000+5] = {0};
		
		repSTL(idx)
		   count[it->S]++;
		
		FOR(i,1,n+1)
		 printf("%ld\n", &count[i]);	
		
	}
}
