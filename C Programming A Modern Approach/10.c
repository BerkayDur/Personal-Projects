#include <stdio.h>

/*
	A variable declared in the body of a function is said to be local to the function. By
	default, local variables have the following properties:

		Automatic Storage Duration. The storage duration of a variable is the portion of the
		program execution during which storage for the variable exists. Storage for a local
		is automatically allocated when the enclosing function is called and deallocated when
		the function returns. A local variable doesn't retain its value when the enclosing
		function returns, so the value could be different when the function is recalled.

		Block Scope. The scope of a variable is the portion of the program text in which the
		variable can be referenced. A local variable has block scope; it is visible from its
		point of declaration to the end of the enclosing function body. So, other functions
		can use the same name for other purposes.


	Static Local Variables are ones which have static in its declaration, causing it to have
	a static storage duration instead an automatic storage duration. A static variable has
	a permanent storage location, so it retains its value throughout the execution of the
	program. Consider the following function:

		void f(void)
		{
			static int i ;	## Static Local Variable ###
			...
		}

	Since the local variable i has been declared static, it occupies the same memory location
	throughout the execution of the program. When f returns, i won't lose its value.

	A static variable still has block scope, so it's not visible to other functions. So, a
	static variable is a way to hide data from other functions but retain its value for
	future calls of the same function.


	Parameters have the same properties - automatic storage duration and block scope - as local
	variables. The only difference is that each parameter is initialized automatically when a
	function is called.


	External variables can be used by functions to communicate. These are variables that are
	declared outside the body of any function.

	The properties of external variables (or global variables) are different from those local
	variables:

		Static Storage Duration. External variables have static storage duration, just like
		local variables that have been declared static.

		File Scope. An external variable has a file scope: it is visible from its point of
		declaration to the end of the enclosing function. This means global variables can be
		accessed and modified by all functions that follow its declaration.


	Example: Using External Variables to Implement a Stack:

		A stack is a data structure (Stacks are abstract concepts, not a C feature). A stack
		A stack, like an array, can store multiple data items of the same type. However,
		the operations on a stack are limited: we can either push an item onto the stack (add
		it to one end - the stack top) or pop it from the stack (remove it from the same end).
		Examining or modifying an item that's not at the top of the stack is forbidden.

		One way to implement a stack in c is to store the items in an array, we'll call it
		contents. A separate integer variable named top marks the position of the stack top.
		When the stack is empty, the top has value 0. To push an item on the stack, we store
		the item in contents at the position indicated by top, the increment top. Popping an
		item requires decrementing top, then using it as an index into contents to fetch the
		item that's being popped.

		Here's part of the program:
*/

/*
#include <stdbool.h>

#define STACK_SIZE 100

// External variables
int contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(int i)
{
	if (is_full()) {
		stack_overflow();
	}
	else {
		contents[top++] = i;
	}
}

int pop(void)
{
	if (is_empty()) {
		stack_underflow();
	}
	else {
		return contents[--top];
	}
}
*/

/*
	Pros and Cons of External Variables:

		Global variables are convenient for functions communicating. In most cases, however,
		it's better for functions to communicate through parameters rather than by sharing
		variables. Here's why

			If we change an external variable during program maintenance, we'll need to see
			how it affects every function.

			If a global variable is assigned an incorrect value, it may be difficult to
			identify the function causing this problem.

			Functions that rely on external variables are hard to reuse in other programs.
			As a function that relies on a global variable isn't self-contained.
*/


//	Program that asks the user to guess a hidden number

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

// External variable
int secret_number;

// Prototypes
void initialize_number_generator(void);
void choose_new_secret_number(void);
void read_guesses(void);

int guess(void)
{
	char command;

	printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);
	initialize_number_generator();
	do {
		choose_new_secret_number();
		printf("A new number has been chosen.\n");
		read_guesses();
		printf("Play again? (Y/N) ");
		scanf_s(" %c", &command);
		printf("\n");
	} while (command == 'Y' || command == 'y');

	return 0;
}

/*
	initialize_number_generator: Initializes the random number generator using the time of day.
*/

void initialize_number_generator(void)
{
	srand((unsigned)time(NULL));
}

