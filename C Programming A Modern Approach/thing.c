#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Section 2

int a1(void)
{
    printf("       *\n");
    printf("      *\n");
    printf("     *\n");
    printf("*   *\n");
    printf(" * *\n");
    printf("  *\n");
    return 0;
}

int a2(void)
{
    #define PI 3.1415
    float r=10.0;

    printf("Volume = %f", (4.0f/3.0f)*PI*r*r*r);
    return 0;
}

int a3(void)
{
    #define PI 3.1415
    float r;
    printf("Enter radius of sphere: ");
    scanf("%f", &r);

    printf("Volume = %.2f", (4.0f/3.0f)*PI*r*r*r);
    return 0;
}

int a4(void)
{
    float val;

    printf("Enter an amount: ");
    scanf("%f", &val);
    printf("With tax added: $%.2f", val*1.05);
    return 0;
}

int a5(void)
{
    float x;
    printf("Enter x value: ");
    scanf("%f", &x);
    printf("%f", 3*x*x*x*x*x+2*x*x*x*x-5*x*x*x-x*x+7*x-6);
    return 0;
}

int a6(void)
{
    float x;
    printf("Enter x value: ");
    scanf("%f", &x);
    printf("%f", ((((3*x+2)*x-5)*x-1)*x+7)*x-6);
    return 0;
}

int a7(void)
{

    int val;
    printf("Enter a dollar amount: ");
    scanf("%d", &val);
    printf("$20 bills: %d\n", val/20);
    val%=20;
    printf("$10 bills: %d\n", val/10);
    val%=10;
    printf(" $5 bills: %d\n", val/5);
    val%=5;
    printf(" $1 bills: %d\n", val);
    return 0;
}


// Section 3

int b1(void)
{
    int month, day, year;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("you entered the date %d%.2d%.2d\n", year, month, day);
    return 0;
}

int b2(void)
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

int b3(void)
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

int b4(void)
{
    int a, b, c;
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%3d) %3d-%4d", &a, &b, &c);
    printf("You entered %3d.%3d.%4d\n", a, b, c);
    return 0;
}

int b5(void)
{
    int a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4, d1, d2, d3, d4;
    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
          &a1, &a2, &a3, &a4, &b1, &b2, &b3, &b4,
          &c1, &c2, &c3, &c4, &d1, &d2, &d3, &d4);
    printf("%2d %2d %2d %2d\n", a1, a2, a3, a4);
    printf("%2d %2d %2d %2d\n", b1, b2, b3, b4);
    printf("%2d %2d %2d %2d\n", c1, c2, c3, c4);
    printf("%2d %2d %2d %2d\n\n", d1, d2, d3, d4);
    printf("Row sums: %2d %2d %2d %2d\n", a1+a2+a3+a4, b1+b2+b3+b4,
           c1+c2+c3+c4, d1+d2+d3+d4);
    printf("column sums: %2d %2d %2d %2d\n", a1+b1+c1+d1, a2+b2+c2+d2,
           a3+b3+c3+d3, a4+b4+c4+d4);
    printf("Diagonal sums: %2d %2d\n", a1+b2+c3+d4, a4+b3+c2+d1);
    return 0;
}

int b6(void)
{
    int a1, a2, b1, b2;
    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d", &a1, &a2, &b1, &b2);
    printf("The sum is %d/%d\n", a1*b2+b1*a2, a2*b2);
    return 0;
}


// Section 4

int c1(void)
{
    int val;
    printf("Enter a two-digit number: ");
    scanf("%d", &val);
    printf("The reversal is: %1d%1d\n", val%10, val/10);
    return 0;
}

int c2(void)
{
    int val, a, b, c;
    printf("Enter a three-digit number: ");
    scanf("%d", &val);
    a=(val%100)%10;
    b=(val%100)/10;
    c=(val/100);
    printf("The reversal is: %1d%1d%1d\n", a,b,c);
    return 0;
}

int c3(void)
{
    int a, b, c;
    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d",&a,&b,&c);
    printf("The reversal is: %1d%1d%1d\n",c,b,a);
    return 0;
}

