#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
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
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();
	int z[100005] = {0};
	
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) {
	  if (i > R) {
	    L = R = i;
	    while (R < n && s[R-L] == s[R]) R++;
	    z[i] = R-L; R--;
	  } else {
	    int k = i-L;
	    if (z[k] < R-i+1) z[i] = z[k];
	    else {
	      L = i;
	      debug(L);
	      while (R < n && s[R-L] == s[R]) R++;
	      z[i] = R-L; R--;
	    }
	  }
	  cout <<"i: " << i << " [ " << L << " " << R << " ] = " << z[i] << "\n";
	}
	
	FOR(i,0,s.size()-1)
	 cout << z[i] << ' ';
}
