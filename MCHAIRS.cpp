#include <iostream>
#include <math.h>
using namespace std;


int main() {
    long int *a, n;
    a = new long int[100000001];
    a[0] = 1;
    for( int i = 1; i <= 100000001; i++ )
         a[i] = (a[i-1]*2)%1000000007;
    
    cout << "Done !";
    cin >> n;
}
