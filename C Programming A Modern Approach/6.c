#include <stdio.h>

/*
	A loops is a statement of which its job is to repeatedly execute the loop body. A loop
	has a controlling expression, which is tested each time the loop is executed. There are
	3 loops in c: while, do, and for. The controlling expression is executed before the loop
	body is executed in a while loop, the controlling expression is evaluated after the
	loop body is executed in a do loop.

	The while loop looks like this:
					while ( expression ) statement
	e.g.
		while (i < n){			## Controlling expression ##
			i = i *2			## Loop body ##
		}

	The controlling expression is tested before any iteration.

	The loop continues iterating if the controlling expression stays true.


	We can easily create an infinite while loop by leaving the value of controlling expression to
	always be true.
	e.g.
		while (non-zero) ...

	This loop goes on forever unless, the body contains a statement that transfers control out
	of the loop (break, goto, return) or calls a function that causes the program to terminate.
*/

// Program that prints a table of squares using a while loop

int square(void)
{
	int i, n;

	printf("This program prints a table of square.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);

	i = 1;
	while (i <= n) {
		printf("%10d%10d\n", i, i * i);
		i++;
	}

	return 0;
}


// Program that sums a series of numbers

int sum(void)
{
	int n, sum = 0;

	printf("This program sums a series of integers.\n");
	printf("Enter integers (0 to terminate): ");

	scanf_s("%d", &n);
	while (n != 0) {
		sum += n;
		scanf_s("%d", &n);
	}
	printf("The sum is: %d\n", sum);

	return 0;
}


/*
	The do loop is the same as the while loop, but the controlling expression is tested after
	each execution of the loop body.
	It has the form:
				do {
					statement
				} while (expression);

	The loop body is executed first then the controlling expression is evaluated, if non-zero
	the next iteration of the body is executed and then the controlling expression is
	re-evaluated, if the value is 0, the body is not terminated.
	e.g.
		i = 10;
		do {
			printf("T minus %d and counting\n", i);
			--i;
		} while (i > 0);
*/


// Program calculates the number of digits in an integer

int numdigits(void)
{
	int digits = 0, n;

	printf("Enter a non-negative integer: ");
	scanf_s("%d", &n);

	do {
		n /= 10;
		digits++;
	} while (n > 0);

	printf("The number has %d digit(s).\n", digits);

	return 0;
}

/*
	If this loop above was done with a while loop, the number of digits for 0 would return 0.
*/


/*
	The for loop has the form:
			for (initialization; test condition; incrementation){
				statement
			}

	The for loop can be replaced by the while loop:
			initialization;
			while ( test condition ) {
				statement
				incrementation;
			}

	e.g.
		for (i = 10; i > 0 ; i--){
			printf("T minus %d and counting\n", i);
		}

					<===>

		i = 10;
		while ( i > 0 ) {
			printf("T minus %d and counting\n", i);
			--i;
		}

	The initialization step is only performed once, before the loop begins to execute.

	The for loop is usually the best for incrementing and decrementing a value.
	Common idioms are:
		Counting up from 0 to n-1:
				for (i = 0; i < n; i++) ...
		Counting up from 0 to n:
				for (i = 0; i <= n; i++) ...
		Counting down from n-1 to 0:
				for (i = n - 1; i >= 0; i--) ...
		Counting down from n to 1:
				for (i = n; i > 0; i--) ...


	All 3 of the expressions aren't necessary needed for a for loop.
	e.g.
		i = 10;
		for (; i > 0; --1)
			printf("T minus %d and counting\n", i);

	For this one, we didn't need an initialization, as it's already initialized before.

	e.g.
		for (i = 10; i > 0;)
			printf("T minus %d and counting\n", i--);

	For this one, we didn't need the third expression as the value is decremented in the body
	for the loop.


	with only the conditional expression, we get a for loop that looks like a while loop.
	e.g.
		for (; i > 0;)
			printf("T minus %d and counting\n", i--);

						<===>

		while (i > 0)
			printf("T minus %d and counting\n", i--);

	They're the same but the while loop is much easier to read.


	If in the for loop, the conditional expression is missing, the default value is true (so 1),
	making it an infinite loop, that doesn't terminate (unless done other).
	e.g.
		for (;;) ...


	In a for loop, we can declare a variable and assign it in the initialization. If this variable
	already exists, this statement creates a new version that is only used within the loop.
	e.g.
		for (int i = 0; i < n; i++) {
			printf("%d", i);			### Works ###
		}
		printf("%d", i);				### Wrong ###

	This works, but it is not possible to access the variable outside the loop.


	When writing for a for loop, we may want more than one initialization and this can be done
	through using a comma expression (in the initialization or incrementation).
	It has the form:
					expr1, expr2

	First, expr1 is evaluated and its value is discarded, then expr2 is evaluated and its value
	is the value of the entire expression. If i=1 and j=5, and the comma expression
	++i, i + j is evaluated, the value of this expression is 7.
	This is has less precedence than most and is left-associative, so:
			i = 1, j = 2, k = i + j
						<==>
			((i = 1), (j = 2)), (k = (i + j))


	This is useful when we want 2 initialization in a for loop.
	e.g.
		sum = 0;
		for (i = 1; i <= N; i++)
			sum +=i;
				<==>
		for (sum = 0, i = 1; i <=N; i++)
			sum +=i;
*/


// Program prints a table of square using a for loop

int square2(void)
{
	int i, n;

	printf("This program prints a table of square.\n");
	printf("Enter number of entries in table: ");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++) {
		printf("%10d%10d\n", i, i * i);
	}

	return 0;
}



