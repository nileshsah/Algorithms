#include <iostream>
using namespace std;

int main() {
    long int t;
    cin >> t;
    
    while(t--) {
      float s, n, m, k;
      cin >> s >> n >> m >> k;
      float prob = 1;
      
      for( float i = 1; i <= k; i++ )
           prob *= float( (n-i)/(s-i) );
     
     float sum = 1;
     
     if( prob != 1 )
       for( float i = k+1; i <= m-1; i++ )
          sum += (n-i)/(s-i);
          
    // cout << "Prob: " << prob << " Sum: " << sum << endl;
     cout << float(prob*sum) << endl;
    }
} 
