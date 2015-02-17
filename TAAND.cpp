#include <iostream>


long int ipow(int base, int exp)
{
    long int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}



long  unsigned int a[100000+5], b[100000+5][30+1], pow2[31], ans;
long int n, i, j, bit[30], arr[100000+5], arr2[100000+5], count = 0;
    
int main() {
    
    
    b[0][0] = 0;
    for( i = 0; i < 30; i++ )
         pow2[i] = ipow(2, i);
         
    scanf("%ld", &n);
    
    for( i = 0; i < n; i++ ) {
         scanf("%ulld", &a[i]);
            for( int j = 0; j <= 29; j++ ) {
                 if( a[i]&pow2[j] ) {
                    b[i][j] = 1;
                     bit[j] = 1;
                 }  
                 
            std::cout << b[i][j] << " ";
            }               
           std::cout << "\n";      
    }
    
    
     for( i = 29; i >= 0; i-- ) {
         if( bit[i] == 0 )
             continue;
       for( j = 0; j < n; j++ ) {
         if( b[j][i] == 1 ) {
             arr[count] = j;
             count++;
             std::cout << arr[count-1] << " -- ";
         }
       }
       
       if( bit[i] == 1 )
           break;
     }
     i--;
     
      for( ; i >= 0; i-- ) {
         if( bit[i] == 0 )
             continue;
             int tcount = 0;
             
           for( j = 0; j < count; j++ ) {
                if( b[ arr[j] ][i] == 1 ) {
                    arr2[tcount] = arr[j];
                    tcount++;
                }
           }
           
           count = tcount;
           
           std::cout << std::endl;
           
           for( j = 0; j < tcount; j++ ) {
                std::cout << arr[count-1] << "  ";
                arr[j] = arr2[j];
           }
      }
      
      ans = a[ arr[0] ]&a[ arr[1] ];
      std::cout << ans;
      std::cin >> ans;
}
                    
                
                
                
           
          
          
     
       
   
      
       
    
    
    
    
    
    
                 
    
    
