#include <iostream.h>
using namespace std;

int main() {
    int t;
       
    while(t--) {
      char a[1000005];
      cin.getline( a, 1000005 );
      
      long long int count = 0, open = 0;
      
      for( int i = 0; a[i] != '\0'; i++ ) {
           if( a[i] == '<' )
               open++;
           if( a[i] == '>' )
               open--;
           
           if( open < 0 )
               break;
           if( open == 0 )
               count++;
      }
      std::cout << count << endl;
    }    
}
               
      
          
      
      
       
