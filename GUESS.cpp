#include <iostream>
using namespace std;

int main() {
    long unsigned int t;
    cin >> t;
    
    while(t--) {
      long long unsigned int n, m;
      cin >> n >> m;
      
      if( n%2 == 0 && m%2 == 0 )
          cout << "1/2" << endl;
      else if( (n%2 != 0 && m%2 == 0) || (n%2 == 0 && m%2 != 0) )
           cout << "1/2" << endl;
      else if( n%2 != 0 && m%2 != 0 )
           cout << (n*m-1)/2 << "/" << n*m << endl;
    }
}
      
      
      
      
      
      
      
