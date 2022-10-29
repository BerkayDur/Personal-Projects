

int LinearSearchInt(int const A[], int const n, int const v)
{
    for (int *p=A;p<A+n;p++){
        if (*p==v){
            return p-A;
        }
    }
    return -1;
}
