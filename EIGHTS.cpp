#include <iostream>
using namespace std;

int main() {
    for( long long int i = 192; i <= 3000; i++ )
         if( (i*i*i)%1000 == 888 )
             cout << i << endl;
    
    int m;
    cin >> m;
}

