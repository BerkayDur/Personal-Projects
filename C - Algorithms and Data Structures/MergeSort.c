
void MergeInt(int A[], int const n, int const m)
{
    int n1 = m, n2 = n-m;
    int L[n1+1], R[n2+1];
    for (int i=0;i<n1;i++){
        L[i] = A[i];
    }
    for (int i=0;i<n2;i++){
        R[i] = A[m+i];
    }
    L[n1] = 2147483647;
    R[n2] = 2147483647;
    for (int i=0,j=0,k=0;k<n;k++){
        if (L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
    return;
}

void MergeSortInt(int A[], int const n)
{
    if (n==1){
        return;
    }
    int m = n/2;
    MergeSortInt(A,m);
    MergeSortInt(A+m,n-m);
    MergeInt(A,n,m);
}
