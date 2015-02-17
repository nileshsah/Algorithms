#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
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

ll arr[100005] = {0};

int main() {
	string s;
	cin >> s;
		
	ll ec = 0;
	
	FOR(i,0,s.size()-1) {
	  arr[i] = s[i] - '0';
	  if( arr[i]%2 == 0 )
	  	ec++;
	}
	
//	cout << "EC: " << ec << endl;
	
	if( ec == 0 )
	  { cout << "-1"; return 0; }
	
	ll last = s.size()-1;
	
	FOR(i,0,s.size()-1)
	 if( arr[i]%2 == 0 && arr[i] < arr[last] ) {
	 	swap(s[i],s[last]);
	 	cout << s; return 0; 
	 }
	
	FOR(i,0,s.size()-1)
	 if( arr[i]%2 == 0 && ( ec == 1 || arr[i] == arr[last] ) ) {
	 	swap(s[i],s[last]);
	 	 cout << s; return 0;
	 }
	 else if( arr[i]%2 == 0 )
	 	ec--;
	 		
}
