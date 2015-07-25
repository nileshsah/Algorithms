#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
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
using namespace std;

ll fastpow( ll x, ll y, ll MOD ) {
	ll res = 1;

	while(y) {
		if(y&1) {
			res *= x;
			res %= MOD;
		}
		x *= x;
		x %= MOD;
		y /= 2;
	}
	return res;
}

bool front[1000005] = {0};
bool back[1000005] = {0};

int main() {
	string s;
	cin >> s;
	ll a, b;
	cin >> a >> b;
	
	ll val = 0;
	
	FOR(i,0,s.size()-1) {
		val *= 10;
		val += s[i] - '0';
		val %= a;
		
		if(val==0)
		 front[i] = 1;
	}
	
	val = 0; ll exp = 0;
	ROF(i,s.size()-1,0) {
	   val += fastpow(10,exp,b)*(s[i]-'0');
	   if(s[i]!='0'&&val%b==0)
	    back[i] = 1;
	   val %= b;
	   exp++;
	}
	
	FOR(i,0,s.size()-1)
	 if( front[i] && back[i+1] ) {
	 	cout << "YES\n" << s.substr(0,i+1) << "\n" << s.substr(i+1);
	 	return 0;
	 }
	 
	 cout << "NO";
	 
	 
	
}
