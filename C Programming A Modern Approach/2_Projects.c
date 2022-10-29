#include <stdio.h>

int s2_1(void)
{
    printf("       *\n      *\n     *\n*   *\n * *\n  *\n");
    return 0;
}

#define PI 3.14159
int s2_2(void)
{
    int r = 10;
    printf("Volume of sphere of radius %d %.1f\n", r, (4.0f/3.0f)*PI*r*r*r);
    return 0;
}

int s2_3(void)
{
    int r;
    printf("Enter the radius of the sphere: ");
    scanf("%d", &r);
    printf("Volume of sphere of radius %d %.1f\n", r, (4.0f/3.0f)*PI*r*r*r);
    return 0;
}

int s2_4(void)
{
    float val;
    printf("Enter an amount: ");
    scanf("%f", &val);
    printf("With tax added: $%.2f\n", val*1.05f);
    return 0;
}

int s2_5(void)
{
    float x;
    printf("Enter a value of x: ");
    scanf("%f", &x);
    printf("%.2f\n", 3*x*x*x*x*x+2*x*x*x*x-5*x*x*x-x*x+7*x-6);
    return 0;
}

int s2_6(void)
{
    float x;
    printf("Enter a value of x: ");
    scanf("%f", &x);
    printf("%.2f\n", ((((3*x+2)*x-5)*x-1)*x+7)*x-6);
    return 0;
}

int s2_7(void)
{
    int dollar;
    printf("Enter a dollar amount: ");
    scanf("%d", &dollar);
    printf("$20 bills: %d\n", dollar/20);
    dollar=dollar%20;
    printf("$10 bills: %d\n", dollar/10);
    dollar=dollar%10;
    printf(" $5 bills: %d\n", dollar/5);
    dollar=dollar%5;
    printf(" $1 bills: %d\n", dollar/1);
    dollar=dollar%1;
    return 0;
}
