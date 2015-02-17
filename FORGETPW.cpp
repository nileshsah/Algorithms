#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    //cin.ignore();
    while(t--) {
      char s[1000006]; int rep[130];
      
      rep[0] = 0;
      for( int i = 33; i <= 126; i++ )
           rep[i] = i;
           
      int n;
      cin >> n;
      
      for( int i = 0; i < n; i++ ) {
           char c, p;
           cin >> c >> p;
           rep[c] = p;
      }
      
      cin.ignore();
      cin.getline(s, 1000006);
      long int len = strlen(s);
      
     // cout << "\nLength: " << len;
      
      long int flag = 0, i, j, brk;
      for(  i = 0; i < len; i++ ) {
           if( rep[s[i]] == 48 && flag == 0 ) {
           
           }
           else if( rep[s[i]] == 46 )
            { break; }
           else {
               cout << char(rep[s[i]]);
               flag = 1;
           }
      }
      
      brk = i;
      
      
      for( j = len-1; j > i; j-- ) {
           if( rep[s[j]] == 48  )
               continue;
           if( rep[s[j]] == 46 ) {
               j--;
               break;           
           }
           if( rep[s[j]] > 48 && rep[s[j]] <= 57 )
               break;
      }
      
      if( j != i ) {
          for( ; i <= j; i++ )
               cout << char(rep[s[i]]);
         // s[j+1] = '\0';
          //cout << "j: " << j << " i: " << i << endl;
          //cout << s+i;
      }
         
      if( (flag == 0 && j <= brk) || (i == 0 && j == 0 & brk == 0) )
          cout << "0";
          
      // cout << endl << "i: " << i << " j: " << j << " brk: " << brk ;
          cout << endl;
    }
}
       
      
           
           
           
           
           
      
      
      
      
      
               
