#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define max(a,b) a > b ? a : b
using namespace std;

int main() {
  while(1) {
	ll n, m;
	set<ll> a;
	vector<ll> c, v1, v2, sum1, sum2;
	
	get(n);
	if( n == 0 )
		break;		
	
	
	rep(n) {
	 ll x; get(x);
	 a.insert(x);
	 v1.pb(x);
	}
	
	get(m);
	rep(m) {
	 ll x; get(x);
	 v2.pb(x);	 
	 set<ll>::iterator it = a.find(x);	
	 if( it != a.end() )
	  { c.pb(*it); }
	}
	
	vector<ll>::iterator it = c.begin();
	ll sum = 0;
	
	rep(n) {
	  if( it != c.end() && v1[i] == *it ) {
	  	sum += *it;
	  	sum1.pb(sum);
	  	sum = 0;
	  	it++;
	  }
	  else
	  	sum += v1[i];
	}
	sum1.pb(sum);
	
	 it = c.begin();
	sum = 0;
	rep(m) {
	  if( it != c.end() && v2[i] == *it ) {
	  	sum += *it;
	  	sum2.pb(sum);
	  	sum = 0;
	  	it++;
	  }
	  else
	  	sum += v2[i];		
	}
	sum2.pb(sum);
	
	sum = 0;
	rep(c.size()+1) {
		//cout << i << " 1::" << sum1[i] << " 2::" << sum2[i] << endl;
		sum += max( sum1[i], sum2[i] );
	}
	
	printf("%ld\n", sum );
	
	
 }
}