int c4(void)
{
    int val;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &val);
    printf("In octal, your number is: 0");
    printf("%d", val/(8*8*8));
    val%=8*8*8;
    printf("%d", val/(8*8));
    val%=8*8;
    printf("%d", val/(8));
    val%=8;
    printf("%d\n", val);
    return 0;
}


// Section 5

int d1(void)
{
    int b, i=1, a;
    printf("Enter a number: ");
    scanf("%d", &b);
    a=b;
    if ((a/10)>0){
        a/=10;
        i++;
    }
    if ((a/10)>0){
        a/=10;
        i++;
    }
    printf("The number %d has %d digits\n", b, i);
    return 0;
}

int d2(void)
{
    int a, b;
    printf("Enter a 24-hour time: ");
    scanf("%2d:%2d", &a, &b);
    if (a>12){
        a=a-12;
        printf("Equivalent 12-hour time: %d:%d PM", a, b);
    }
    else if (a==24){
        a=0;
        printf("Equivalent 12-hour time: %d:%d AM", a, b);
    }
    else{
        printf("Equivalent 12-hour time: %d:%d AM", a, b);
    }
    return 0;
}

int d7(void)
{
    int a, b, c, d, x1, x2, y1, y2;
    printf("Enter 4 integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    x1=a>b?a:b;
    y1=a<b?a:b;
    x2=c>d?c:d;
    y2=c<d?c:d;
    printf("Largest: %d\n",x1>x2?x1:x2);
    printf("Smallest: %d\n", y1<y2?y1:y2);
    return 0;
}


// section 6

int e1(void)
{
    float max=0, a;
    do {
        printf("Enter a number: ");
        scanf("%f", &a);
        max=max>a?max:a;
    } while (a!=0);
    printf("The largest number entered was %g", max);
    return 0;
}

int e2(void)
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

int e3(void)
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

    printf("In lowest terms: %d/%d", a/max, b/max);
    return 0;
}

int e5(void)
{
    int rem, num;
    printf("Enter a number to be reversed: ");
    scanf("%d", &num);

    printf("The number reversed is: ");
    while (num>0){
        rem=num%10;
        num=num/10;
        printf("%d", rem);
    }
    printf("\n");
    return 0;
}

int e6(void)
{
    int val;
    printf("Enter a value: ");
    scanf("%d", &val);

    for(int i=2;i*i<=val;i+=2){
        printf("%d\n", i*i);
    }
    return 0;
}

int e8(void)
{
    int days, start, count=0;

    printf("Enter number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week (1=sun, 7=sat): ");
    scanf("%d", &start);

    for (int i=start-1; i>0; i--){
        printf("   ");
        count++;
    }
    for (int i=1; i<=days;){
        if (count==7){
            count=0;
            printf("\n");
        }
        else{
            count++;
            printf("%2d ", i++);
        }
    }

    return 0;
}

int e10(void)
{
    int m,d,y,sm,sd,sy;

    for (;;){
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &m, &d, &y);
        if (m==0 && d==0 && y==0){
            break;
        }
        if (y<sy){
            sy=y, sd=d, sm=m;
            continue;
        }
        if (y==sy && m<sm){
            sy=y, sd=d, sm=m;
            continue;
        }
        if (y==sy && m==sm && d<sd){
            sy=y, sd=d, sm=m;
        }
    }
    printf("%d/%d/%.2d\n is the earliest date", sm, sd, sy);
    return 0;
}

int e11(void)
{
    int n, fac=1, j=1, med;
    float val=1;

    printf("Enter an integer: ");
    scanf("%d", &n);

    for (int i=1; i<=n; i++){
        med=(fac*(j++));
        fac=med;
        val+=(1.0f/(fac));

    }
    printf("%f\n", val);
    return 0;
}

