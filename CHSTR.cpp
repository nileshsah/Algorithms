#include <bits/stdc++.h>
#define ll long long
//#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
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
#define MOD 1000000007
using namespace std;

#define gc getchar

struct node {
	char c;
	node *next[27];
};

void get(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

ll store[5005] = {0};
 
ll modpow(ll a,ll b) 
{
	if( b == MOD-2 && store[a] != 0 )
	 return store[a];
	ll bk = a;
	 
    ll ans=1;
    while(b)
    {
        if(b%2)
            ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return store[bk] = ans;
}
 
ll val[5005] = {0};

int main() {
//	INPFILE;
	
	int t; get(t);
	while(t--) {
		int n, q;
		get(n); get(q);
		char rd[5005];
		scanf("%s", &rd);
		string s(rd);
		unordered_map<string,ll> m;
		memset( val, 1, sizeof val );
		
		cout << "INPUT\n";
		
		FOR(i,0,n-1) {
		 string p;
		  FOR(j,i,n-1) {
		   p += s[j];
		   m[p]++;;
		  }
		}
		
		cout << "SUBSTRING\n";
		
		ll idx[5005] = {0};
		ll maxx = 0;
		repVector(m) {
		 idx[it->S]++;
		 maxx = max( maxx, it->S );
		}
		
		
		
		vector< pair<ll,ll> > v;
		 FOR(i,1,maxx)
		  if( idx[i] ) {
		   v.pb( mp(i,idx[i]) );
	//	   cout << i << " " << idx[i] << "\n";
		  }
		
		cout << "SAMPLE\n";
		
		ll ans[5005] = {0};
			
		ll itr = v.size()-1;
		
		ROF(i,maxx,1) {
		 while( itr > 0 && v[itr].F > i )
		   itr--;
		 FOR(j,itr,v.size()-1)
		  if( v[j].F == i ) {
		   ans[i] += v[j].S;
		   val[ v[j].F ] = 1;
		//   printf("-- C(%lld,%lld) = %lld\n", v[j].F, i, val[ v[j].F ] );
		  }
		  else if( v[j].F > i ) {
		  	val[ v[j].F ] *= ( (i+1)*modpow( v[j].F - i, MOD-2 ) )%MOD;
		    val[ v[j].F ] %= MOD;
		 //   printf(" C(%lld,%lld) = %lld\n", v[j].F, i, val[ v[j].F ] );
			ans[i] = ( ans[i] + val[ v[j].F ]*v[j].S )%MOD;
		  }
		}
		   		 
		while(q--) {
			int k; get(k);
			if( k > maxx )
			 printf("0\n");
			else
			 printf("%lld\n", ans[k]);
		}
	}
}
