#include <stdio.h>		// includes information about C's standard i/o library.

int pun(void)
{
	printf("To C, or not to C: that is the question.\n");
	return 0;		//returns 0 when the program terminates
}


/*
	converting from c to machine code goes like this:

		Preprocessing.	The program is first given to a preprocessor, which obeys commands that
						begin with # (known as directives). A preprocessor is like an editor,
						it can add things to the program and make modifications

		Compiling.		the program now goes through a compiler, which translates it to machine
						code instructions (object code).

		Linking.		a linker combines the object code produced by the compiler with any
						additional code needed to yield a complete executable program. This
						additional code includes library functions (like printf)
*/


/*
c programs have the general form

	directives

	int main(void)
	{
		statements
	}
*/


/*
	compilers ignore comments.
*/

int variables(void)
{
/*
	variables are a way to store data temporary during program execution.

	every variable has a type, which specifies the data type it holds.

	Variables must be declared before use (this is for the compiler).
	e.g.
		type name;
*/
	int height, length, width, volume;
	float profit, loss;
/*
	variables can be given a value by assignment. (but must be delcared before assignment)
*/
	profit = 2150.48f;
	height = 8;
	length = 12;
/*
	the f is added to a constant because it is type float

	printing a variable is done by replacing a placeholder %....
					%d for int
					%f for float
*/
	printf("Profit: %f\n", profit);
/*
	precision. %a.bf
		a is whitespace to the left of dp.
		b is how many decimal places.
*/
	printf("Profit: %100.2f\n", profit);
	printf("Height: %d \t Length: %d \n", height, length);
	return 0;
}

int dweight_1(void)
{
	int height, length, width, volume, weight;
	height = 8;
	length = 12;
	width = 10;
	volume = height * length * width;
	weight = (volume + 165) / 166;

	printf("Dimensions: %dx%dx%d\n", length, width, height);
	printf("Volume (Cubic Inches): %d\n", volume);
	printf("Dimensional weight (pounds): %d\n", weight);
	return 0;
}


/*
	an uninitialized variable is one which hasn't been assigned a value by the program.
	Attempting to access this variable may yield a random value or a crash.
	this can be avoided by assigning a value before use.
*/

int dweight_2(void)
{
	int height = 8, length = 12, width = 10;


/*
	you can assign and declare a variable on the same line.
	for height, 8 is said to be the initializer
*/

	printf("%d\n", height * length * width);

/*
	can print volume, without having to assign a variable to the value (just need an expression)
*/

	return 0;
}


/*
	scanf can read inputs.
	printf and scanf require the use of a formatted string.

	scanf needs to know the data type of the input,
	e.g.
		scanf("%f",&x);

		this means scanf takes a float as input and stores it in variable x
*/

int dweight2(void)
{
	int height, length, width, volume, weight;
	printf("Enter height of box: ");
	scanf_s("%d", &height);
	printf("Enter length of box: ");
	scanf_s("%d", &length);
	printf("Enter width of box: ");
	scanf_s("%d", &width);
	volume = height * length * width;
	weight = (volume + 165) / 166;
	printf("Volume (cubic inches): %d\n", volume);
	printf("Dimensional weight (pounds): %d\n", weight);
	return 0;
}


/*
	the problem with tihs porgram is that it doesnt work correctly if the input is non-numeric
*/


/*
	its good practise to define constants so they can be changed if needed.
	this can be done using macro definition
	e.g.
		#define MACRO-NAME value

	this is a preprocessing directive. so when the program is compiled, the preprocessor
	replaces each macro by the value it represents.

	if the value is an expression with operators, it should be enclosed by brackets
*/



// following program converts fahrenheit to celsius

#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f/9.0f)
int celsius(void)
{
	float fahrenheit, celsius;
	printf("Enter Fahrenheit temperature: ");
	scanf_s("%f", &fahrenheit);
	celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;	/*	compiler sees this as:
																celsius=(fahrenheit-32.0f)*(5.0f/9.0f);
															*/
	printf("Celsius equivalent: %.1f\n", celsius);
	return 0;
}

/*
	SCALE_FACTOR is defined to be (5.0f/9.0f) instead of (5/9) as c will truncate the result in integer
	division, so (5/9) would be 0
*/


/*
	names for variables, functions, macros, and other entities are called identifiers.
	Identifiers have a certain format.
	e.g.
		they may contain letters, digits, and underscore, but must begin with a letter or underscore.


	there are keywords which cannot be identifiers
*/

/*
	A token is groups of characters that can't be split up without changing their meaning.

	each preprocessing directive requires its own line

	statements can be divided over many lines

	space between tokens is allowed and reccomended

	Indentation is used for nesting

	blank lines can divide a program into logical units

	can't put a new-line character in a string
*/