// Program prints a table of square using an odd method

int square3(void)
{
	int i, n, odd, square;

	printf("This program prints a table of square.\n");
	printf("Enter number of entries in table: ");
	scanf_s("%d", &n);

	i = 1;
	odd = 3;
	for (square = 1; i <= n; odd += 2) {
		printf("%10d%10d\n", i, square);
		++i;
		square += odd;
	}

	return 0;
}


/*
	The break statement can be used to jump out of a loop.
	e.g.
		for (;;){
			printf("Enter a number (enter 0 to stop): ");
			scanf_s("%d", &n);
			if (n == 0)
				break;
			printf("%d cubed is %d\n", n, n * n * n);
		}

	breaks will only leave the innermost of a nested while, do, for, or switch statement.


	The continue statement (only works for loops) doesn't exit from a loop, it transfers control
	just before the end of the loop, so control remains inside the loop.
	e.g.
		n = 0;
		sum = 0;
		while (n < 10) {
			scanf_s("%d", &i);
			if (i == 0)
				continue;
			sum += i;
			n++;
			## Continue jumps here ##
		}



	The goto statement is capable of jumping to any statement within a function, provided it
	has a label.
	A label is an identifier placed at the beginning of a statement:

			identifier : statement

	A statement may have more than 1 label.
	The goto statement has the form:

			goto identifier;

	e.g.
		for (d = 2; d < n; d++)
			if (n % d ==0)
				goto done;

			done:
			if (d < n)
				printf("%d is divisible by %d\n", n, d);
			else
				printf("%d is prime\n", n);


	goto is rarely used because the other statements are similar. But the goto statement can
	exited a nested loop.
	e.g.
		while (...) {
			switch (...) {
				...
				goto loop_done;
				...
			}
		}
		loop_done: ...

*/

// Program to balance a check-book

int checking(void)
{
	int cmd;
	float balance = 0.0f, credit, debit;

	printf("*** ACME check-book-balancing program ***\n");
	printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");

	for (;;) {
		printf("Enter command: ");
		scanf_s("%d", &cmd);
		switch (cmd) {
		case 0:
			balance = 0.0f;
			break;
		case 1:
			printf("Enter amount of credit: ");
			scanf_s("%f", &credit);
			balance += credit;
			break;
		case 2:
			printf("Enter amount of debit: ");
			scanf_s("%f", &debit);
			balance -= debit;
			break;
		case 3:
			printf("Current balance: $%.2f\n", balance);
			break;
		case 4:
			return 0;
		default:
			printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");
			break;
		}
	}
}

/*
	null means nothing and a statement can be null if it contains nothing.
	e.g.
		i = 0; ; j = 1;
	This line contains 3 statements: an assignment to i, a null statement, and an assignment to j.


*/
