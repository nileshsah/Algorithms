#include<iostream>
//#include <conio.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
       int a[10][10];
       a[1][1] = 0;
       
       
      int n, m;
      int mcount = 0;
      cin >> n >> m;
      
      
      for( int i = 0; i < m; i++ ) {
           int x, y;
           cin >> x >> y;        
           a[y][x] = -1;
           
           for( int i = 1; i <= n; i++ ) {
                if( a[i][x] == 0 )
                    a[i][x] = -2;
                if( a[y][i] == 0 )
                    a[y][i] = -2;
                
                if( x-i >= 1 ) {
                    if( y-i >= 1 && a[y-i][x-i] != -1 )
                        a[y-i][x-i] = -2;
                    if( y+i <= n &&  a[y+i][x-i] != -1 )
                        a[y+i][x-i] = -2;
                }
                if( x+i <= n ) {
                   if( y-i >= 1 && a[y-i][x+i] != -1 )
                        a[y-i][x+i] = -2;
                    if( y+i <= n &&  a[y+i][x+i] != -1 )
                        a[y+i][x+i] = -2;
                }
           }
           
                
      }
      
      
      for( int j = 1; j <= n; j++ ) {
           for( int i = 1; i <= n; i++ ) {
                cout << a[j][i] << "  ";
           }
           cout << endl;
      }
      
      //(i+1,j+2), (i+1,j-2), (i-1,j+2), (i-1,j-2), (i+2,j+1), (i+2,j-1), (i-2,j+1), (i-2,j-1)
      for( int j = 1; j <= n; j++ ) 
           for( int i = 1; i <= n; i++ ) {
                
                if( a[j][i] == -1 || a[j][i] == -2 )
                    continue;
                    
                int count = 0;
                if( i+1 <= n ) {
                    if( j-2 >=1 && a[j-2][i+1] == -1 )
                        count++;
                    if( j+2 <= n && a[j+2][i+1] == -1 )
                        count++;
                }
                if( i+2 <= n ) {
                    if( j-1 >=1 && a[j-1][i+2] == -1 )
                        count++;
                    if( j+1 <= n && a[j+1][i+2] == -1 )
                        count++;
                }  
               if( i-1 >= 1 ) {
                    if( j+2 <=n && a[j+2][i-1] == -1 )
                        count++;
                    if( j-2 <= n && a[j-2][i-1] == -1)
                        count++;
                }  
               if( i-2 >= 1 ) {
                    if( j+1 <=n && a[j+1][i-2] == -1)
                        count++;
                    if( j-1 <= n && a[j-1][i-2] == -1 )
                        count++;
                }  
                
                if( count > 1 )
                    mcount++;
                
           }
           
           cout << mcount <<endl;
    
    }
    
   // getch();
              
}
               
