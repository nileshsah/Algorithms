#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
using namespace std;

long dp[105][105] = {0};

long getsum( vector<int> v, int i, int n ) {
	long s = 0;	
	for( int k = i; k <= n; k++ )
		s += v[k];
	return s%100;
}

long rec( vector<int> v, int i, int n ) {
	long sum = dp[i][n];
	if( i == n )
		return 0;
	if( dp[i][n] != -1 )
		return dp[i][n];
//	cout << i << "  " << n << endl;
	
	for( int k = i; k+1 <= n; k++ ) {
		long val = rec( v, i, k ) + rec( v, k+1, n);
		val += getsum(v,i,k)*getsum(v, k+1, n);
		
		if( sum > val || sum == -1 )
			sum = val;
	}
	
	
	dp[i][n] = sum;
	
	return sum;
}

int main() {
	int n;
	while( get(n) != -1 ) {
	  vector<int> v;
	  rep(n) {
		int x;
		get(x);
		v.pb(x);		
	 }
	 memset( dp, -1, sizeof dp );
	 printf("%ld\n", rec( v, 0, v.size()-1 ) );
	 
	}	
}
