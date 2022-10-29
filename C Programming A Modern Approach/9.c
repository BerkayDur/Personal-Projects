#include <stdio.h>

/*
	A functions is just a grouping of statements that have been given a name.
	Here are some examples of functions:


	double average(double a, double b)
	{
		return (a + b) / 2;
	}

	the double before the average, is used to define the return type. The identifiers a and b, the
	function's parameters, represent the two numbers that will be supplied when average is called.
	Each parameter must have a type. Every function has an executable part, called the body, enclosed in
	braces. To call a function, we write the function name, followed by a list of arguments.

	To place this function in another file, or after the main function, we have to declare it before
	main. For example:

	double average(double a, double b);

	int main(void)
	....
*/


// Program computes pairwise averages of the numbers

double average(double a, double b)
{
	return (a + b) / 2;
}

/*
	#include <stdio.h>

	double average(double a, double b);

	int main(void)
	{
		double x, y, z;

		printf("Enter three numbers: ");
		scanf_s("%lf%lf%lf", &x, &y, &z);
		printf("Average of %g and %g: %g\n", x, y, average(x, y));
		printf("Average of %g and %g: %g\n", y, z, average(y, z));
		printf("Average of %g and %g: %g\n", x, z, average(x, z));

		return 0;
	}
*/

/*
	Not every function returns a value, to specify this, we specify that the return type is void.
*/


// Program that prints a countdown

void countdown(int n)
{
	printf("T minus %d and counting\n", n);
}

/*
	#include <stdio.h>

	void print_count(int n);

	int main(void)
	{
		int i;

		for (i = 10; i > 0; --i) {
			countdown(i);
		}

		return 0;
	}
*/

/*
	Some functions have no parameter, so void is written in braces as the functions input
*/


// Program that prints a bad pun

void pun2(void)
{
	printf("To c, or not to c: that is the question.\n");
}

/*
	#include <stdio.h>

	void pun2(void);

	int main(void)
	{
		pun2();

		return 0;
	}
*/


/*
	The general form of a function definition is:

			return-type function-name ( parameter )
			{
				declarations
				statements
			}

	The return function is governed by these rules:

		Functions may not return arrays, but there are no other restrictions on the return type.

		Specifying that the return type is void indicates that the function doesn't return a value.

		In c99, it is illegal to omit the return type of a function.

	The body of a function may include both declarations and statements.

	Variables declared in the body of a function belong exclusively to that function: they can't be
	examined or modified by other functions.

	Functions of return type void may have an empty body and doesn't produce a value, whereas a non-void
	function produces a value that can be stored in a variable, tested, printed, or used in some way.
	But the value can be discarded if not needed.
*/


// Program that test whether a number is prime or not

#include <stdio.h>
#include <stdbool.h>

bool prime(int n)
{
	int divisor;

	if (n <= 1) {
		return false;
	}
	for (divisor = 2; divisor * divisor <= n; divisor++) {
		if (n % divisor == 0) {
			return false;
		}
	}
	return true;
}

/*
	#include <stdio.h>
	#include <stdbool.h>

	bool prime(int n);

	int main(void)
	{
		int n;

		printf("Enter a number: ");
		scanf_s("%d", &n);
		if (prime(n)) {
			printf("Prime\n");
		}
		else {
			printf("Not prime\n");
		}

		return 0;
	}
*/

