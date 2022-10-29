

int FindMaxCrossingSubarrayInt(int const A[], int const mid, int  const n, int *const left_index, int *const right_index)
{
    int left_sum = -2147483648;
    int right_sum = -2147483648;

    *left_index = mid;
    *right_index = mid;

    for (int i=mid-1, sum=0;i>=0;i--){
        sum += A[i];
        if (sum>left_sum){
            left_sum = sum;
            *left_index = i;
        }
    }
    for (int i=mid, sum=0;i<n;i++){
        sum += A[i];
        if (sum>right_sum){
            right_sum = sum;
            *right_index = i;
        }
    }

    return left_sum + right_sum;
}

int FindMaxSubarrayInt(int const A[], int const n, int *const left_index, int *const right_index)
{
    if (n==1){
        *left_index = 0;
        *right_index = 0;
        return A[0];
    }
    int mid = n/2;

    int left_low, left_high;
    int left_sum = FindMaxSubarrayInt(A,mid,&left_low, &left_high);

    int right_low, right_high;
    int right_sum = FindMaxSubarrayInt(&A[mid],n-mid,&right_low, &right_high);

    right_low += mid;
    right_high += mid;

    int cross_low, cross_high;
    int cross_sum = FindMaxCrossingSubarrayInt(A,mid,n,&cross_low, &cross_high);

    if (left_sum >= right_sum && left_sum >= cross_sum){
        *left_index = left_low;
        *right_index = left_high;

        return left_sum;
    }

    else if (right_sum >= left_sum && right_sum >= cross_sum){
        *left_index = right_low;
        *right_index = right_high;
        return right_sum;
    }

    else {
        *left_index = cross_low;
        *right_index = cross_high;
        return cross_sum;
    }
}

int FindMaxSubArrayIntBadMethod(int const A[], int const n, int *const start_index, int *const end_index)
{
    int real_sum = -2147483648;
    int sum;

    *start_index = *end_index = 0;

    for (int i=0;i<n;i++){
        sum = 0;
        for (int j=i;j<n;j++){
            sum += A[j];
            if (sum>real_sum){
                real_sum = sum;
                *start_index = i;
                *end_index = j;
            }
        }
    }
    return real_sum;
}

int FindMaxSubarrayIntFastest(int const A[], int const n, int *const start_index, int *const end_index)
{
    int max_sum = 0;
    int sum =0;
    int i;
    *start_index = 0;
    *end_index = 0;

    for (int j=0;j<n;j++){
        if (sum <=0){
            i = j;
            sum = A[j];
        }
        else{
            sum += A[j];
        }
        if (sum > max_sum){
            max_sum = sum;
            *start_index = i;
            *end_index = j;
        }

    }
    return max_sum;
}
