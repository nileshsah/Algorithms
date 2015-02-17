#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
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

ll Dp[10000+5][2] = {0};
ll n;

class BigInt {
	int num[3005];
	ll size;
public:
	BigInt() {
		size = 3000;
		FOR(i,0,size)
			num[i] = 0;
	}
	
	int &operator[]( ll n )
	 { return num[n]; }
	
	BigInt operator+( BigInt b ) {
		ll c = 0;
		BigInt ans;
		
		FOR(i,0,size) {
			ans[n] = ( this->num[i] + b.num[i] + c )/10;
			c = ( this->num[i] + b.num[i] + c)%10;
		}
	}
	
	void operator=( BigInt a ) {
		FOR(i,0,size)
		 this->num[i] = a[i];
	}
	
	void print() {
		bool flag = 0;		
		for( ll i = size; i >= 0; i-- ) {
			if( num[i] != 0 )
				flag = 1;
			if ( flag )
				printf("%d", num[i]);
		}
	}
	
	void set( ll n, ll val )
	 { num[n] = val; }
			
};



ll rec( ll r, bool l ) {
	if( r == n-1 )
	  return 1;
	  
	if( Dp[r][l] != 0 )
		return Dp[r][l];
	
	ll val = rec(r+1,1);
	
	if( l != 0 )
	  val += rec(r+1,0);
	
	Dp[r][l] = val;
	return val;	
}

BigInt dp[10000][2];


int main() {
	/*get(n);
	ll ans = 0;
	ans += rec(0,1);
	ans += rec(0,0);
	cout << ans << endl;
		
	
	dp[n][0].set(0,1);  dp[n][1].set(0,1);
	cout << "\n\nVAL: "; dp[n][1].print();

	
	for( int i = n-1; i >= 1; i-- )
	  { dp[i][0] = dp[i+1][1]; dp[i][1] = dp[i+1][1] + dp[i+1][0]; }
	cout << " \n\nANS:";
	 BigInt Ans = dp[1][1] + dp[1][0];
	 Ans.print();
	*/
	
	BigInt a, b, c;
	a.set(0,9); b.set(0,8);
	cout << " a: "; a.print(); 
	cout << " b: "; b.print();
	
	c = a + b;
	//c.print();
}
