#include <stdio.h>

int s4_1(void)
{
    int val;
    printf("Enter a two-digit number: ");
    scanf("%d", &val);
    printf("The reversal is: %d%d\n", val%10, val/10);
    return 0;
}

int s4_2(void)
{
    int val;
    printf("Enter a three-digit number: ");
    scanf("%d", &val);
    printf("The reversal is: %d%d%d\n", (val%100)%10, (val%100)/10, val/100);
    return 0;
}

int s4_3(void)
{
    int a, b, c;
    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &a, &b, &c);
    printf("The reversal is %d%d%d\n", c, b, a);
    return 0;
}

int s4_4(void)
{
    int val;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &val);

    printf("%d", val/(8*8*8*8));
    val=val%(8*8*8*8);
    printf("%d", val/(8*8*8));
    val=val%(8*8*8);
    printf("%d", val/(8*8));
    val=val%(8*8);
    printf("%d", val/(8));
    val=val%(8);
    printf("%d\n", val);
    return 0;
}
