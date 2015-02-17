#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 template<typename T1, typename T2> struct node { 
      T1 first; 
      T2 second; 
 };
 
int main() {
    int t;
    cin >> t;
    while(t--) {
      long int n, q, i, j;
      cin >> n >> q;
      
      vector< pair<long long int, long long int> > v;
      
      for( i = 0; i < n; i++ ) {
           long long int x, y;
           cin >> x >> y;
           
           pair< long long int , long long int > p;
           p.first = x;
           p.second = y-x;
           
           v.push_back(p);
           
      }
      
      sort( v.begin(), v.end() );
      
      for( i = 0; i < q; i++ ) {
           long long int x;
           
           cin >> x;
           
           int flag = 1;
           
           for( j = 0; j < n; j++ ) {
                
                if( x < v[j].first )
                   break;
                
                if( x >= v[j].first && x <= v[j].first+v[j].second )
                 { flag = 0; break; }
           }
           
           if( flag == 1 )
               cout << "YES\n";
           else
               cout << "NO\n";
      }

   }
}
      
      
           
    
