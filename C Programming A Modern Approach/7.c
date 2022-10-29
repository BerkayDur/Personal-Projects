
#include <stdio.h>

/*
	Basic types are ones which are built in.

	Integers types are ones which are whole numbers.
	Integers can be divided into 2 categories, signed and unsigned.
	In binary, the leftmost bit of a signed integer (the sign bit) is 0 if the number is
	positive or zero, 1 if negative. Unsigned integers have no sign bit.

	In c, the integer variable are signed, unless declared otherwise.

	In c, the integer types come in different sizes. Usually int is 32 bits. There is also long
	integers, and short integers (used to save memory).

	Combining all these, there are six combinations that provide different types:

		short int				<=>		short
		unsigned short int		<=>		unsigned short

		int
		unsigned int

		long int				<=>		long
		unsigned long int		<=>		unsigned long

	We can shorten this by simply not writing int when using long or short.


	on 16-bit systems, short and int have the same range.
	on 32-bit systems, int and long have the same range.

	c99 added in (unsigned) long long int. They're both required to be at least 64-bits wide.


	Constants in c are ones which appear in the text of a program (not read, written,
	or computed). They can be written in decimal, octal, or hexadecimal.
	e.g.
		Decimal constants (0 - 9), mustn't begin with 0:
			15	255	 32767

		Octal constants (0 - 7), must begin with 0:
			017  0377  077777

		Hexadecimal constants (0 - 9 & a - f), must begin with 0x:
			0xf  0xff  0x7fff  0xfF  0xFF  0XFF ....

	A decimal integer constant is normally of type int. However, if too large to store as int,
	the compiler changes its type to long int, but if again to large, then type unsigned long.

	for octal and hexadecimal, the compiler goes through types: int, unsigned int, long int, and
	unsigned long int, until it finds a capable one.

	To force a compiler to keep a constant as long int, add an l:
		15L  0377L  0x7fffl

	likewise for unsigned, but with a U:
		15U  0377u 0x7fffU

	or both:
		15Ul  0377lu  0x7fffLu


	use LL for long long int.


	Integer overflow can occur, if the result is too large to be presented.


	When reading and writing, %d conversion only works for type int.
	So:

			%d		for signed int in decimal
			%u		for unsigned int in decimal
			%o		for unsigned int in octal
			%x		for unsigned int in hexadecimal

	We add h in front for short.
	e.g.
		short s;

		scanf("%hd", &s);
		printf("%hd", s);

	we add L in front for long.
	e.g.
		long y;

		scanf("%Ld", &y);
		printf("%ld", y);

	we add LL in front for long long.
	e.g.
		long long e;

		scanf("%lld", &e);
		printf("%LLd", e);
*/


// Program that sums a series of numbers (using long variables)

int sum2(void)
{
	long n, sum = 0;

	printf("This program sums a series of integers.\n");
	printf("Enter integers (0 to terminate): ");

	scanf_s("%ld", &n);
	while (n != 0) {
		sum += n;
		scanf_s("%ld", &n);
	}
	printf("The sum is: %ld\n", sum);

	return 0;
}


