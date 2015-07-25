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
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

/////////////////////////////////////////////////////
// CODE FOR LIS in nlogn from geeksforgeeks.com//////
////////////////////////////////////////////////////

#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
// Binary search (note boundaries in the caller)
// A[] is ceilIndex in the caller

ll CeilIndex(ll A[], ll l, ll r, ll key) {
    ll m;
 
    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m; // ternary expression returns an l-value
    }
 
    return r;
}
 
ll LongestIncreasingSubsequenceLength(ll A[], ll size) {
    // Add boundary case, when array size is one
 
    ll tailTable[100005] = {0};
    ll len; // always points empty slot
 
    memset(tailTable, 0, sizeof(tailTable[0])*size);
 
    tailTable[0] = A[0];
    len = 1;
    for( int i = 1; i < size; i++ ) {
        if( A[i] < tailTable[0] )
            // new smallest value
            tailTable[0] = A[i];
        else if( A[i] > tailTable[len-1] )
            // A[i] wants to extend largest subsequence
            tailTable[len++] = A[i];
        else
            // A[i] wants to be current end candidate of an existing subsequence
            // It will replace ceil value in tailTable
            tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i];
    }
 
    return len;
}

struct node {
	ll x, y;
	ll size, index;

};

bool compare( const node &a, const node &b ) {
	if( a.x == b.x )
	 return a.y > b.y;
	else 
	 return a.x < b.x;
}

ll dp[100005] = {0}, ans = 1;


int main() {
	ll n; cin >> n;
	vector<node> v, w;
	FOR(i,1,n) {
	  node ptr;
	  cin >> ptr.x >> ptr.y;
	  ptr.size = ptr.y - ptr.x;
	  v.pb(ptr);
	}
	sort( all(v), compare );
	
	ll A[100005];
	
	ll size = 0;
	FOR(i,0,n-1)
	  A[i] = v[i].y;
	 
	 

	 cout << LongestIncreasingSubsequenceLength(A,n);
}
