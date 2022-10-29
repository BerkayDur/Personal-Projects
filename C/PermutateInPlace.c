

void PermutateInPlaceInt(int A[], int n)
{
    srand(time(0));
    for(int i=0, place,hold;i<n;i++){
        place = rand()%(n-i) + i;
        hold = A[i];
        A[i] = A[place];
        A[place] = hold;
    }
    return;
}

