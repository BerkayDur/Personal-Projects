
void BinaryAdd(int const A[], int const B[], int const n, int C[n+1])
{
    int carry=0;
    for (int i=n-1;i>=0;i--){
        C[i+1] = A[i] + B[i] + carry;
        carry =0;
        if (C[i+1]/2==1){
            C[i+1]-=2;
            carry = 1;
        }
    }
    C[0] = carry;
    return;
}
