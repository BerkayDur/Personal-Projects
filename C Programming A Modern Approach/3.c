#include <stdio.h>

/*
	printf is designed to display the contents of a string, known as a format string.
	it looks like this:
		printf(string, expr1, expr2, ...);

	theres no limit to the number of values that can be printed by a call of printf

	the format string can contain ordinary characters and conversion specifications
	(these being with %). This is just a placeholder representing a value.

	the info that follows the % specifies how the value is converted from binary
	to characters.
	e.g.
		%d specifies that printf is to convert an int value from binary to a string
		of decimal digits.

	ordinary charatcers are simply copied to the output line

	conversion specifications have the general form:
		%m.pX

			The minimum field width, m, specifies the minimum number of
			characters to print.
			as the value is right-justified, it m is greater than the value,
			this means blank space is added to the left of the value.
			putting a -m, makes it left-justified.

	These are the most common conversion specifier for number:
		d - displays an integer in decimal (base 10) form. In this case, p
			is the number of digits to display (basically adds 0 to left)

		e - displays a floating-point number in exponential form. p indicates
			how many digits should appear after the decimal point, default
			is 6, and if p=0, this shows no decimal point.

		f - displays a floating-point number in fixed decimal form, without
			an exponent. p is number of decimals after decimal point.

		g - displays a floating-point number in either exponential form or fixed
			decimal form, depending on the numbers size. p is the max number of
			significant digits. unlike f, g doesn't show trailing 0's. if there
			are no digits after the decimal point, g doesn't display the point
*/


//prints int and float values in various forms

int tprintf(void)
{
	int i;
	float x;
	i = 40;
	x = 839.21f;
	printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
	printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);
	return 0;
}


/*
	escape sequences enable strings to contain characters that would otherwise cause
	problems in the compiler. (standard ones i already know)
*/




/*
	scanf reads input according to a particular format. A scanf format string may
	contain both ordinary characters and conversion specifications. The conversions
	with scanf are essentially the same as those used with printf.
	& is used to create a pointer to a variable.

	scanf works by matching groups of input characters with conversion specifications.

	When scanf searches for the beginning of a number, it ignores white-space
	characters.

	scanf matches characters in the format string with the input, and skips over
	whitespace if needed. if the value doens't match, it is put back to be read by the
	next call of scanf

*/


//Adds 2 fractions
int addfrac(void)
{
	int num1, denom1, num2, denom2, result_num, result_denom;

	printf("Enter first fraction: ");
	scanf_s("%d/%d", &num1, &denom1);

	printf("Enter second fraction: ");
	scanf_s("%d/%d", &num2, &denom2);

	result_num = num1 * denom2 + num2 * denom1;
	result_denom = denom1 * denom2;
	printf("The sum is %d/%d\n", result_num, result_denom);

	return 0;
}

/*
	print % by adding %% in format string
*/
