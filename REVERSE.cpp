#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#define rep(i,n) for( i = 0 ; i < n ; i++)
#define max(a,b) (a>b):a?b
using namespace std;

struct node {
       int cost;
       long int id;
};

int main() {
    vector< node > v[100000+5];
    queue<long int> q;
    
    long int a[100000+5] = {0}, b[100000+5] = {0};
    long int n, m, x, y, i;
    scanf("%ld %ld", &n, &m);
    
    rep(i, n+1)
      a[i] = LONG_MAX;
    a[1] = 0;
    
    rep(i,m){
         scanf("%ld %ld", &x, &y);
         node p;
         p.cost = 0; p.id = y;
         v[x].push_back(p);
         p.cost = 1; p.id = x;
         v[y].push_back(p);
    }
    q.push(1);
    
    while(!q.empty()) {
     long int i = q.front(); q.pop();
     //cout << endl << i << "(" << a[i] << "): ";
     for(vector< node >::iterator it = v[i].begin(); it != v[i].end(); it++) { 
      //cout << it->id << "(" << it->cost << ")  ";
      if( a[it->id] > ( a[i] + it->cost ) ) {
          a[it->id] = a[i] + it->cost; 
          q.push(it->id);
      }
     } 
    }
     if( a[n] != LONG_MAX )
      printf("%ld", a[n]);
     else
      printf("-1");
     //cin >> n;
}    
