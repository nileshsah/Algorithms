#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

string dp[10];

int main() {
	
	dp[1] = "1"; dp[2] = "2"; dp[3] = "3";
	dp[4] = "322"; dp[5] = "5"; dp[6] = "53"; dp[7] = "7";
	dp[8] = "7222"; dp[9] = "7332";
	
	ll n; cin >> n;
	string a, ans = "";
	cin >> a;
	
	FOR(i,0,a.size()-1) {
		a[i] -= '0';
		if( a[i] >= 2 && a[i] <= 9 )
		 ans += dp[a[i]];
	}
	
	sort( all(ans), greater<char>() );
	cout << ans;
	
}
