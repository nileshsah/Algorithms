#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG]" << #x << " " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

long long SmallC(int n, int r, ll MOD)
{
    vector< vector<long long> > C(2,vector<long long> (r+1,0));
 
    for (int i=0; i<=n; i++)
    {
        for (int k=0; k<=r && k<=i; k++)
            if (k==0 || k==i)
                C[i&1][k] = 1;
            else
                C[i&1][k] = (C[(i-1)&1][k-1] + C[(i-1)&1][k])%MOD;
    }
    return C[n&1][r];
}
 
long long Lucas(int n, int m, ll p)
{
    if (n==0 && m==0) return 1;
    int ni = n % p;
    int mi = m % p;
    if (mi>ni) return 0;
    return Lucas(n/p, m/p, p) * SmallC(ni, mi, p);
}
 
long long C(int n, int r, ll MOD = 1000000007)
{
	if( n < r )
		return 0;
    return ( Lucas(n, r, MOD)%MOD );
}

int main() {
	ll t; get(t);
	while(t--) {
		string s;
		cin >> s;
		s = " " + s;
		
		ll n; cin >> n;
		
		int L[100005] = {0};
		int R[100005] = {0};
		
		FOR(i,1,s.size()-1) {
		 L[i] += L[i-1];
		 if( s[i] == 'l' )
		   L[i]++;
		}
		
		ROF(i,s.size()-1,1) {
		  R[i] += R[i+1];
		  if( s[i] == 'l' )
		  	R[i]++;
		}
		
		ll ans = 0;
		
		FOR(i,1,s.size()-1)
		 if( s[i] == 'o' ) {
		 	ans += C(L[i],n/2)*C(R[i],n/2);
		 	ans %= 1000000007;
		 }
		 
		 cout << ans << endl;
		
	}
}
