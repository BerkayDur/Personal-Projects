#include <stdio.h>

/*
	One-Dimensional Arrays

	An Array is a data structure containing a number of data values, all of which have the
	same type. These values ,known as elements, can be individually selected by their position
	within the array.

	The simplest type of Array has one dimension. The elements in an one-dimensional array are
	conceptually arranged one after another in a single row.

	To declare an array, we must specify the type of the array's elements and the number of
	elements.
	e.g.
		int a[10];

	This is an array a that has 10 elements of type int.

	The elements of an array may be of any type; the length of the array can be specified by
	any (integer) constant expression. If we need to change the length of an array at a later
	date, it may be wise to use a macro to define the length of an array.
	e.g.
		#define N 10
		...
		int a[N];

	To access a particular element in an array, we can reference its index. The index starts
	at 0.

	expressions of the form a[i] are lvalues, so they can be used in the same way as ordinary
	variables:
	a[0] = 1;
	printf("%d\n", a[5]);
	++a[i];

	If an array is defined to contain an element of type T, then each element in the array is
	treated as if it were a variable of type T.

	Arrays and for loops works really well with one another. for loops can be used to perform
	an operation on every element in an array.

	For an array a of length N:

		for (i = 0; i < N; i++)
			a[i] = 0;				## clears a ##

		for (i = 0; i < N; i++)
			scanf("%d", &a[i]);		## reads data into a ##

		for (i = 0; i < N; i++)
			sum += a[i]				## sums the elements of a ##


	C doesn't require index bounds to be checked, so if the index goes out of bounds, the
	program's behaviour is undefined.

	Array subscripts may contain integer expressions.
*/


// Program that reverses a series of numbers
#define N 10

