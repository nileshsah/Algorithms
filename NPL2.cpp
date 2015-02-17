#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define L 2*r
#define R 2*r+1
using namespace std;

int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll n;
		set<string> s;
		map<string,ll> m;
		string a,b,c,d,e,f;
		get(n);
		cin.ignore();
		while(n--) {
		 char ss[200];
		 cin.getline(ss,200);
		 string str(ss);
		
		 s.insert(str);
		 m[str]++;
		}
		
		for( set<string>::iterator it = s.begin(); it != s.end(); it++ )
		 cout << *it << " " << m[*it] << endl << endl;
		
		
	}
}
