#include <stdio.h>

#define M 10
void selection_sort(int a[], int N);

int s9_1(void)
{
    int nums[M]={0};

    printf("Enter a series of numbers: ");
    for (int i=0;i<M;i++){
        scanf("%d", &nums[i]);
    }
    selection_sort(nums, M);
    for (int j=0; j<M; j++){
        printf("%d ", nums[j]);
    }
    printf("\n");
    return 0;
}

void selection_sort(int a[], int N)
{
    int max=0, position, hold;
    for (int i=0;i<N;i++){
        max=max>a[i]?max:a[i];
        position=a[i]==max?i:position;
    }
    hold=a[N-1];
    a[N-1]=max;
    a[position]=hold;
    if (N>2){
        selection_sort(a, N-1);
    }
    return;

}
