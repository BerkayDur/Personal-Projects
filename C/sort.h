
void InsertionSortInt(int A[], int const n,_Bool const increasing);
void SelectionSortInt(int A[], int n);
void MergeInt(int A[], int const n, int const m);
void BubbleSortInt(int A[], int const n);




_Bool IsSortedInt(int const A[], int const n);




_Bool IsSortedInt(int const A[], int const n)
{
    for (int *p=A+1, *q=A;p<A+n;p++,q++){
        if (*p<*q){
            return 0;
        }
    }
    return 1;
}
