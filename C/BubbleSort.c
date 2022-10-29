
void BubbleSortInt(int A[], int const n)
{
    int hold;
    for (int *p=A;p<A+n-1;p++){
        for (int *q=A+n-1;q>p;q--){
            if (*q<*(q-1)){
                hold = *q;
                *q = *(q-1);
                *(q-1) = hold;
            }
        }
        PrintArrayInt(A,n);
    }
    return;
}
