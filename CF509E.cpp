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
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll arr[5*100005] = {0};
ll sumR[5*100005] = {0};
ll sumL[5*100005] = {0};

int main() {
//	INPFILE;
	string s;
	cin >> s;
	s = "0" + s;
	ll len = s.size()-1;
	
	
	for( ll i = 1; i <= len; i++ ) {
	  if( s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y' )
		 arr[i] = arr[i-1]+1;
	  else 
	  	 arr[i] = arr[i-1];	  
	  sumL[i] = sumL[i-1] + arr[i];
	}
	
	for( ll i = len; i >= 1; i-- )
		sumR[i] = arr[i] + sumR[i+1];
	
	double ans = 0;
	
//	cout << " LEN: " << len << endl;
	
	FOR(i,1,len) {
//		cout << " A: " << arr[i] << " S: " << sumR[len-i+1] << " - " << sumL[i] << endl;
		ans += 1.0*( arr[i] + sumR[len-i+1] - sumL[i] )/double(i);
//		cout << " ANS: " << ans << endl;
	}
	
//	ans += arr[len]/(len);
	
	printf("%0.6lf", ans);
}