/*
	Floating point number are ones which can support digits after the decimal point.
	There are 3 floating types:
			float			Single-precision floating-point
			double			Double-precision floating-point
			long double		Extended-precision floating point

	Floating types also include complex types (search these if needed)


	Floating constants must contain a decimal point and/or an exponent (uses e). By default,
	floating constants are stored as double-precision numbers. This causes no problem since
	double values are automatically to float when necessary.

	To force the compiler store a floating constant in float, add F at the end of the constant.
	For long double, add L at the end of the constant.

	The conversion specification for reading and writing single-precision floating-point numbers
	are: %e, %f, and %g. To make it double, add l in front. This works for scanf, but not for
	printf as e, f, and g conversion can be used for either float or doubles.
	e.g.
		double d;
		scanf("%lf", &d);

	When reading or writing a value of type long double, put l in front of the e, f, or g.
	e.g.
		long double d;
		scanf("%lf", &d);
		printf("%lf", d);


	The only basic type remaining is char, the character type.
	A variable of type char can be assigned to any single character:
		char ch;

		ch = 'a';
		ch = 'A';
		ch = '0';
		ch = ' ';

	These have to be enclosed in single quotes.


	Character operations are very easy as c treats them as small integers.
	When a character appears in computation, c simply uses integer values.
	C uses the ASCII character set.
	e.g.
		char ch;
		int i;

		i = 'a';		# i is now 97
		ch = 65;		# ch is now 'A'
		ch = ch + 1;	# ch is now 'B'
		ch++;			# ch is now 'C'

	Characters can be compared as they're represented using integers, so they have the same
	properties as numbers.

	There exists signed and unsigned char, which have values between -128 and 127 and between
	0 and 255, respectively. It isn't specified whether the ordinary char is signed or unsigned.

	C99 has this hierarchy for arithmetic types:

		Integer types

			char

			signed integer types, both standard (signed char, short int, int, long int,
			long long int) and extended.

			Unsigned integer types, both standard (unsigned char, unsigned short int,
			unsigned int, unsigned long int, unsigned long long int, _Bool) and extended.

			Enumerated types


		Floating types

			Real floating types (float, double, long double)

			Complex types (float_complex, double_complex, long double_complex)



	Character constants is usually one character enclosed in single quotes, but this
	isn't the case with escape sequence, which are used to display characters, which can't
	be entered from a keyboard. There are 2 kinds of escape sequences: Character escapes and
	Numeric escapes.
	Below are the character escapes:

		Alert (bell)		\a
		Backspace			\b
		Form feed			\f
		New line			\n
		Carriage return		\r
		Horizontal tab		\t
		Vertical tab		\v
		Backslash			\\
		Question mark		\?
		Single quote		\'
		Double quote		\"

	The problem with character escapes, is that they don't include non-printing ASCII Characters
	beyond the 128 ASCII characters. The solution to this is Numeric escapes, as they can
	represent any character. Numeric escape sequences are written in octal or hexadecimal and
	they look like this:
		The octal escape sequence is a \ followed by an octal number with at most 3 digits

		THe hexadecimal escape sequence is a \x followed by a hexadecimal number.

	It is wise to use #define to give escape sequences names. And it is possible to use
	escape sequences in strings as well.


	We can convert lower-case letters to upper-case, by using characters. A better way to do
	this is by using toupper in the c library:

	ch = toupper(ch);	## This converts ch to upper-case ##

	To use this, we have to include the directive:

	#include <ctype.h>


	To read and write Characters, we can use the conversion specification %c (this can only
	read one character).


	We can read and write single characters using getchar and putchar.
	putchar writes a single character:

	putchar(ch);

	When getchar is called, it reads one character, which it returns. In order to save it, we
	must assign it to a variable:

	ch = getchar();

	getchar actually returns an integer rather than a char value. Like scanf, getchar doesn't skip
	white-space characters as it reads.

	getchar and putchar are much faster than scanf and printf.

	We can skip the rest of an input line by using:

	while (getchar() != '\n')
		...

	The next program skips all blank characters before the first non-blank encountered:

	while ((ch = getchar()) == ' ')
		...


	##### When using getchar and scanf, we can have the problem that scanf leaves behind unread
	characters (like new-line). getchar will return the first of the leftover characters.
*/


// Program determines the length of a message

int length(void)
{
	char ch;
	int len = 0;

	printf("Enter a message: ");
	ch = getchar();
	while (ch != '\n') {
		len++;
		ch = getchar();
	}
	printf("Your message was %d character(s) long.\n", len);

	return 0;
}


// Program determines the length of a message

int length2(void) {
	int len = 0;

	printf("Enter a message: ");
	while (getchar() != '\n') {
		len++;
	}
	printf("Your message was %d character(s) long.\n", len);

	return 0;
}

