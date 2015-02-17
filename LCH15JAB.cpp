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

int main() {
	ll t; get(t);
	while(t--) {
		char str[55];
		scanf("%s", &str);
		
		string s(str);
		ll sum = s.size();
		ll arr[27] = {0};
		
		FOR(i,0,s.size()-1)
		 arr[ s[i] - 'a' ]++;
		
		bool flag = 0;
		
		FOR(i,0,26)
		 if( sum - arr[i] == arr[i] )
		 	{ flag = 1; break; }
		
	    if( flag )
		 printf("YES\n");
		else	
		 printf("NO\n");
		
	}
}
