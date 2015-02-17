#include <stdio.h>
#include <stdlib.h>
struct node {
    long max;
    long maxR;
    long maxL;
    long sum;
};
 
long max(long x, long y) {
    return x > y ? x : y;
}
 
typedef struct node node;
 
node tree[4 * 50005];
long A[50005];
int n;
 
void initialize(int nod, int b, int e) {
    if (b == e)
        tree[nod].max = tree[nod].maxR = tree[nod].maxL = tree[nod].sum = A[e];
 
    else {
        initialize(nod * 2, b, (b + e) / 2);
        initialize(nod * 2 + 1, ((b + e) / 2) + 1, e);
        tree[nod].sum = tree[nod * 2].sum + tree[nod * 2 + 1].sum;
 
        //get new maximum
        long newMax = max(tree[nod * 2].max, tree[nod * 2 + 1].max);
        newMax = max(newMax, tree[nod * 2].maxR + tree[nod * 2 + 1].maxL);
        tree[nod].max = newMax;
 
        //get new maximum right
        tree[nod].maxR = max(tree[nod * 2 + 1].maxR,
                tree[nod * 2 + 1].sum + tree[nod * 2].maxR);
 
        //get new maximum left
        tree[nod].maxL = max(tree[nod * 2].maxL,
                tree[nod * 2].sum + tree[nod * 2 + 1].maxL);
 
    }
    
	printf(" [ %ld %ld %ld ] ROOT: %d \n", tree[nod].maxL, tree[nod].max, tree[nod].maxR, nod );
}
 
node query(int nod, int b, int e, int i, int j) {
    if (i <= b && j >= e)
        return tree[nod];
    int mid = (b + e) / 2;
    if (j <= mid)
        return query(nod * 2, b, mid, i, j);
    if (i > mid)
        return query(nod * 2 + 1, mid+ 1, e, i, j);
    node p1 = query(nod * 2, b, mid, i, j);
    node p2 = query(nod * 2 + 1, mid + 1, e, i, j);
    node result;
 
    result.sum = p1.sum + p2.sum;
 
    //get new maximum
    long newMax = max(p1.max, p2.max);
    newMax = max(newMax, p1.maxR + p2.maxL);
    result.max = newMax;
 
    //get new maximum right
    result.maxR = max(p2.maxR, p2.sum + p1.maxR);
 
    //get new maximum left
    result.maxL = max(p1.maxL, p1.sum + p2.maxL);
 
    return result;
}
 
int main() {
    scanf("%d", &n);
    int i = 0;
 
    for (i = 0; i < n; i++)
        scanf("%ld", &A[i]);
 
    initialize(1, 0, n - 1);
    int m;
 
    scanf("%d", &m);
    int x, y;
 
    for (i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        node ans = query(1, 0, n - 1, x - 1, y - 1);
        printf("%ld\n", ans.max);
    }
 
    return 0;
}
