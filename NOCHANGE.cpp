#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<long> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

vector<ll> v;
ll x;
bool flag = 0;

void rec( ll r, ll n, ll sum ) {
	if( sum == x )
	  { cout << "YES"; exit(0); }

	if( flag || sum > x || r >= v.size() )
		return;		
	if( n == 0 )
		return;
	
	for( ll i = min(n,(x-sum)/v[r]); i >= 0; i-- )
	  if( sum + i*v[r] <= x )
		rec( r+1, i, sum + i*v[r] );
	
}

bool solve() {
	ll sum[10] = {0};
	sum[0] = v[0];
	
	FOR(i,1,v.size())
	  sum[i] = sum[i-1] + v[i];
	
	bool dp[100000] = {0};
	dp[0] = 1;
	
	FOR(i,0,x+1)
	 if(dp[i]) 
	  dp[i+v[0]] = 1;
	  
	FOR(k,0,v.size())
	 FOR(i,0,x+1)
	 	if(dp[i] && i+sum[k] <= x )
	 	  dp[i+sum[k]] = 1;
	 	else if( i+sum[k] > x )
	 		break;
	
	return dp[x]; 
}



int main() {
    get(x);
	
	ll n; get(n);
	rep(n)
	 { ll x; get(x); v.pb(x); }
	
	//for( ll i = x/v[0]; i >= 0; i-- )
	//	rec(1,i,i*v[0]);
	
	if( solve() )
		cout << "YES";
	else
		cout << "NO";
	 
}