/*
	choose_new_secret_number: Randomly selects a number between 1 and MAX_NUMBER and stores it
							  in secret_number.
*/

void choose_new_secret_number(void)
{
	secret_number = rand() % MAX_NUMBER + 1;
}

/*
	read_guesses: Repeatedly reads the user guesses and tells the user whether each guesses too
				  low, too high, or correct. When the guess is correct, prints the total of
				  guesses and returns.
*/

void read_guesses(void)
{
	int guess, num_guesses = 0;

	for (;;) {
		num_guesses++;
		printf("Enter guess: ");
		scanf_s("%d", &guess);
		if (guess == secret_number) {
			printf("You won in %d guesses!\n\n", num_guesses);
			return;
		}
		else if (guess < secret_number) {
			printf("Too low; try again.\n");
		}
		else {
			printf("Too high; try again.\n");
		}
	}
}


/*
	This program is good but it relies on an external variable. So here's a version that
	doesn't rely on an external variable.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER2 100



// Prototypes
void initialize_number_generator2(void);
int new_secret_number(void);
void read_guesses2(int secret_number2);

int guess2(void)
{
	char command;
	int secret_number2;

	printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER2);
	initialize_number_generator2();
	do {
		secret_number2 = new_secret_number();
		printf("A new number has been chosen.\n");
		read_guesses2(secret_number2);
		printf("Play again? (Y/N) ");
		scanf_s(" %c", &command);
		printf("\n");
	} while (command == 'Y' || command == 'y');

	return 0;
}

/*
	initialize_number_generator: Initializes the random number generator using the time of day.
*/

void initialize_number_generator2(void)
{
	srand((unsigned)time(NULL));
}

/*
	new_secret_number: Randomly selects a number between 1 and MAX_NUMBER2.
*/

int new_secret_number(void)
{
	return rand() % MAX_NUMBER2 + 1;
}

/*
	read_guesses: Repeatedly reads the user guesses and tells the user whether each guessis too
				  low, too high, or correct. When the guess is correct, prints the total of
				  guesses and returns.
*/

void read_guesses2(int secret_number2)
{
	int guess, num_guesses = 0;

	for (;;) {
		num_guesses++;
		printf("Enter guess: ");
		scanf_s("%d", &guess);
		if (guess == secret_number2) {
			printf("You won in %d guesses!\n\n", num_guesses);
			return;
		}
		else if (guess < secret_number2) {
			printf("Too low; try again.\n");
		}
		else {
			printf("Too high; try again.\n");
		}
	}
}

/*
	A block is a compound statement of the form:

		{ declarations statements }

	e.g.
		if (i > j) {
			int temp = i;
			i = j;
			j = temp;
		}


	By default, the storage duration of a variable declared in a block is automatic: storage
	for the variable is allocated when the block is entered and deallocated when the block is
	exited. The variable has block scope; it can't be referenced outside the block. A variable
	that belongs to a block can be declared static to give it static storage duration.

	The body of a function is a block. Blocks in a function body are useful when we need
	variables for temporary use. Putting temporary variables inside blocks has 2 advantages:

		1)	It avoids cluttering the declarations at the beginning of the function body with
			variables that are only used briefly.

		2)	It reduces name conflicts.

	c99 allows variables to be declared anywhere within a block, just as variables can be
	declared anywhere within a function.



	In c, the same identifiers may have several different meanings. C's scope rules enable the
	programmer (and the compiler) to determine which meaning is relevant at a give point in
	the program.
	The most important scope rule is:

		When a declaration inside a block names an identifier that's already visible, the new
		declaration temporarily "hides" the old one, and the identifier takes on a new meaning.
		At the end of the block, the identifier regains its old meaning.
*/

/*
	It's best to order a c program in this way:

		#include directives
		#define directives
		Type definitions
		Declarations of external variables
		Prototypes for functions other than main
		Definition of main
		Definitions of other functions
*/


// Program that classifies a poker hand

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
bool straight, flush, four, three;
int pairs;	// can be 0, 1, or 2

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

int poker(void)
{
	for (;;) {
		read_cards();
		analyze_hand();
		print_result();
	}
}


