#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		string s;
		cin.ignore();
		getline(cin,s);
		ll arr[100] = {0};
		
		FOR(i,0,s.size()-1)
		 arr[tolower(s[i])-'a']++;
		
		ll mx = arr[0], ptr = 0;
		FOR(i,1,25)
		 if( mx <= arr[i] )
		 	{ mx = arr[i]; ptr = i; }
		
		printf("%c\n", char(ptr+'a'));
	}
}
