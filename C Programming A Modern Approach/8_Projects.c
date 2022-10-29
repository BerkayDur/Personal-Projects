#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int s8_1(void)
{
	bool digit_seen[10] = { false }, digits[10]={ false };
	int digit, i;
	long n;
	printf("Enter a number: ");
	scanf("%ld", &n);
	while (n > 0) {
		digit = n % 10;
		if (digit_seen[digit]) {
            digits[digit]=true;
            i=1;
		}
		digit_seen[digit] = true;
		n /= 10;
	}
	if (i) {
        printf("Repeated digit(s): ");
        for(;i<10;i++){
            if (digits[i]){
                printf("%d ", i);
            }
        }
	}
	else {
		printf("No repeated digits\n");
	}
    printf("\n");
	return 0;
}

int s8_2(void)
{
	int digit, digits[10]={ 0 };
	long n;
	printf("Enter a number: ");
	scanf("%ld", &n);
	while (n > 0) {
		digit = n % 10;
        digits[digit]++;
		n /= 10;
	}
	printf("Digit:\t\t");
    for (int i=0; i<10; i++){
        printf("%d ", i);
    }
    printf("\nOccurrences:\t");
    for (int i=0; i<10; i++){
        printf("%d ", digits[i]);
    }
    printf("\n");
	return 0;
}

int s8_6(void)
{
    char message[100], val;
    int c=0;

    printf("Enter message: ");
    for (; (val=getchar())!='\n'; c++){
        message[c]=toupper(val);
    }
    for (int i=0; i<c; i++){
        switch (message[i]){
            case 'A': message[i]='4';break;
            case 'B': message[i]='8';break;
            case 'E': message[i]='3';break;
            case 'I': message[i]='1';break;
            case 'O': message[i]='0';break;
            case 'S': message[i]='5';break;
        }
        printf("%c", message[i]);
    }
    printf("!!!!!!!!!!!!!!!\n");
    return 0;
}

int s8_7(void)
{
    int nums[5][5], sum;

    for (int i=0; i<5; i++){
        printf("Enter row %d: ", i+1);
        for (int j=0; j<5; j++){
            scanf("%d", &nums[i][j]);
        }
    }
    printf("Row totals: ");
    for (int i=0; i<5; i++){
        sum=0;
        for (int j=0; j<5; j++){
            sum+=nums[i][j];
        }
        printf("%d ", sum);
    }
    printf("\n");
    printf("Column totals: ");
    for (int i=0; i<5; i++){
        sum=0;
        for (int j=0; j<5; j++){
            sum+=nums[j][i];
        }
        printf("%d ", sum);
    }
    printf("\n");
    return 0;
}

int s8_8(void)
{
    int nums[5][5], sum, max, min;

    for (int i=0; i<5; i++){
        printf("Enter Student %d's grades: ", i+1);
        for (int j=0; j<5; j++){
            scanf("%d", &nums[i][j]);
        }
    }
    printf("\tTotal\tAverage\n");
    for (int i=0; i<5; i++){
        sum=0;
        for (int j=0; j<5; j++){
            sum+=nums[i][j];
        }
        printf("S%d:\t%d\t%g\n", i+1, sum, sum/5.0f);
    }
    printf("\n");
    printf("\tAverage\t\tHighest\t\tLowest\n");
    for (int i=0; i<5; i++){
        sum=0;
        max=0;
        min=100;
        for (int j=0; j<5; j++){
            sum+=nums[j][i];
            max=nums[j][i]>max?nums[j][i]:max;
            min=nums[j][i]<min?nums[j][i]:min;
        }
        printf("T%d:\t%g\t%d\t%d\n", i+1, sum/5.0f, max, min);
    }
    printf("\n");
    return 0;
}
