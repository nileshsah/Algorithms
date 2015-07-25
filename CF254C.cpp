#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
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
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);

	string s, t;
	cin >> s >> t;
	
	ll ps[205] = {0}, pt[205] = {0};
	FOR(i,0,s.size()-1)
	 ps[s[i]]++;
	FOR(i,0,t.size()-1)
	 pt[t[i]]++;
	
	ll rem[200] = {0}, ans = 0;
	string add;
	FOR(i,'A','Z')
	 if( ps[i] > pt[i] )
	  rem[i] += ps[i] - pt[i];
	 else if( ps[i] < pt[i] )
	  FOR(j,1,pt[i]-ps[i])
	   add += char(i);
	
//	debug(add);
	
	sort( all(add) );
	

	FOR(i,0,s.size()-1) {
//		debug(ps[s[i]]); debug(rem[s[i]]);
	  char bk = s[i];
	 if( !add.empty() && rem[s[i]] && ( ps[s[i]] == rem[s[i]] || s[i] > add[0]  )  )
	  { ans++;  rem[s[i]]--; s[i] = add[0]; add.erase(add.begin()); }
	  ps[bk]--;
	}
	
	cout << ans << "\n" << s;
}