int e12(void)
{
    int E, fac=1, j=1, med;
    float val=1, current=10;

    printf("Enter an integer: ");
    scanf("%d", &E);

    for (;current>E;){
        med=(fac*(j++));
        fac=med;
        current=(1.0f/(fac));
        val+=current;
    }
    printf("%f\n", val);
    return 0;
}


// section 7

int f2(void)
{
	int i, n;
	char x;

	printf("This program prints a table of square.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);
    getchar();
	for (i = 1; i <= n; i++) {
        if ((i-1)%24==0 && i!=1){
            printf("Press Enter to continue...");
            while ((x=getchar())!='\n'){

            }
        }
		printf("%10d%10d\n", i, i * i);
	}

	return 0;
}

int f4(void)
{
    char x;

    printf("Enter phone number: ");
    while((x=getchar())!='\n'){
        switch(x){
        case('A'):case('B'):case('C'):
            printf("2"); break;
        case('D'):case('E'):case('F'):
            printf("3"); break;
        case('G'):case('H'):case('I'):
            printf("4"); break;
        case('J'):case('K'):case('L'):
            printf("5"); break;
        case('M'):case('N'):case('O'):
            printf("6"); break;
        case('P'):case('R'):case('S'):
            printf("7"); break;
        case('T'):case('U'):case('V'):
            printf("8"); break;
        case('W'):case('X'):case('Y'):
            printf("9"); break;
        default:
            putchar(x);
        }
    }
    printf("\n");
    return 0;
}

int f5(void)
{
    int sum=0;
    char x;

    printf("Enter a word: ");
    while((x=getchar())!='\n'){
        x=toupper(x);
        switch(x){
        case('A'):case('E'):case('I'):case('L'):case('N'):case('O'):case('R'):case('S'):
        case('T'):case('U'):
            sum+=1; break;
        case('D'):case('G'):
            sum+=2; break;
        case('B'):case('C'):case('M'):case('P'):
            sum+=3; break;
        case('F'):case('H'):case('V'):case('W'):case('Y'):
            sum+=4; break;
        case('K'):
            sum+=5; break;
        case('J'):case('X'):
            sum+=8; break;
        case('Q'):case('Z'):
            sum+=10; break;
        }
    }
    printf("Scrabble value: %d\n", sum);
    return 0;
}

int f10(void)
{
    int v=0;
    char x;

    printf("Enter a sentence: ");
    while((x=getchar())!='\n'){
        x=toupper(x);
        switch(x){
        case('A'):case('E'):case('I'):case('O'):case('U'):
            v+=1;
        }
    }
    printf("Your sentence contains %d vowels.\n", v);
    return 0;
}

int f11(void)
{

    char x, f;

    printf("Enter a first and last name: ");
    for(int i=0;(x=getchar())!='\n';){
        if (i==0 & x!=' '){
            f=x;
            i++;
            while((x=getchar())!=' '){
            }
        }
        else if(i==1 & x!=' '){
            putchar(x);
        }
    }
    printf(", %c.\n", f);
    return 0;
}

int f12(void)
{
    float val, a, b;
    char op;

    printf("Enter an expression: ");
    scanf("%f",&a);
    while((op=getchar())!='\n'){
        scanf("%f",&b);
        a=(op=='*')?a*b:a;
        a=(op=='/')?a/b:a;
        a=(op=='+')?a+b:a;
        a=(op=='-')?a-b:a;
    }
    printf("\nValue of expression: %g\n",a);
    return 0;
}

int f13(void)
{
    char x;
    float i=1, sum=0;

    printf("Enter a sentence: ");
    while((x=getchar())!='\n'){
        if(x==' '){
            i++;
        }
        else{
            sum++;
        }
    }
    printf("Average word length is: %g\n", sum/i);
    return 0;
}

int f14(void)
{
    float x, y=1, avg, div, oy;

    printf("Enter a positive number: ");
    scanf("%f", &x);
    while(1){
        div=x/y;
        avg=(div+y)/2;
        oy=y;
        y=avg;
        if(fabs(y-oy)<0.00001*y){
            break;
        }
    }
    printf("Square root: %f\n", y);
    return 0;
}
    //157
