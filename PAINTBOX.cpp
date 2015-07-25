#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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

ll size[1000000] = {0};

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll w, n;
		get(n); get(w);
		ll arr[100005] = {0};
		ll parent[100005] = {0};
		memset( size, 0, sizeof size );
		
		FOR(i,1,n)
		 get(arr[i]);
		 
	    ll ans = 0, index = 1;
	   
	   FOR(i,1,n+1) {
	     if( arr[i] != arr[i-1] ) { 
		    ans += max(0LL,size[index]-w+1); 
		    index++; 
			parent[i] = index;
			size[index] = 1;
		 }
	     else
	        { size[index]++; parent[i] = index; }
	   }
	   
		

			
		ll q; get(q);
		while(q--) {
		   ll x, y;
		   get(x) get(y);
		   if( arr[x] == y )
		    { cout << ans << endl; continue; }
		 
		   ans -= max(0LL,size[parent[x]]-w+1);
	//	   cout << ans << endl;
		   
		   parent[x] = ++index;
		   size[index] = 1;	
		   	   
		   if( arr[x+1] == y ) {
		     FOR(i,x+1,n)
		      if( arr[i] == y )
		        { parent[i] = index; size[index]++; }
		      else
		        break;
		   }
		   else if( arr[x] == arr[x+1] ){
		     parent[x+1] = ++index;
		   	 size[index] = 1;
		     FOR(i,x+2,n)
		      if( arr[i] == arr[x] )
		        { parent[i] = index; size[index]++; }
		      else
		        break;
		   }

		   
		   if( arr[x-1] == y ) {
		     ROF(i,x-1,1)
		      if( arr[i] == y )
		        { parent[i] = parent[x]; size[parent[x]]++; }
		      else
		        break;
		   }
		   else if( arr[x-1] == arr[x] ) {
		   	  parent[x-1] = ++index;
		   	  size[index] = 1;
			  ROF(i,x-2,1)
		      if( arr[i] == arr[i+1] )
		        { parent[i] = index; size[index]++; }
		      else
		        break;
		   }
		   
	 
		   
		   set<ll> s;
		   if( x-1 >= 1 )
		    s.insert(parent[x-1]);
		   s.insert(parent[x]);
		   if( x+1 <= n )
		    s.insert(parent[x+1]);
		   
		   repSet(s) {
		     ans += max(0LL,(size[*it]-w+1));
		 //    cout << "I: " << *it << " A: " << size[*it]-w+1 << endl;
		 }
		   
		   arr[x] = y;
	
	
		   cout << ans << endl;
		}
		
	}
}
