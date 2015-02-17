#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
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
	INPFILE;
	ll n, t = 1; get(n);
	while(n--) {
		string s, backup;
		cin >> s;
		
		printf("Case #%lld: ", t++ );
		backup = s;
		
		FOR(i,0,s.size()) {
		  char str = s[i];
		  ll idx = i;
		  
		  FOR(j,i+1,s.size())
			if( str >= s[j] && !( s[j] == '0' && i == 0 ) )
			   str = s[j], idx = j;
		  
		  if( ( i == 0 && str == '0' ) || ( s[i] == s[idx] ) )
			continue;
		  else if( idx != i  )
			 { swap( s[i], s[idx] ); break; }
		}
		
		cout << s << " ";
		s = backup;
		
		FOR(i,0,s.size()) {
		  char str = s[i]; 
		  ll idx = i;
		  
		  FOR(j,i+1,s.size())
			if( str <= s[j] )
			  str = s[j], idx = j;
		
		  if( ( i == 0 && str == '0' ) || ( s[i] == s[idx] ) )
			continue;
		  else if( idx != i  )
			 { swap( s[i], s[idx] ); break; }
		}
		
		cout << s << endl;
		
		
	}
}
