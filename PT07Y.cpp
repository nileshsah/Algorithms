#include <iostream>
#include <set>
#include <queue>
#define ll int unsigned
#define get(a) scanf("%ld", &a)
//using namespace std;

std::set<ll> v[100000+5];

int main() {
    ll n, m;
    get(n); get(m);
    
    bool flag = true;
    
    while(m--) {
      ll x, y;
      get(x); get(y);
      v[x].insert(y);
      v[y].insert(x);

    }
    
    std::queue<ll> q;
    q.push(1);
    v[1].erase(1);
    
    bool a[100000+5] = {0};
    a[0] = 1; a[1] = 1;
    ll count = 1;
    
    while(!q.empty()) {
       ll x = q.front();
       v[x].erase(x);
       q.pop();
       for( std::set<ll>::iterator it = v[x].begin(); it != v[x].end(); it++ ) {
            if( a[(*it)] == 1 )
               { flag = false; break; }
            q.push(*it);
            a[*it] = 1;
            v[*it].erase(x);
            count++;
       }
    }
    
    if( count != n )
        flag = 0;
    
    if( flag )
        printf("YES");
    else
        printf("NO");
}
    
      
      
    
    
