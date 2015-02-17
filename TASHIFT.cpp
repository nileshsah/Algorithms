#include <iostream>
using namespace std;

int main() {
    long int n, i, j,z, max = 0;
    char a[1000000+6], b[1000000+6];
    
    cin >> n;
    cin.ignore();  
    cin.getline( a, n+1);
    cin.getline( b, n+1);
    
    long int flag = -1,mflag = -1, count = 0;
    for( j = 0; j < 2*n; j++ ) {
         i = j%n;
         if( flag == -1 && b[i] == a[0] ) {
             flag = i; count = 1;
             z = i+1;; z %= n;
         while( b[z] == a[count] )
            {  count++; z++; z%= n; }
                 //cout <<"flag: " << flag <<"max: " << max << endl;             
             if( max < count ) {
                    max = count;
                    mflag = flag;
                } 
             flag = -1; count = 0;
         }
    
    }
    if( mflag == -1 )
        mflag = 0;
        
    cout << mflag;
    //cin >> flag;
}
    
