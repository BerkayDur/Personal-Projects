#include <stdio.h>

int s5_1(void)
{
    int val, i=1;
    printf("Enter a number: ");
    scanf("%d", &val);
    if (val/10>=100){
        i=4;
    }
    else if (val/10>=10) {
        i=3;
    }
    else if (val/10>=1) {
        i=2;
    }
    else {
        i=1;
    }
    printf("The number %d has %d digits\n", val, i);
    return 0;
}

int s5_2(void)
{
    int a, b;
    char post;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &a, &b);
    if (a/12==2){
        a=0;
        post='A';
    }
    else if (a/12==1 && a!=12){
        a=a-12;
        post='P';
    }
    else{
        post='A';
    }
    printf("Equivalent 12-hour time: %d:%.2d %cM\n", a, b, post);
    return 0;
}

int s5_4(void)
{
    int windspeed;

    printf("Enter wind speed (in knots): ");
    scanf("%d", &windspeed);

    if (windspeed<1){
        printf("Calm");
    }
    else if (windspeed<3){
        printf("Light air");
    }
    else if (windspeed<27){
        printf("Breeze");
    }
    else if (windspeed<47){
        printf("Gale");
    }
    else if (windspeed<63){
        printf("Storm");
    }
    else {
        printf("Hurricane");
    }
    printf("\n");
    return 0;
}

int s5_7(void)
{
    int a, b, c, d;
    int l1, l2, s1, s2;
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    l1 = a>b? a:b;
    s1 = a<b? a:b;
    l2 = c>d? c:d;
    s2 = c<d? c:d;
    printf("Largest: %d\n", l1>l2?l1:l2);
    printf("Smallest: %d\n", s1<s2?s1:s2);
    return 0;
}

int s5_9(void)
{
    int m1, d1, y1, m2, d2, y2, a;
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m1, &d1, &y1);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m2, &d2, &y2);
    if (y1<y2){
        a=1;
    }
    else if (y2<y1){
        a=0;
    }
    else {
        if (m1<m2){
            a=1;
        }
        else if (m2>m1){
            a=0;
        }
        else{
            if (d1<d2){
                a=1;
            }
            else if (d2<d1){
                a=0;
            }
            else {
                printf("Same date\n");
                return 0;
            }
        }
    }
    if (a){
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m1, d1, y1, m2, d2, y2);
    }
    else{
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m2, d2, y2, m1, d1, y1);
    }
    return 0;
}

int s5_10(void)
{
    int num;
    printf("Enter numerical grade: ");
    scanf("%d", &num);
    if (num<0 || num>100){
        printf("Numerical grade must be between 0 and 100!");
    }
    else{
        switch (num/10){
        case(9):case(10):printf("A");break;
        case(8):printf("B");break;
        case(7):printf("C");break;
        case(6):printf("D");break;
        default:printf("F");
        }
    }
    printf("\n");
    return 0;
}
