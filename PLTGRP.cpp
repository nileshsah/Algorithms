#include <iostream>
#include <cstdio>
using namespace std;

#include <string.h>
#include <stdio.h>
 
 
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
// Binary search (note boundaries in the caller)
// A[] is ceilIndex in the caller

 
long int func(long int A[], long int size) {
    // Add boundary case, when array size is one
 
    long int *tailTable   = new long int[size];
    long int len; // always points empty slot
 
    memset(tailTable, 0, sizeof(tailTable[0])*size);
 
    tailTable[0] = A[0];
    len = 1;
    for( long int i = 1; i < size; i++ ) {
        if( A[i] < tailTable[0] )
            // new smallest value
            tailTable[0] = A[i];
        else if( A[i] >= tailTable[len-1] )
            // A[i] wants to extend largest subsequence
            tailTable[len++] = A[i];
        //else
            // A[i] wants to be current end candidate of an existing subsequence
            // It will replace ceil value in tailTable
            //tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i];
    }
 
    delete[] tailTable;
 
    return len;
}

int main() {
    long int n, i;
    long int a[100000+5];
    
    long int count = 0;
    
    scanf("%ld", &n);
     
    for( i = 0; i < n; i++ ) {
         scanf("%ld", &a[i]);
    }
    
    cout << func( a, n ) << endl;
    
    //cout << n - count;
    //cin >> n;
}
    
