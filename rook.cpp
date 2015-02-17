#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    fstream f1;
    f1.open("raging_rooks.txt");
    int n,m,i, xcount = 0, ycount = 0;
    int *x, *y;
    x = new int[1000001];
    y = new int[1000001];
    x[0] = 0; y[0] = 0;
    

    //getch();
    int count = 0;
    while( f1 >> n >> m ) {
           //cout << " ( " << n <<" , "<< m <<" )\n";
           //getch();
           x[n] = 1;
           y[m] = 1;
           count++;
    }
    
    cout << count;
    
    cout << "\nPassed\n";
    getch();
    for(i = 1; i <= 1000000; i++ ) {
            if( x[i] != 1 )
                xcount++;
            if( y[i] != 1)
                ycount++;
   }
   
   cout << "xcount: " << xcount <<" ycount: " << ycount;
   getch();
}
    
