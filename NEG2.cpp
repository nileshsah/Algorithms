#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) a < b ? a : b
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
using namespace std;

int main() {
 	ll n;
 	get(n);
 	stack<int> q;
 	int b = -2;
 	
 	if( n == 0 )
 	 { printf("0"); return 0; }
 	 
 	while( n != 0 ) {
 		if( n%b == 0 )
 			q.push(0);
 		else
 			q.push(1);
 		if( n < 0 && n%b != 0 )
			{ n /= b; n++; }
		else
			n /= b;
	}
	
	while(!q.empty())
	 { printf("%d", q.top()); q.pop(); }
 
}