/*
	Computers can only do arithmetic using numbers of the same size (same number of bits), but in
	c we can combine different basic types into the same expression. The compiler then has to
	generate instructions to convert some operands to different types so the hardware will
	be able to evaluate the expression. This is known as implicit conversions. We can also
	perform explicit conversions, using the cast operator.Implicit conversions are performed
	in the following situations:

			When the operands in an arithmetic or logical expression don't have the same type
			(c performs the usual arithmetic conversions)

			When the type of expression on the right of an assignment doesn't match the type
			of the variable of the left

			When the type of an argument in a function call doesn't match the type of the
			corresponding parameter.

			When the type of the expression in a return statement doesn't match the
			function's return type



	Usual arithmetic conversions are applied to the operands of most binary operators, including
	arithmetic, relational, and equality operators. Promotion is known as converting the type
	of an operand to match type of the other operand. We can divide the rules for performing
	the usual arithmetic conversions into 2 cases (to promote the operand whose type is
	narrower, meaning it stores fewer bytes):

		The type of either operand is a floating type. Use:

						long double
							 ^
						   double
							 ^
						   float


		Neither operand is a floating type. First perform integral promotion, then Use:

						unsigned long int
						        ^
							 long int
							    ^
						   unsigned int
						        ^
							   int

			A special case with this is where long int and unsigned int have the same length.
			Then, both are converted to unsigned long int.


	When one operand is a floating type, and the other isn't, upcasting happens. This is where
	the other operands type gets converted to float as if the converse happened, we would lose
	precision.


	Don't use unsigned and signed types, as the compiler converts the signed to unsigned by
	adding n + 1 (where n is the largest representable value of the unsigned type).
	(AIDS AF).


	The usual arithmetic conversion don't apply to assignment. In c, the right side of
	assignment is converted to the declared type of the variable. This works fine if the
	variable type is at least as "wide" as the expression. If not, we will get a less
	precision.
	e.g.
		int i;

		i = 842.97;		## i is now 842 ##


	c99, has rules for implicit conversions. For integer type, the ranks are (ignoring enumerated
	and extended integer types):
		1.	long long int, unsigned long long int
		2.	long int, unsigned long int
		3.	int unsigned int
		4.	short int, unsigned short int
		5.	char, signed char, unsigned char
		6.	_Bool

	the rules in c99, for performing usual arithmetic conversions are divided into 2 cases:

		The type of either operand is a floating type. As long as neither operand has a complex
		type, the rules are the same as before.

		Neither operand type is a floating type. First perform integer promotion on both
		operands If the type of the two operands are now the same, the process end. Otherwise,
		use the following rules, stopping at the one that applies best:

			If both operands have signed types or both have unsigned types, convert the operand
			whose type has lesser integer conversion rank to the types of of the operand with
			greater rank.

			If the unsigned operand has rank greater or equal to the rank of the type of the
			signed operand, convert the signed operand to the type of the unsigned operand.

			If the type of the signed operand can represent all of the type of the unsigned
			operand, convert the unsigned operand to the type of the signed operand.

			Otherwise, convert both operands to the unsigned type corresponding to the type
			of the signed operand.


	If we want a greater degree of control over the type conversion, we can use cast.
	The cast expression has the form:

				( type-name ) expression

	Type-name specifies the types to which the expression should be converted.
	e.g.
		float f, frac_part;

		frac_part = f - ( int ) f;

	Cast expressions are considered unary operators.

	Sometimes casts are necessary to avoid overflow.
	e.g.
		long i;
		int j = 1000;

		i = j * j;		## Overflow may occur ##

	This looks fine but when multiplying operands which are of type int, the result is int.
	So j * j, may be too large to be an int, causing overflow. We can use cast to avoid
	this problem:

		i = (long) j * j;


	We can use type definitions are used just like the #define directive to create a macro.
	e.g.

			typedef int Bool;

	It is a	c convention to capitalise the name give. Using type definitions to define Bool,
	causes the compiler to add Bool to the list of type names that it recognizes. Now,
	Bool can be used to in the same way as the built-in type names - in variable declarations,
	cast expressions, and elsewhere.
	For example, we can use Bool to declare variables:
					Bool flag; ## same as int flag ##

	The advantages of type definitions are that they can make a program more understandable.
	e.g.

		typedef float Dollars;

		Dollars cash_in, cash_out;

	Type definitions make it easier to modify a program. So, if we decide that Dollars should
	be defined as double, all we need to do is change the type definition:

		typedef double Dollars;

	This means, that declarations of Dollars variables need not to be changed.

	So, Type Definitions make programs more portable as different computers have different
	ranges for a type.


	We can determine how much memory is required to store variables of a particular type. This
	is the sizeof operator:

		sizeof ( type-name )

	To print this, we can print this by simply use z in the conversion specification, followed by
	one of the usual integer code (typically u):

		printf("Size of int: %zu\n", sizeof(int));
*/
