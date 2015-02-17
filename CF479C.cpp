#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<double> >
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;


long longDiv( string str, long div ) {
      // cout << " DIV: " << str << "/" << div;
       ll rem = 0;
       string ans;
       bool start = 0;
       
       for( int i = 0; i < str.length(); i++ ) {
            rem *= 10;
            rem += str[i] - '0';
            ll q = rem/div;
            
         if( q > 0 )
          start = 1;
          
          if( start )
           {  ans.pb(q+'0'); rem %= div; }                 
       }
       
       //cout << " REM: " << rem << endl;
 		return rem;
 		

}

int main() {
	string a;
	cin >> a;
	ll x, y;
	get(x); get(y);
	
	FOR(i,1,a.size()-1) {
		string w =  a.substr(0,i), e =  a.substr(i);
		if( e[0] == '0' ) continue;
	 if( longDiv( w, x ) == 0 && longDiv( e, y ) == 0 )
	 	{ cout << "YES\n" << w << "\n" << e; return 0; }
	}
	
	cout << "NO";
}

