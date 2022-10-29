#include <stdio.h>
#include <ctype.h>

int s7_2(void)
{
	int i, n;

	printf("This program prints a table of square.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);
    getchar();
	for (i = 1; i <= n;i++) {
        if (i%24==0){
            printf("Press Enter to continue... ");
            while (1){
                    if (getchar()=='\n'){
                        break;
                    }
                    continue;
            }
        }
		printf("%10d%10d\n", i, i * i);
	}
    printf("\n");
	return 0;
}

int s7_4(void)
{
    char x=1;
    printf("Enter phone number: ");
    while (x!='\n'){
        x=toupper(getchar());
        if (x!=81 && (x>64 && x<90)){
            if (x<68){
                putchar(50);
            }
            else if (x<71){
                putchar(51);
            }
            else if (x<74){
                putchar(52);
            }
            else if (x<77){
                putchar(53);
            }
            else if (x<80){
                putchar(54);
            }
            else if (x<84){
                putchar(55);
            }
            else if (x<87){
                putchar(56);
            }
            else{
                putchar(57);
            }
        }
        else{
            putchar(x);
        }
    }
    printf("\n");
    return 0;
}

int s7_7(void)
{
    int a1, a2, b1, b2;
    char op;
    printf("Enter 2 fractions with an operator between them: ");
    scanf("%d/%d%c%d/%d", &a1, &a2, &op, &b1, &b2);
    if (op=='+'){
        printf("sum is: %d/%d\n", a1*b2+a2*b1, a2*b2);
    }
    else if (op=='-'){
        printf("difference is: %d/%d\n", a1*b2-a2*b1, a2*b2);
    }
    else if (op=='/'){
        printf("quotient is: %d/%d\n", a1*b2, a2*b1);
    }
    else if (op=='*'){
        printf("product is: %d/%d\n", a1*b1, a2*b2);
    }
    else{
        printf("Please enter of the form: a/bXc/d\n");
    }

    return 0;
}

int s7_9(void)
{
    int hour, minute;
    char x;
    printf("Enter a 12-hour time: ");
    scanf("%d:%d", &hour, &minute);
    getchar();
    while ((x=getchar())!='\n'){
        if (x=='P' || x=='p'){
            hour=hour+12;
            if (hour>=24){
                hour=hour-24;
            }
            break;
        }
    }
    printf("Equivalent 24-hour time: %d:%.2d\n", hour, minute);
    return 0;
}

int s7_10(void)
{
    int i=0;
    char x;
    printf("Enter a sentence: ");
    while ((x=toupper(getchar()))!='\n'){
        switch (x){
        case(65):case(69):case(73):case(79):case(85):
            i++;
        }
    }
    printf("Your sentence contains %d vowels.\n", i);
    return 0;
}

int s7_11(void)
{
    char c, f, x=0, l=0;

    printf("Enter a first and last name: ");

    getchar();
    while ((c=getchar())==' '){
    }
    f=c;
    while ((c=getchar())!='\n'){
        if (x==' ' && c!=' '){
            l++;
        }
        if (l && c!=' '){
            putchar(c);
        }
        x=c;

    }
    printf(", %c.\n", f);
    return 0;
}

int s7_12(void)
{
    char c;
    float a, b;
    printf("Enter an expression: ");
    scanf("%f", &a);
    for (;;){
        c=getchar();
        if (c==' ' || c=='\t' || c=='\n'){
            break;
        }
        scanf("%f", &b);
        printf("%f %c %f\n", a, c, b);
        if (c=='+'){
            a+=b;
        }
        else if (c=='-'){
            a-=b;
        }
        else if (c=='*'){
            a*=b;
        }
        else if (c=='/'){
            a/=b;
        }
    }
    printf("Value of expression: %g\n", a);
    return 0;
}

int s7_13(void)
{
    int words=1, letters=1;
    char c;

    printf("Enter a sentence: ");
    getchar();
    while ((c=getchar())!='\n'){
        if (c!=' '){
            letters++;
        }
        else{
            words++;
        }
    }
    printf("Average word length: %g\n",((float)letters)/words);
    return 0;
}
