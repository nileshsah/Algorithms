#include <iostream>
using namespace std;

int main() {    
    double inp = 1.00;
    
    while( inp > 0.00 ) {
    cin >> inp;
    
    if( inp == 0.00 )
        break;
    
    double sum = 0;
    long int n = 1;
    
    while( inp - sum > 0 ) {
       n++;
       sum += double(1)/n;
    }
    
    cout << n-1 << " card(s)" << endl;
   }
}
