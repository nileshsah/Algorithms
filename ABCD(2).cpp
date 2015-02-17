#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
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
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll n;
char ans[50005] = {0};
char str[50005] = {0};
bool flag = 0;

void rec( ll arr[], ll idx ) {
	if( flag )
		return;
	if( idx > n )
		{ flag = 1; return; }
	
	FOR(i,0,3)
	 if( arr[i] < n/2 && ans[idx-1] != char('A'+i) && str[idx-1] != char('A'+i)  ) {
	 	arr[i]++;
	 	ans[idx] = 'A' + i;
	 	rec( arr, idx+1 );
	 	arr[i]--;
	 	
	 	if( flag ) return;
	 }
}

int main() {
	get(n); n *= 2;
	scanf("%s", &str);
	
	ll arr[4] = {0};
	rec( arr, 1 );
	
	FOR(i,1,n)
	 printf("%c", ans[i]);		
}
