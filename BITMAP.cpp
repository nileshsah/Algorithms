#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

inline long absol( long n ) {
     if( n < 0 )
         return -n;
     else
         return n;
}

struct node {
       int x;
       int y;
       int z;
};

inline bool eval( node p, int n, int m, char str[200][200] ) {
     if( p.x < 0 || p.y < 0 || p.x >= m || p.y >= n || str[p.y][p.x] == '1')
         return 0;
     
     return 1;
}

int main() {
    long t;
    scanf("%ld", &t);
    
    while(t--) {
      int n, m;
      char str[200][200]; 
      long a[200][200] = {0};
      queue<node> q;
      
      scanf("%ld %ld", &n, &m);
         
      for( int i = 0; i < n; i++ ) {
           scanf("%s", str[i]);
      }
      
      bool mark[200][200] = {0};
                   
      for( int i = 0; i < n; i++ )
           for( int j = 0; j < m; j++ )
                if( str[i][j] == '1' ) {
                    int count = 1;
                    node cur; cur.x = j; cur.y = i; cur.z = -1;
                    q.push(cur);
                }
                           
                  do{
                        node cur;
                        cur = q.front();
                        q.pop();
                        
                        int len = cur.z+1;
                        
                        bool flag = 0;
                        
                        if( a[cur.y][cur.x] > len || a[cur.y][cur.x] == 0 )
                          {  a[cur.y][cur.x] = len; flag = 1; }
                            
                        
                     
                     if( flag ) {
                         node s;
                         int dr[]={-1,1,0,0},dc[]={0,0,-1,1};
                          for( int k = 0; k < 4; k++ ) {
                             s.x = cur.x + dr[k]; s.y = cur.y + dc[k]; s.z = cur.z+1;
                             if( ( s.x >= 0 && s.y >= 0 && s.x < m && s.y < n && str[s.y][s.x] != '1') && !mark[s.y][s.x]  )
                              { q.push(s); mark[s.y][s.x] = true; }
                          }
                     }
                                                    
                         
                  }while(!q.empty());
             
      
      
       for( int i = 0; i < n; i++ ){ 
           for( int j = 0; j < m; j++ )
                    printf("%ld ", a[i][j]);
           printf("\n");
       }
    }
}
                    
                             
      
           
      
