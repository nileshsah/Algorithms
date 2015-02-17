#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//definitions
#define mem_prep(varx) memset(varx,0,sizeof(varx))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define rep(i,a,n) for(int i=(a);i<(n);i++) 
#define repe(i,a,n) for(int i=(a);i<=(n);i++)
#define forsz(i,a,v) rep(i,a,sz(v))
#define repsz(i,v) rep(i,0,sz(v))
#define vi vector
#define vs vector
#define FOR(i,N) for(int i=0;i<(N);i++) 

int value[1000];
int weight[1000];
int picks[1000][1000] = {0};
int dp[1000][1000];
int n, W;

int knapsack() {

for(int i = 0; i <= n; i++) {
for(int w = 0; w <= W; w++) {

if(i == 0 || w == 0) {
dp[i][w] = 0;
continue;
}

// If current Item can't be included, than we choose maxvalue when maxweight is w and items are chosen from 1 to i - 1.
if(weight[i] > w) {
dp[i][w] = dp[i-1][w]; 
picks[i][w] = -1;
}
//If current can be included, than two cases arises, answer with current item included and answer if current item is not included. we take the maximum of the two. here comes power of dp.
else {

dp[i][w] = max(dp[i-1][w], value[i] + dp[i-1][w - weight[i]]);

if(dp[i-1][w] < value[i] + dp[i-1][w - weight[i]])
picks[i][w] = 1;
else picks[i][w] = -1;
}
}
}

return dp[n][W];
}

void pickups() {

int items = n;
int cost = 0;
while(items > 0) {

if(picks[items][W] == 1) {

cost += weight[items];
W -= weight[items];
items--;

}

else items--;
}

cout << cost << endl;
}

int main() {

int t;
cin >> t;
while(t--) {

cin >> W >> n;
for(int i = 1; i <= n; i++) {

cin >> weight[i];
cin >> value[i];

}

int maxvalue = knapsack();
cout << maxvalue << endl;
}

return 0;
}
