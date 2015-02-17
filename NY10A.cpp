#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( long i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
using namespace std;

int main() {
    ll t;
    get(t);
    
    while(t--) {
     ll n;
     get(n);
     char str[100];
     cin.ignore();
     cin.getline(str, 100);
     char test[][8] = { "TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH" };
     ll arr[10] = {0};
     
     repu(2,40) {
       char c[5];
       int x = 0;
       c[x++] = str[i-2];
       c[x++] = str[i-1];
       c[x++] = str[i];
       c[x] = '\0';
       
       rep(8)
        if( strcmp(c, test[i]) == 0 )
        { arr[i]++; break; }   
     }
     
     printf("%d", n);
     rep(8)
      printf(" %d", arr[i]);
     printf("\n");
              
    }
    
}
