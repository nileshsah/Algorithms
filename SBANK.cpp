#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <string>
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
      ll n;
      map< string, ll > acount;
      
      get(n);
      cin.ignore();
      
      rep(n) {
        char temp[30];
        gets(temp);
        string str(temp);
        acount[str] = acount[str] + 1;
      } 
      
      map< string, ll >::iterator it = acount.begin();
      
      for( ; it != acount.end(); it++ )
        printf("%s %ld\n", (it->first).c_str(), it->second);     
      
    }
}
