

void SelectionSortInt(int A[], int n)
{
    int index, hold;
    for (int i=0;i<n-1;i++){
        index = i;
        for (int j=i+1;j<n;j++){
            index = A[index]<A[j]?index:j;
        }
        int hold = A[i];
        A[i] = A[index];
        A[index] = hold;
    }
    return;
}
