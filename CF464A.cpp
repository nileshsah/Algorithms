#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	ll len = n-1;
	s[len]++;
	
	while( len >= 0 && len < n ) {
		if( s[len] > 'a' + k - 1 ) {
		 s[len] = 'a'; len--;
		 if( len >= 0 )
		  s[len]++;
		}
		else if( len > 0 && s[len] == s[len-1] ) s[len]++;
		else if( len > 1 && s[len] == s[len-2] ) s[len]++;
		else len++;
	}
	
	if( len < 0 )
	 cout << "NO";
	else
	 cout << s;
}
