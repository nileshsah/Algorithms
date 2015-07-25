#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;


ll c[100005] = {0};
ll start[100005] = {0};
ll one[100005] = {0};
ll zero[100005] = {0};
ll ans[100005] = {0};
ll mark[100005] = {0};
ll pos_zero[100005] = {0};
ll pos_one[1000005] = {0};

		
int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n, k, q;
		get(n); get(k); get(q);
		string s;
		cin >> s;
		s = " " + s;
		
		memset( start, 0, sizeof start );
		memset( one, 0, sizeof one );
		memset( zero, 0, sizeof zero );
		memset( ans, 0, sizeof ans );
		memset( c, 0, sizeof c );
		memset( mark, 0, sizeof mark );
		memset( pos_zero, 0, sizeof pos_zero );
		memset( pos_one, 0, sizeof pos_one );

		ll index = 1;	
		ll last_one, last_zero;
		ll po = 1, pz = 1;
		start[index] = 1;
		
		FOR(i,1,n) {
			one[i] = one[i-1];
			zero[i] = zero[i-1];
			
			( s[i] == '0' ) ? zero[i]++ : one[i]++;
			( s[i] == '0' ) ? pos_zero[pz++] = i : pos_one[po++] = i;
			
			
			if( one[i] > k ) {
			  last_one = max( pos_one[po-k], pos_zero[max(0L,pz-k)] );
			  
			  one[i] = one[last_one] + 1 - one[last_one-1];
			  zero[i] = zero[last_one] - zero[last_one-1];
			  
			  ans[i] += ans[i-1] + i - last_one;
			  start[++index] = last_one;
			  c[index] = i - last_one;
		    }
		    else if( zero[i] > k ) {
		      last_zero = max( pos_zero[pz-k], pos_one[max(0L,po-k)] );
		      
			  one[i] = one[last_zero] - one[last_zero-1];
			  zero[i] = zero[last_zero] - zero[last_zero-1] + 1;
			  
			  ans[i] += ans[i-1] + i - last_zero;
			  start[++index] = last_zero;
			  c[index] = i - last_zero;
			}
			else {
//				cout << "i: " << i << " " << c[index] << endl;
				ans[i] += ans[i-1] + c[index];	
			}
			
			c[index]++;
			mark[i] = index;
		
			
		}
		
/*		cout <<"\n";
		FOR(i,1,n)
		 cout << mark[i] << " ";
		cout << "\n";
		FOR(i,1,n)
		 cout << ans[i] << " ";
		cout << "\n";
*/		
		while(q--) {
			ll l, r;
			get(l); get(r);
			
			ll sum = ans[r] - ans[l-1];
			sum += r - l + 1;
			
//			cout << "SUM: " << sum << endl;
//			cout << "M: " << mark[l] << " START:" << start[mark[l]] << endl;
			ll idx = mark[l];
			ll s = start[idx];
			ll x = l - s;
			ll y = min( r-l+1, c[idx] - x );
//			cout << x << " " << y << endl;
			
			printf("%lld\n", sum - x*y );
			
			
		}
	}
}
