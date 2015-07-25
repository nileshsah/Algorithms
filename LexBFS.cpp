#include <bits/stdc++.h>
#define ll long
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define F first
#define S second
#define mp make_pair
using namespace std;

vector<ll> Graph[1005];
ll vertex = 0, edge = 0;
bool explore[1005] = {0};

void printline( char s ) {
	cout << endl;
	FOR(i,1,50)
	 cout << s;
	cout << endl;
}


void clearall() {
	FOR(i,0,1004) {
	 Graph[i].clear();
	 explore[i] = 0;
	}
}

int generate( ) {
	
	clearall();
	
	cout << "\nEnter Number of VERTICES: "; cin >> vertex;
	if( vertex > 1000 || vertex < 0 )
	 { cout << "Vertices out of bounds!\n"; return -1; }
	
	cout << "Enter Number of EDGES:   "; cin >> edge;
	cout << "Enter the edges:\n";
	
	FOR(i,1,edge) {
		ll x, y;
	   cin >> x >> y;
	   if( x > vertex || y > vertex )
	    { cout << "[ Invalid Edge ]\n"; i--; continue; }
	   Graph[x].pb(y); 
	   Graph[y].pb(x);
	}
	
	cout << "\n\n [ Graph Generated Successfully ! ]\n";
	return 0;
	
}

int LexBFS( ll p ) {
	
	if( p > vertex )
	 { cout << "\n[ Invalid Vertex ]\n"; return -1; }
	 
	ll D[1005] = {0};
	D[p] = vertex+1;
	
	set< pair<ll,ll> > bfs;
	
	FOR(i,1,vertex)
	  bfs.insert( mp( D[i], i ) );
	
	queue<ll> lex;
	
	while(!bfs.empty()) {
		ll label = bfs.rbegin()->F - 1;
		ll node = bfs.rbegin()->S;
		explore[node] = 1;
		
		repVector(Graph[node])
		 if(!explore[*it]) {
		 	bfs.erase( mp( D[*it], *it ) );
		 	D[*it] = label;
		 	bfs.insert( mp( D[*it], *it ) );
		 }
		
		  lex.push(node);
		  bfs.erase(--bfs.end());
	}
	
	cout << "\n LexBFS - Order: ";
	while(!lex.empty())
	 { cout << lex.front() << " "; lex.pop(); }
	cout << "\n";
	
	return 0;
}
	

int main() {

 while(1) {	
	printline('*');
	cout << "\t\tLex-BFS Implementation";
	printline('*');
	
	ll x;
	
	cout << " 1. Generate Graph"
		 << "\n 2. Apply LexBFS"
		 << "\n 3. Exit"
 		 << "\nChoose option: ";
 	cin >> x;
 	
 	if( x == 1 )
 	 generate();
 	else if( x == 2 ) {
 	  ll p;
	  cout << "\nEnter Node to Apply LexBFS: ";
 	  cin >> p;
 	  LexBFS(p);
 	}
 	else if( x == 3 )
 	 return 0;
 	
  }
 
}
