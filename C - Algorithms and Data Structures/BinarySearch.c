#include "array.h"

int BinarySearchInt(int A[], int n, int v)
{
    int m;
    int *p=A;
    for(int n2=n;;){
        PrintArrayInt(p,n2);
        if (n2==1){
            return p[0]==v?p-A:-1;
        }
        m = n2/2;
        printf("|%d|",n-m);
        if (p[m-1]==v){
            return p-A+m-1;
        }
        else if (v<p[m-1]){
            continue;
        }
        else if (v>p[m-1]){
            p += m;
            n2 -= m;
            continue;
        }
    }
}
