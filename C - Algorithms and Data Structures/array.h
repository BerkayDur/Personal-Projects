#include <stdio.h>

int FindMaxCrossingSubarrayInt(int const A[], int const mid, int  const n, int *const left_index, int *const right_index);
int FindMaxSubarrayInt(int const A[], int const n, int *const left_index, int *const right_index);
int FindMaxSubArrayIntBadMethod(int const A[], int const n, int *const start_index, int *const end_index);
void PrintArrayInt(int const A[], int const n);

void PrintArrayInt(int const A[], int const n)
{
    for (int const *p=A;p<A+n;p++){
        printf("%d ",*p);
    }
    printf("\n");
    return;
}
