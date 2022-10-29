#include <stdio.h>

int s6_1(void)
{
    float num, max=0;


    for(;;){
        printf("Enter a number: ");
        scanf("%f", &num);
        if (num<=0){
            break;
        }
        if (num>max){
            max=num;
        }
    }
    printf("The largest number entered was %f\n", max);
    return 0;
}

int s6_2(void)
{
    int a, b, max, min, med;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    max = a>b?a:b;
    min = a<b?a:b;
    while (min!=0){
        med=min;
        min=max%min;
        max=med;
    }
    printf("Greatest common denominator: %d\n", max);
    return 0;
}

int s6_3(void)
{
    int a, b, max, min, med;

    printf("Enter a fraction: ");
    scanf("%d/%d", &a, &b);

    max = a>b?a:b;
    min = a<b?a:b;
    while (min!=0){
        med=min;
        min=max%min;
        max=med;
    }

    printf("In lowest terms: %d/%d\n", a/max, b/max);
    return 0;
}

int s6_5(void)
{
    int a;

    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Reversed: ");
    do {
        printf("%d", a%10);
        a=a/10;
    }   while (a!=0);
    printf("\n");
    return 0;
}

int s6_6(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i=2;i*i<=n;){
        printf("%d\n",i*i);
        i+=2;
    }
    return 0;
}

int s6_8(void)
{
    int days, start, j=1;
    printf("Enter number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week (1=sun, 7=sat): ");
    scanf("%d", &start);
    for (int i=1; j<=days;){
        if (i<start && j==1){
            printf("   ");
            i++;
        }
        else if (i<=7){
            printf("%2d ", j++);
            i++;
        }
        else {
            printf("\n");
            i=1;
        }
    }
    return 0;
}

int s6_11(void)
{
    int n;
    float result=1, value=1;
    printf("Enter the number of sums to approximate e: ");
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        result=result+value*(1.0f/i);
        value=value*(1.0f/i);
    }
    printf("%f\n", result);
    return 0;
}

int s6_12(void)
{
    float result=1, value=1, n;
    printf("Enter an epsilon value: ");
    scanf("%d", &n);
    for (int i=1; value>n; i++){
        result=result+value*(1.0f/i);
        value=value*(1.0f/i);
    }
    printf("%f\n", result);
    return 0;
}
