#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#define rep(i,n) for( i = 1 ; i < n ; i++)
#define max(a,b) (a>b):a?b
#define all(c) c.begin(), c.end()
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
      int n, m, a[400+5], count = 0;
      scanf("%d %d", &n, &m);
      queue<int> q[400+5];
      
      for( int i = 1; i <= m; i++ ) {
           scanf("%d", &a[i]);
           q[a[i]].push(i);
      }
      
      int i;
      rep(i,m+1)
       if( q[a[i]].back() != INT_MAX )
        q[a[i]].push(INT_MAX);
        
      set<int> s;
      
      for( int i = 1; i <= m; i++ ) {
        int x = a[i];
        
        if(s.find(x) != s.end())
         { q[x].pop(); }
        else if( s.size() != n )
         { s.insert(x); q[x].pop(); count++; }
        else if( s.size() == n ) {
             int max = 0, id;
             for(set<int>::const_iterator it = s.begin(); it != s.end(); it++) 
                    if( q[*it].front() > max )
                      {  id = *it; max = q[*it].front(); }
             s.erase(id);
             s.insert(x);
             q[x].pop();
             count++;
        }
        
        //cout << "\nSET: ";
        // for(set<int>::const_iterator it = s.begin(); it != s.end(); it++) 
             //cout << *it << "  ";
      }
      
      printf("%d\n", count);
    }
}
