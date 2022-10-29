#include <stdio.h>
#include <ctype.h>

int s12_1a(void)
{
    char x, word[100];
    int i;
    printf("Enter a message: ");
    for (i=0; (x=getchar())!='\n';i++){
        word[i]=x;
    }
    for(i--;i>=0;i--){
        putchar(word[i]);
    }
    return 0;
}

int s12_1b(void)
{
    char word[100];
    char *p=word, x;
    printf("Enter a message: ");
    while ((x=getchar())!='\n' && p<word+100){
        *p++=x;
    }
    p--;
    while(p>=word){
        putchar(*p--);
    }
    return 0;
}


int s12_2a(void)
{
    int i;
    char message[100], x;
    printf("Enter a message: ");
    for (i=0; (x=getchar())!='\n';){
        x=toupper(x);
        if (x>64 && x<91){
            message[i++]=x;
        }
        else
            continue;
    }
    i--;
    for (int j=0;i>0;j++,i--){
        if (message[i]!=message[j]){
            printf("Not a palindrome");
            return 0;
        }
    }
    printf("Palindrome");
    return 0;
}

int s12_2b(void)
{
    char message[100];
    char x, *p=message, *q=message;
    printf("Enter a message: ");
    for (; (x=getchar())!='\n';){
        x=toupper(x);
        if (x>64 && x<91){
            *p++=x;
        }
        else
            continue;
    }
    p--;
    for (;p>=message;){
        if (*p--!=*q++){
            printf("Not a palindrome");
            return 0;
        }
    }
    printf("Palindrome");
    return 0;
}