int reverse(void)
{
	int a[N], i;

	printf("Enter %d numbers: ", N);
	for (i = 0; i < N; i++) {
		scanf_s("%d", &a[i]);
	}

	printf("In reverse order: ");
	for (i = N - 1; i >= 0; i--) {
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}

/*
	We can use an array initializer to give an array initial values. We can do this by making it
	equal to a list of constant expressions:
		int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				## The initial value of a is {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ##

	If the initializer is shorter than the array, the remaining values become 0's:
		int a[10] = {1, 2, 3, 4, 5, 6};
				## The initial value of a is {1, 2, 3, 4, 5, 6, 0, 0, 0, 0} ##

	Using this, we can easily initialize an array of all 0's:
		int a[10] = {0};
				## The initial value of a is {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ##

	The initializer cannot be completely empty and cannot be longer than the array.

	If an initializer is present, the length of the array may be omitted:
		int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				## The initial value of a is {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ##


	If we want to initialize:
		int a[15] = {0, 0, 29, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 48};
				## The initial value of a is {0, 0, 29, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 48} ##

	Instead of writing this all down, we just use designated initializers:
		int a[15] = {[2] = 29, [9] = 7, [14] = 48};
				## The initial value of a is {0, 0, 29, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 48} ##
*/


//	Program that numbers for repeated digits
#include <stdbool.h>

int repdigit(void)
{
	bool digit_seen[10] = { false };
	int digit;
	long n;

	printf("Enter a number: ");
	scanf_s("%ld", &n);

	while (n > 0) {
		digit = n % 10;
		if (digit_seen[digit]) {
			break;
		}
		digit_seen[digit] = true;
		n /= 10;
	}

	if (n > 0) {
		printf("Repeated digit\n");
	}
	else {
		printf("No repeated digit\n");
	}

	return 0;
}

/*
	We can use the sizeof operator to determine the size of an array (in bytes). If a is an
	array that consists of 10 numbers of type int, then sizeof(a) is typically 40. We can
	determine the length of an array by doing:

		sizeof(a) / sizeof(a[0])

	We can use this in a loop. And this is better as the loop doesn't have to be modified if
	the array length should change.
	The expression:

			i < sizeof(a) / sizeof(a[0])

	can produce an warning with some compliers, as i has type int, whereas sizeof produces a
	value of type size_t (an unsigned type). But this is safe as both operands only have positive
	values. But to avoid this warning, we can change the type of the right operand to a signed
	integer:

			i < (int) sizeof(a) / sizeof(a[0])

	Can be wise to define this in a macro.
*/


//	Program that prints a table of compound interest

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int interest(void)
{
	int i, low_rate, num_years, year;
	double value[5];

	printf("Enter interest rate: ");
	scanf_s("%d", &low_rate);
	printf("Enter number of years: ");
	scanf_s("%d", &num_years);

	printf("\nYears");
	for (i = 0; i < NUM_RATES; i++) {
		printf("%6d%%", low_rate + i);
		value[i] = INITIAL_BALANCE;
	}
	printf("\n");

	for (year = 1; year <= num_years; year++) {
		printf("%3d    ", year);
		for (i = 0; i < NUM_RATES; i++) {
			value[i] += (low_rate + i) / 100.0 * value[i];
			printf("%7.2f", value[i]);
		}
		printf("\n");
	}

	return 0;
}

/*
	An array can have any number of dimensions. For example, the following declaration creates
	a two-dimensional array (a matrix):

			int m[5][9];

	This array has 5 rows and 9 columns. Both columns are indexed from 0.

	C stores arrays in row-major order (google it), with row 0 first, then row 1, and so forth.
	We can write an identity matrix:

			#define N 10

			double indent [N][N];
			int row, col;

			for (row=0; row < N; row++)
				for (col = 0; col < N; col++)
					if (row == col)
						indent[row][col] = 1.0;
					else
						indent[row][col] = 0.0;

	Multidimensional arrays play a lesser role in C than in other programming languages,
	primarily because C provides a more flexible way to store multidimensional data: array
	of pointers.

	We can create an initializer for a two-dimensional array by nesting one-dimensional
	initializers:

			int m[5][9] = { {1, 1, 1, 1, 1, 0, 1, 1, 1},
							{0, 1, 0, 1, 0, 1, 0, 1, 0},
							{0, 1, 0, 1, 1, 0, 0, 1, 0},
							{1, 1, 0, 1, 0, 0, 0, 1, 0},
							{1, 1, 0, 1, 0, 0, 1, 1, 1} };

	Initializers for higher-dimensional arrays are constructed in a similar fashion.

	C provides a variety of ways to abbreviate initializers for multidimensional arrays:

		If an initializer isn't large enough to fill the array, the remaining elements are
		given the value 0.

		If an inner list in the initializer isn't long enough to fill a row, the remaining
		elements are initialized to 0.

		We can omit inner braces. Once the compiler fills a row, it begins filling the next.

	Designated initializers also work with multidimensional arrays. For example, we can create
	the 2 dimensional identity matrix as follows:

			double ident[2][2] = {[0][0] = 1.0, [1][1] = 1.0};


	Any array, can be made constant by starting its declaration with the word const:

			const char hex_chars[] =
				{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
				 'A', 'B', 'C', 'D', 'E', 'F'};


	An array that has been declared const should not be modified (the compiler will detect
	direct attempts to modify).

	This documents that the program won't change the array.

	Const isn't limited to arrays; it works with any variable.
*/


// Program that deals a random hand of cards
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int deal(void)
{
	bool in_hand[NUM_SUITS][NUM_RANKS] = { false };
	int num_cards, rank, suit;
	const char rank_code[] = { '2','3','4','5','6','7','8','9','t','j','q','k','a' };
	const char suit_code[] = { 'c','d','h','s' };

	srand((unsigned)time(NULL));

	printf("Enter number of cards in hand: ");
	scanf_s("%d", &num_cards);

	printf("Your hand:");
	while (num_cards > 0) {
		suit = rand() % NUM_SUITS;		// picks random suit
		rank = rand() % NUM_RANKS;		// picks random rank
		if (!in_hand[suit][rank]) {
			in_hand[suit][rank] = true;
			num_cards--;
			printf(" %c%c", rank_code[rank], suit_code[suit]);
		}
	}
	printf("\n");

	return 0;
}


/*
	When declaring an array, it's possible to use an expression that's not constant, but not
	with my current compiler :/. This is called variable-length arrays (VLA). This means that
	the length of the VLA is computed when the program is executed, not when compiled. The
	restrictions on VLAs is that they can't have static storage duration or be initialized.
*/
