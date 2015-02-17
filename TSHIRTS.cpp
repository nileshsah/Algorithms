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

vector<ll> v[105];
ll n;

ll dp[105][1050];


ll rec( ll r, ll bit ) {
//	cout << " REC: " << r << " " << bit << endl;	
	if( bit == pow(2,n+1)-2 && r > 100 )
		return 1;
	if( r > 100 )
		return 0;
	if( dp[r][bit] != -1 )
		return dp[r][bit];
	
	ll ans = 0;
	
	repVector(v[r]) {
		if( !( bit&(1LL<<(*it)) ) )
		  { ans += rec( r+1, (bit|(1LL<<(*it))) ); ans %= MOD; }
	}	
	ans += rec( r+1, bit );
	ans %= MOD;
	
	 dp[r][bit] = ans;
	 return ans;  
}


int main() {
	ll t; get(t);
	while(t--) {
		get(n);
		cin.ignore();
		memset( dp, -1, sizeof dp );
		
		FOR(i,1,n) {
			string s;
			getline(cin,s);
			ll val = 0;
		
			FOR(k,0,s.size()) {
				if(  k == s.size() || s[k] == ' ' )
				  { v[val].pb(i);  val = 0; }
				else if( isdigit(s[k]) )
				  { val *= 10; val += s[k] - '0'; }
			}
			
		}
		
		FOR(i,1,100)
		 sort( all(v[i]) );
				
		printf("%lld\n", rec(1,0)%MOD );
		
		FOR(i,1,100)
		 v[i].clear();

		 
	}
}
