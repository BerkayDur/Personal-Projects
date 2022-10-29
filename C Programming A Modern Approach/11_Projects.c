#include <stdio.h>

void pay_amount(int dollar, int *twenties, int *tens, int *fives, int *ones);

int s11_1(void)
{
    int dollar, a, b, c, d;
    printf("Enter a dollar amount: ");
    scanf("%d", &dollar);
    pay_amount(dollar, &a, &b, &c, &d);
    printf("$20 bills: %d\n", a);
    printf("$10 bills: %d\n", b);
    printf(" $5 bills: %d\n", c);
    printf(" $1 bills: %d\n", d);
    return 0;
}

void pay_amount(int dollar, int *twenties, int *tens, int *fives, int *ones)
{
    int left;
    *twenties=dollar/20;
    left=dollar%20;
    *tens=left/10;
    left=left%10;
    *fives=left/5;
    left=left%5;
    *ones=left;
    return;
}


void reduce(int numerator, int denominator, int *reduced_numberator, int *reduced_denominator);

int s11_2(void)
{
    int a, b, x, y;

    printf("Enter a fraction: ");
    scanf("%d/%d", &a, &b);
    reduce(a,b,&x,&y);
    printf("In lowest terms: %d/%d\n", x, y);
    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int max, min, med;
    max = numerator>denominator?numerator:denominator;
    min = numerator<denominator?numerator:denominator;
    while (min!=0){
        med=min;
        min=max%min;
        max=med;
    }
    *reduced_numerator=numerator/max;
    *reduced_denominator=denominator/max;

}
