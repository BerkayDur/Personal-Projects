

int HeapParent_(int i)
{
    return (i+1)/2 -1;
}

int HeapLeft_(int i)
{
    return 2*i+1;
}

int HeapRight_(int i)
{
    return 2*i + 2;
}

_Bool MaxHeapProperty_(int A[], int i)
{
    if ()
}

_Bool MinHeapProperty_(int A[], int n)
{
    for (int i=n-1;i>0;i--){
        printf("|%d|  ",i);
        if (A[i]<A[HeapParent_(i)]){
            return 0;
        }
    }
    return 1;
}
