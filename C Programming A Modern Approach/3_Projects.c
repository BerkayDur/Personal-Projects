#include <stdio.h>

int s3_1(void)
{
    int month, day, year;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("you entered the date %d%.2d%.2d\n", year, month, day);
    return 0;
}

int s3_2(void)
{
    int item, month, day, year;
    float price;

    printf("Enter item number: ");
    scanf("%d", &item);
    printf("Enter unit price: ");
    scanf("%f", &price);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("Item\t\tUnit \t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%-d \t\t$%7.2f \t\t%d/%d/%d\n", item, price, month, day, year);
    return 0;
}

int s3_3(void)
{
    int a, b, c, d, e;
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &a, &b, &c, &d, &e);
    printf("GS1 prefix: %d\n", a);
    printf("Group identifier: %d\n", b);
    printf("Publisher code: %d\n", c);
    printf("Item number: %d\n", d);
    printf("Check digit: %d\n", e);
    return 0;
}

int s3_4(void)
{
    int a, b, c;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%3d) %3d-%4d", &a, &b, &c);
    printf("You entered %3d.%3d.%4d\n", a, b, c);
    return 0;
}

s3_6(void)
{
    int a1, a2, b1, b2;
    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d", &a1, &a2, &b1, &b2);
    printf("The sum is %d/%d\n", a1*b2+b1*a2, a2*b2);
    return 0;
}
