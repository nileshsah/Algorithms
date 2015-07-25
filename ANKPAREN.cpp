#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main() {
//	BOOST;
	ll t; cin >> t;
	while(t--) {
		string s;
		cin >> s;
		ll k; get(k);
		
		ll val = 0; bool flag = 1;
		FOR(i,0,s.size()-1) {
		 if( s[i] == '(' )
		   val++;
		 if( s[i] == ')' )
		   val--;
		 if( val < 0 )
		  flag = 0;
		}
		
		if( val != 0 )
		 flag = 0;
		 
		if( !flag && k == 1 )
		 { cout << s << "\n"; continue; }
		else if( !flag && k > 1 )
		 { cout << "-1\n"; continue; }
		
		set<string> idx;
		string start = "", end = s;
		end.erase(end.begin());
		
		ll i = 0;
		while(1) {
		  if( i >= s.size() ) break;
		  
		  while( i > 0 && i < s.size()-1 && s[i] == s[i-1] )
		   { start += s[i]; if(end.empty()) break; end.erase(end.begin()); i++; }
		  
		  if( i >= s.size() ) break;
		  
		  string p = start + end;
	//	  debug(p);
		  idx.insert(p);
		  if(end.empty()) break;
		  start += s[i]; end.erase(end.begin());

		  i++;
		}
		
		if( k > idx.size() )
		 { cout << "-1\n"; continue; }
		
		auto it = idx.begin();
		for( int i = 1; i < k; i++, it++ );
		cout << *it << "\n";
		 
	}
}