/*
	We are not required to place the definition of each function above the point it was called. We are
	able to do this by declaring the function before it is called, which looks like this:

				return-type function-name ( parameters );

	This specific function declaration is known as a function prototype. It doesn't have to specify the
	the names of the function's parameters, as long as their types are present.


	Parameters appear in function definitions - they represent values to be supplied when the function
	is called. Arguments are expressions that appear in function calls. In c, arguments are passed by
	value: when a function is called, each argument is evaluated and its value assigned to the
	corresponding parameter. Since the parameter contains a copy of the argument's value, any changes
	made to the parameter during the execution of the function don't affect the argument.


	In c, it is possible for function calls in which the types of the arguments don't match the types of
	the parameters. These are the cases:

		The compiler has encountered a prototype prior to the call. The value of each argument is
		implicitly converted to the type of the corresponding parameter as if by assignment. For example,
		if an int argument is passed to a function that was expecting a double, the argument is converted
		to double automatically.

		The compiler has not encountered a prototype prior to the call. The compiler performs the
		default argument promotions: 1) float arguments are converted to double. 2) The integral
		promotions are performed, causing char and short arguments to be converted to int (c99 +).

	Relying on the default argument promotions is dangerous and shouldn't be used.


	Arrays can be used as arguments in a function. When a function parameter is a one-dimensional array,
	the length of the array can be left unspecified:

		int f(int a[])
		{
			...
		}

	The function doesn't know how long the array is, and there is no easy way to determine the length
	of the array passed. Instead, we have to pass it as an additional argument.

	#### Using the sizeof operator will not give the correct answer for an array parameter ####

	When supply an array name as a parameter, we don't put square braces after it.

	A function has no way of checking to see that we've passed it the correct array length, so we can
	just exploit this by telling the function that the array is smaller than it really is. Be careful
	not to tell the function that an array argument is larger than it really is.

	A function is able to change the elements of an array parameter.

	If the parameter is a multidimensional array, only the length of the first dimension may be omitted
	when the function is declared. This can be a nuisance, so we can use VLAs (Doesn't work with current
	compiler).

	VLAs can be parameters.


	Can use the keyword static in the declaration of array parameters. e.g.

		int f(int a[static 3], int n)
		{
			...
		}

	Using static has no effect on the behaviour of the program. It may help the compiler to generate
	faster instructions for accessing the array. Also, if an array parameter is multi-dimensional,
	static can only be used in the first dimension.

	Lets say:

		int b[]={3, 0, 3, 4, 1};
		total = f(b, 5);

	The only problem is that b must be declared as a variable and then initialized prior to the call.
	If b isn't needed for any other purpose, it can be mildly annoying to create it solely for the
	purpose of calling a function. In c99, we can avoid this by using a compound literal: an unnamed
	array that's created merely for use in the function. For example,

		total = f((int []){3, 0, 3, 4, 1}, 5);

	We also have the option of specifying a length explicitly:

		(int [4]){1, 9, 2, 1}   <=>   (int []){1, 9, 2, 1}

	Compound literals may contain designators and obey the same rules as initializers. Compound literals
	created inside a function may contain arbitrary expressions, not just constants. For example:

		total = f((int []){2 * i, i + j, j * k}, 3);

	Where i, j, and k are variables.

	A compound literal is an lvalue so the values of its elements may be changed. They can be made
	constant, by using const:

		(const int []){5, 4}


	A non-void function must use the return statement to specify what value it will return. The return
	statement has the form:

			return expression;

	The expression is often just a constant or variable:

			return 0;
			return status;

	More complex expressions are possible. For example, it's not unusual to see the conditional operator
	used in a return expression:

			return n >= 0 ? n : 0;

	When this statement is executed, the expression n >= 0 ? n : 0 is evaluated first.

	If the type of the expression in a return statement doesn't match the function's return type, the
	expression will be implicitly converted to the return type.

	If the return-type of a function is void, the return statement may appear in the function, provided
	no expression is given:

			return;

	This cause the function to terminate at that point, returning nothing, as expected.


	Main should return 0 if the program terminates normally. To indicate abnormal termination, main
	should return any value other than 0. this is known as the programs status code.

	Return isn't the only way to terminate a program. Another is calling the exit function, which
	belongs in the <stdlib.h>. The argument passed to exit has the same meaning as mains return value:
	both indicate the program's status at termination. To indicate normal termination, we'd pass 0:

			exit(0);

	We can also pass EXIT_SUCCESS instead to mean the same thing:

			exit(EXIT_SUCCESS);

	passing EXIT_FAILURE indicates abnormal termination:

			exit(EXIT_FAILURE);

	These are defined in the standard library <stdlib.h>.

	The values of EXIT_SUCCESS and EXIT_FAILURE are macros defined in <stdlib.h>. The values of
	EXIT_SUCCESS and EXIT_FAILURE are implementation-defined; typical values are 0 and 1 respectively.

	return and exit are equivalent in main. The difference between is that exit causes program
	termination regardless of which function calls it. Return only causes program termination only
	when it appears in the main function.


	A function is recursive it it calls itself. For example, the following function computes n!
	recursively:
*/

int fact(int n)
{
	if (n <= 1) {
		return 1;
	}
	else {
		return n * fact(n - 1);
	}
}


/*
	Recursions main use is for algorithms.

	diivide-and-conquer is an algorithmic design method that uses recursion. This method involves
	dividing a larger program into smaller pieces that are then tackled by the same algorithm.

	Quick-sort is an algorithm that uses this method, and it goes like this (for simplicity, we'll
	assume that the array being sorted is indexed from 1 to n):

		1.	Choose an array element e (partitioning element), then rearrange the array so that elements
			1,..., i-1 are lesss than or equal to e, element i contains, and elements i+1,..., n
			are greater than or equal to e.

		2.	Sort elements 1,..., i-1 by using quick-sort recursively

		3.	Sort elements i+1,..., n by using quicksort recursively.
*/


// Program that uses the quicksort algorithm on an array of integers
#include <stdio.h>

#define N 10

void quicksort(int a[], int low, int high)
{
	int middle;

	if (low >= high) {
		return;
	}
	middle = split(a, low, high);
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{
	int part_element = a[low];

	for (;;) {
		while (low < high && part_element <= a[high]) {
			high--;
		}
		if (low >= high) {
			break;
		}
		a[low++] = a[high];

		while (low < high && a[low] <= part_element) {
			low++;
		}
		if (low >= high) {
			break;
		}
		a[high--] = a[low];
	}

	a[high] = part_element;
	return high;
}

/*
	#include <stdio.h>

	#define  N 10

	void quicksort(int a[], int low, int high);
	int split(int a[], int low, int high);

	int main(void)
	{
		int a[N], i;

		printf("Enter %d number to be sorted: ", N);

		for (i = 0; i < N; i++) {
			scanf_s("%d", &a[i]);
		}

		quicksort(a, 0, N - 1);

		printf("In sorted order: ");
		for (i = 0; i < N; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");

		return 0;
	}
*/

/*
	This version of quick-sort works but it's slow. There are numerous ways to improve the program's
	performance, including:

		Improve the partitioning algorithm. Instead of choosing the first element in the array as the
		partitioning element, it'd be better to take the median of the first, middle, and last element.

		Using a different method to sort small arrays. Instead of using quick-sort for recursively all
		the way down to arrays with one element, it's better to use a simpler method for smaller arrays.

		Making quick-sort non -recursive. Although Quick-sort is a recursive algorithm by nature, it's more
		efficient if the recursion is removed.
*/
