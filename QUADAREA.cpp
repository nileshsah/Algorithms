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
    
int main() {
    ll t;
    get(t);
    
    while(t--) {
       double a[5] = {0}, s = 0;
       rep(4) { scanf("%lf", &a[i]); s += a[i];  }
       s /= 2;

       double val = (s - a[0])*(s - a[1])*(s - a[2])*(s - a[3]);
      
       val = sqrt(val);
       
       printf("%0.2lf\n", val);
    }
}
