#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

string a, b;
ll dp[100][100] = {0};
ll lcs = 0;

set<string> v;

int LCS(int i, int j) {
	int ret = dp[i][j];
	if(i==a.size() || j==b.size()) return ret = 0;
	if(ret != -1) return ret;
	ret = 0;
	if(a[i]==b[j]) ret = 1 + LCS(i+1, j+1);
	else ret = max(LCS(i+1, j), LCS(i, j+1));
	return ret;
}


void rec( string str, ll x, ll y, ll d = 0) {
//	printf(" REC: %ld %ld = %ld\n", x,y,d );
	if( str.size() == lcs )
	 { printf("%s\n", str.c_str()); return; }
	
   FOR(c,'a','z'+1)	{
   	 bool flag = false;
    FOR(i,x,a.size()) {
     if( a[i] == c )
	  FOR(j,y,a.size())
	 	if( b[j] == c && LCS(i,j) == lcs-d ) {
	 		rec( str + char(c), i+1, j+1, d+1 );
	 		flag = 1; break;
	 	}
		if( flag ) break;
	 }
	}
}

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		char s1[100], s2[100];
		scanf("%s %s", &s1, &s2);
		a = string(s1);
		b = string (s2);
		
		memset( dp, -1, sizeof dp );
		v.clear();
		lcs = LCS(0,0);
		rec( string(), 0,0 );
	
		repVector(v)
		 printf("%s\n", it->c_str());
		
	}
}
