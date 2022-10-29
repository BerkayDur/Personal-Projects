#include <stdio.h>

/*
	some operators in c include:
		Arithmetic Operators - (+-/*)

		Relational operators - comparisons such as "i > 0"

		Logical Operators - (and, or, not) such as (i>0 and i<10)
*/

/*
	There are 7 Arithmetic operators in c.
	Binary operators require two operands, and they can be split into 2 group:
		Additive -		+ addition
						- subtraction

		Multiplicative -		* multiplication
								/ division
								% remainder

	Unary operators only require one operand, and there are only 2:
				+ unary plus
				- unary minus

	e.g.
		i= +1;

	All binary operators (except %) allows for the use of both int and float (or both).

	Both / and % require special care:
		with /, if both operands are int, the operator truncates by dropping the fractional
		part of the result

		% only allows int, if both operands aren't int, the program doesn't compile

		using 0 as the right operand in either (/ or %), isn't possible

		when using negatives, the value truncates towards 0 with integer division.


	Some software will dictate the value, -9/7 may be -1 or -2, this is called
	Implementation-Defined error.


	Operator precidence:
		Highest: + - (unary)
				 * / %
		Lowest:  + - (binary)

	if two or more operators are on the same level of precedence, associativity of the
	operators takes place.

	Binary is left associative.
	e.g.
		i - j - k <=> (i - j) - k
		i * j / k <=> (i * j) / k

	Unary is right associative.
	e.g.
		- + i <=> - (+i)
*/


// Computes a Universal product code check digit

int upc(void)
{
	int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
		first_sum, second_sum, total;

	printf("Enter the first (single) digit: ");
	scanf_s("%1d", &d);
	printf("Enter first group of 5 digits: ");
	scanf_s("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
	printf("Enter second group of five digits: ");
	scanf_s("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

	first_sum = d + i2 + i4 + j1 + j3 + j5;
	second_sum = i1 + i3 + i5 + j2 + j4;
	total = 3 * first_sum + second_sum;

	printf("Check digit: %d\n", 9 - ((total - 1) % 10));
	return 0;
}


/*
	When we want to use something for later, we use an Assignment Operator to assign variables
	to values.

	Simple Assignment - the operator (=). v = e is to evaluate the expression e and copy its value
						into v. e can be a constant, variable, or a more complicated expression.

						If v and e don't have the same type, then the value of e is converted to the
						type of v as the assignment takes place

						since assignment is an operator, several assignments can be chained together.
						i = j = k = 0; <=> i = (j = (k = 0));
						This is as = is right associative

	The assignment operator requires an lvalue as its left operand. An lvalue represents an object
	stored in computer memory. Variable are lvalues (but there are more).
	e.g.
		12 = i;		### WRONG ###
		i + j = 0;	### WRONG ###
		-i = j;		### WRONG ###

	Compound Assignment - Assignments that reuse the old value of a variable to compute the new value.
						  Can use any of the binary operators with this (+-/*%).
						  e.g.
							  i += 2;  ### is the same as  i = i + 2; ###

						  This also works:
						  i += j += k; <=> i += (j += k);

	Increment and Decrement Operators are important and very common.
	This can be done by using:
		i = i + 1; <=> i += 1;
		i = j - 1; <=> j -= 1;

		i++		increments i after being used (so, printing this will print i)
		++i		increments i before being used (so, printing this will print i+1)

		i--		decrements i after being used (so, printing this will print i)
		--i		decrements i before being used (so, printing this will print i-1)

		postfix have higher precedence than unary plus/minus.
		prefix have same precedence as unary plus/minus.


		With the rules of operator precedence and associativity, we can break any expression into
		sub-expressions. C doesn't define the order in which sub-expressions are evaluated.
		This can cause problems,
		e.g.
			a = 5;
			c = (b = a + 2) - (a = 1);

			depending on the compiler, we may get 6 or 2.

			i = 2;
			j = i * i++;

			depending on the compiler, we may get 4 or 6.

		So avoid accessing a variable and modifying it in the same expression.
		These cause what is called an Undefined Behaviour (basically defcon 5).


		In C, we can use any expression as a statement by appending it with a semicolon.
		e.g.
			++i;	When the statement is executed, i is incremented, then the new value of i is
					fetched, however since it's not part of a larger expression, the value is
					discarded and the next statement executed.
*/
