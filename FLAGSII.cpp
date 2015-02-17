#include<iostream>

#include<string>
#include<sstream>
#define SIZE 700

using namespace std;



class Bignum{

    int no[SIZE];   


    public:

        Bignum operator *(Bignum& x){ // overload the * operator
        /*
            34 x 46
            -------
               204          // these values are stored in the
              136           // two dimensional array mat[][];
            -------
             1564   // this the value stored in "Bignum ret"
        */                              
    Bignum ret;             
    int carry=0;
    int mat[2*SIZE+1][2*SIZE]={0};
    for(int i=SIZE-1;i>=0;i--){
        for(int j=SIZE-1;j>=0;j--){
            carry += no[i]*x.no[j];
            if(carry < 10){
                mat[i][j-(SIZE-1-i)]=carry;
                carry=0;
            }
            else{
                mat[i][j-(SIZE-1-i)]=carry%10;
                carry=carry/10;
            }
        }
    }
    for(int i=1;i<SIZE+1;i++){
        for(int j=SIZE-1;j>=0;j--){
            carry += mat[i][j]+mat[i-1][j];

            if(carry < 10){

                mat[i][j]=carry;

                carry=0;

            }

            else{

                mat[i][j]=carry%10;

                carry=carry/10;

            }
        }
    }
    for(int i=0;i<SIZE;i++)
        ret.no[i]=mat[SIZE][i];
    return ret;
}

Bignum (){

    for(int i=0;i<SIZE;i++)

        no[i]=0;

}


Bignum (string _no){

    for(int i=0;i<SIZE;i++)

        no[i]=0;

    int index=SIZE-1;

    for(int i=_no.length()-1;i>=0;i--,index--){

        no[index]=_no[i]-'0';

    }

}


void print(){

    int start=0;

    for(int i=0;i<SIZE;i++)

    if(no[i]!=0){

        start=i;

        break;      // find the first non zero digit. store the index in start.

    }

    for(int i=start;i<SIZE;i++) // print the number starting from start till the end of array.

        cout<<no[i];

    cout<<endl;

    return;

}
 };


 int main(){

Bignum n1("2");
Bignum n2("3");

Bignum n3 = n1*n2;
n3.print();

return 0;

  }
