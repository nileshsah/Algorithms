#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <cmath>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define max(a,b) a > b ? a : b
#define pb push_back
using namespace std;

ll a[3000] = {0};
ll dp[3000][3000] = {0};

ll rec( int top, int rear, int age, ll sum = 0 ) {
   if( top > rear )
       return sum;
       
   if( dp[top][rear] != 0 )
       return dp[top][rear];
   
   ll v1 = age*a[top] + rec( top+1, rear, age+1, 0 );
   ll v2 = age*a[rear] + rec( top, rear-1, age+1, 0 );
   
   dp[top][rear] = max( v1, v2 );
   //cout << "[" << top << "][" << rear << "] " << dp[top][rear] << endl;
   
   return dp[top][rear];
}

int main() {
    ll n;
    get(n);
    
    for( ll i = 0; i < n; i++ )
         get(a[i]);
    
   // cout << "Final: " << 
    rec( 0, n, 0, 0 ); // << endl;
    cout << dp[0][n-1];
    //cin >> n;
    
}
