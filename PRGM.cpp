#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) cin >> a
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
#define eps 10e-14
using namespace std;

ll n;
vector<double> v;
map<double,vector<double> > m;
double val;

void rec( ll r, vector<double> adj, double sum = 0 ) {
	if( !adj.empty() )
		m[abs(sum-val)] = adj;
	
	if( r >= n )
		return;
	
	rec( r+1, adj, sum );
	adj.pb(v[r]);
	rec( r+1, adj, sum+v[r] );	
}

int main() {
//	freopen("input.in", "r", stdin );
	
	cout << "Enter number of values: ";
	cin >> n;
		
	cout <<  "Enter Values: \n";	
	FOR(i,1,n) {
	 printf(" Value #%ld: ", i );
	 double x; cin >> x; v.pb(x);
	}
	
 while(1) {	
	cout << "\nEnter value to extract: ";
	cin >> val;
	
	cout << "\n ";
	
	m.clear();
	rec(0,vector<double>());
	
/*	repSTL(m) 
	 cout << " VAL : " << it->first << endl;
*/
	
	if( m.begin()->first > 0.015 )
		cout << " No Match Found !\n";
	else {
		double ans = 0;
		vector<double> idx = m.begin()->second;
		repVector(idx) { 
		 ans += *it;
		 cout << *it << " ";
		 if( it+1 != idx.end() )
		 	cout << "+ ";
		}
		
		cout << "= " << ans;
		printf(" ( %0.2lf%% Error )\n\n", abs(ans-val)*100/val );
	}
 
 }

}
