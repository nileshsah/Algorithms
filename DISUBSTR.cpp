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
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define max(a,b) a > b ? a : b
#define min(a,b) a > b ? b : a
using namespace std;

int findLCP( string s1, string s2 ) {
	int limit = min( s1.size(), s2.size() ), i;	
	for( i = 0; i < limit && s1[i] == s2[i]; i++ );
	return i;
}

int main() {
 	ll t;
 	get(t);
 	while(t--){
 		char str[1000+5];
		scanf("%s", &str);
		string s(str);
		vector<string> v;
		
		FOR( i,0,s.size() )
			v.pb( s.substr(i) );
		
		sort( all(v) );
		
		int lcp[2000] = {0};
		long sum = v[0].size();
		
		FOR(i,1,v.size()){
			int  = findLCP(v[i], v[i-1]);
			sum += v[i].size() - lcp[i];
		}
		
		printf("%ld\n", sum);		 	
	}
}

