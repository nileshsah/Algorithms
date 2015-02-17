#include <iostream>
using namespace std;


int sumnum( long long unsigned int a ) {
    int size = 0;
    long int sum = 0;
    
    while( a!= 0 ) {
           sum += a%10;
           a /= 10;
           size++;
           
           if( sum > 13 )
               return -1;
    }
    
    if( sum == 13 )
        return size;
    else
        return -1;
}

int main() {
    long long unsigned int con = 1111111111111ll, arr[50] = {0};
    int temp = 0;
    
    for( long long unsigned int i = 1; i <= con ; i++ ) {
         int n = sumnum(i);
         if( n != -1 ) {
             arr[n]++;
         
         if( temp != n ) {
             cout << n-1 << " : " << arr[n-1] << endl;
             temp = n;
         }
         
         }
             
    }

    cin >> temp;
}
    
