

void InsertionSortInt(int A[], int const n,_Bool const increasing)
{
    int i, key;
    for (int j=1;j<n;j++){
        key = A[j];
        i = j-1;
        while (i>=0 && (increasing==1?A[i]>key:A[i]<key)){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
    return;
}