/*
	read_cards: Read the cards into the external variables num_in_rank and num_in_suit;
				checks for bad cards and duplicate cards.
*/

void read_cards(void)
{
	bool card_exists[NUM_RANKS][NUM_SUITS];
	char ch, rank_ch, suit_ch;
	int rank, suit;
	bool bad_card;
	int cards_read = 0;

	for (rank = 0; rank < NUM_RANKS; rank++) {
		num_in_rank[rank] = 0;
		for (suit = 0; suit < NUM_SUITS; suit++) {
			card_exists[rank][suit] = false;
		}
	}

	for (suit = 0; suit < NUM_SUITS; suit++) {
		num_in_suit[suit] = 0;
	}

	while (cards_read < NUM_CARDS) {
		bad_card = false;

		printf("Enter a card: ");

		rank_ch = getchar();
		switch (rank_ch)
		{
		case '0':			exit(EXIT_SUCCESS);
		case '2':			rank = 0; break;
		case '3':			rank = 1; break;
		case '4':			rank = 2; break;
		case '5':			rank = 3; break;
		case '6':			rank = 4; break;
		case '7':			rank = 5; break;
		case '8':			rank = 6; break;
		case '9':			rank = 7; break;
		case 't':case 'T':	rank = 8; break;
		case 'j':case 'J':	rank = 9; break;
		case 'q':case 'Q':	rank = 10; break;
		case 'k':case 'K':	rank = 11; break;
		case 'a':case 'A':	rank = 12; break;
		default:			bad_card = true;
		}

		suit_ch = getchar();
		switch (suit_ch)
		{
		case 'c':case 'C':	suit = 0; break;
		case 'd':case 'D':	suit = 1; break;
		case 'h':case 'H':	suit = 2; break;
		case 's':case 'S':	suit = 3; break;
		default:			bad_card = true;
		}

		while ((ch = getchar()) != '\n') {
			if (ch != ' ') {
				bad_card = true;
			}
		}

		if (bad_card) {
			printf("Bad card; ignored.\n");
		}
		else if (card_exists[rank][suit]) {
			printf("Duplicate card; ignored.\n");
		}
		else {
			num_in_rank[rank]++;
			num_in_suit[suit]++;
			card_exists[rank][suit] = true;
			cards_read++;
		}
	}
}

/*
	analyse_hand: Determine whether the hand contains a straight, a flush, four-of-a-kind,
				  and/or three-of-a-kind; determines the number of pairs; stores the result
				  into the external variables straight, flush, four, three, and pairs.
*/

void analyze_hand(void)
{
	int num_consec = 0;
	int rank, suit;

	straight = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;

	//check for flush
	for (suit = 0; suit < NUM_SUITS; suit++) {
		if (num_in_suit[suit] == NUM_CARDS) {
			flush = true;
		}
	}

	//check for straight
	rank = 0;
	while (num_in_rank[rank] == 0) {
		rank++;
	}
	for (; rank < NUM_RANKS && num_in_rank[rank]>0; rank++) {
		num_consec++;
	}
	if (num_consec == NUM_CARDS) {
		straight = true;
		return;
	}

	// checks for 4-of-a-kind, 3-of-a-kind, and pairs
	for (rank = 0; rank < NUM_RANKS; rank++) {
		if (num_in_rank[rank] == 4) {
			four = true;
		}
		if (num_in_rank[rank] == 3) {
			three = true;
		}
		if (num_in_rank[rank] == 2) {
			pairs++;
		}

	}
}

/*
	print_result: Prints the classification of the hand, based on the values of the external
				  variable straight, flush, four, three, and pairs.
*/


void print_result(void)
{
	if (straight && flush) {
		printf("Straight flush");
	}
	else if (four) {
		printf("Four of a kind");
	}
	else if (three && pairs == 1) {
		printf("Full house");
	}
	else if (flush) {
		printf("Flush");
	}
	else if (straight) {
		printf("straight");
	}
	else if (three) {
		printf("Three of a kind");
	}
	else if (pairs == 2) {
		printf("Two pairs");
	}
	else if (pairs == 1) {
		printf("Pair");
	}
	else {
		printf("High card");
	}
	printf("\n\n");
}
