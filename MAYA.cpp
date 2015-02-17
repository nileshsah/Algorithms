#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
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
#define min(a,b) a < b ? a : b
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
using namespace std;

int main() {
  while(1) {
	ll n;
	get(n);
	cin.ignore();
	
	if( n == 0 )
		break;
	
	vector<long long> v;
	v.pb(1);
	
	for( int i = 1; i <= n; i++ ) {
	  if( i == 2 )
	  	v.pb(360);
	  else	
		v.pb( v[i-1]*20 );
	}
	
	long long num = 0;
	
	while(n--) {
		char str[50];
		cin.getline( str, 20 );
		int dig = 0;
		
		for( int i = 0; i < strlen(str); i++ ) {
			if( str[i] == '.' )
				dig++;
			else if( str[i] == '-' )
				dig += 5;
		}
		
		//cout << dig << " *  " << v[n] << endl;
		num += dig*v[n];
	
	}
	
	printf("%lld\n", num);
 }
}
