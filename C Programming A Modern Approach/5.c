#include <stdio.h>

/*
	Most of the c statements fall into 3 categories:

		Selection Statements - The if and switch allows a program to select a particular execution
							   path from a set of alternatives.

		Iteration Statements - The while, do, and for statements support iteration.

		Jump Statements - The break, continue, and goto statements cause an unconditional jump
						  to some other place in the program (return also belongs here).

	The rest are compound statements, which group several statements into 1 statement, and the
	null statement, which performs no action.


	Logical Expressions are used to check if something is "truthy" or "falsey". They produce
	a 1 if true, 0 if false.

	relational operators are used in logical expressions to compare values.
	These operators are:
		<	less than
		>	greater than
		<=	less than or equal to
		>=	greater than or equal to

	These can be used to compare integers and floating point numbers, with operands of mixed
	types allowed.
	the precedence of logical operators is less than that of arithmetic operators (and are
	left associative).
	e.g.
		i + j < k - 1 <=> (i + j) < (k - 1)

	It is unwise to mix logical operators into a single logical expression.
	e.g.
		i < j < k <=> (i < j) < k

	This is not what you'd expect, this calculates if k is less than 1 or 0. To do it properly,
	we'd have to use logical connectors (logical operators).

	Equality operators are used to compare adjacent values and to whether they are
	equal (or unequal).
	There are two:
		==	equal to
		!=	not equal to

	They are left associative and produce a 1 (true) or 0 (false), but they have less precedence
	than relational operators.
	e.g.
		i < j == j < k  <=>	 (i < j) == (j < k)

	Logical Operators are used as connectives.
	There are 3 basic ones:
		!	Logical Negation			## Unary ##		## right associative ##
		&&	Logical And (Conjunction)	## Binary ##	## left associative ##
		||	Logical Or (Disjunction)	## Binary ##	## left associative ##

	If the operand is 0, it is treated as a false value.
	If the operand is non-zero, it is treated as a true value.

	If the first operand is 0 in &&, the second operand isn't evaluated.

	If the first operand is non-zero in ||, the second operand isn't evaluated.

	This can cause problems.
	e.g.
		i > 0 && ++j > 0

		if i is less than 0, j isn't incremented

	### PLEASE USE A PRECEDENCE TABLE IF NOT USING BRACKETS ###

	If allows two alternatives for a statement by testing the value of the expression.
	It is of form:

					if ( expression ) { statements }

	the statement executes, if the expression is true (non-zero)

	Can use else as well:

					if (expression ) { statements } else { statements }

	Can nest if and else inside each other, cascading if statement.
	This is where the else-if comes from.
	This looks like this:

			if ( expression )
				statement
			else if ( expression )
				statement
			....
			else if ( expression )
				statement
			else
				statement
*/


// Program to calculate a broker's commission

int broker(void)
{
	float commision, value;

	printf("Enter value of trade: ");
	scanf_s("%f", &value);

	if (value < 2500.00f) {
		commision = 30.00f + .017f * value;
	}
	else if (value < 6250.00f) {
		commision = 56.00f + .0066f * value;
	}
	else if (value < 20000.00f) {
		commision = 76.00f + .0034f * value;
	}
	else if (value < 50000.00f) {
		commision = 100.00f + .0022f * value;
	}
	else if (value < 500000.00f) {
		commision = 155.00f + .0011f * value;
	}
	else
		commision = 255.00f + .0009f * value;

	if (commision < 39.00f) {
		commision = 39.00f;
	}

	printf("Commission $%.2f\n", commision);

	return 0;
}

/*
	It's best to use brackets to ensure we know where everything goes.

	An else statement belongs to the nearest if statement that hasn't already been paired to one.
	So, to resolve this, use {}

	We can make use Conditional Expressions, these require the conditional operators (? and :),
	and is used in this way:

		expr1 ? expr2 : expr3	<=> if expr1 then expr2, else expr3.

	These can be used in the place of if and else statements
	e.g.
		if (i > j)
			return i;
		else					<=>			return i > j ? i : j;
			return j;

	e.g.
		if (i > j)
			printf("%d\n", i);
		else					<=>			printf("%d\n", i > j ? i : j);
			printf("%d\n", j);


	The Switch statement is an alternative to using cascading if statements (it's also faster).
	e.g.

		if (num==3)								switch (num) {
			printf("3");							case 3:  printf("3");
		elif if (num==2)									 break;
			printf("2");				<=>			case 2:  printf("2");
		elif if (num==1)									 break;
			printf("1");							case 1:  printf("1");
		else												 break;
			printf("0")								default: printf("0");
															 break;

	In its most common form,
		switch ( expression ) {
			case constant-expression: statements
			...
			case constant-expression: statements
			default: statements
		}

	the controlling expression at the top must be an integer (can be a character in ASCII).

	each case has the same form but the expression must be a constant value like 10, or 4+6,
	but n+10 isn't (unless n is a defined macro), and this must be an integer (or character).

	Statements can be added after a case, but it needs break at the end of the case.

	case labels must be unique.

	different cases may have the same group of statements.
	e.g.
		switch (num) {
			case 3: case 2: case 1:
						printf("Passing");
						break;
			default:	printf("Failing");
						break;

	default case isn't required in a switch statement. But if no cases are matched and there
	isn't a default, control passes to the next statement after switch.

	Switch works by jumping to the case that is true and executing every statement after it. So,
	without the break, all other cases after the true one will also be printed.
	##### ALWAYS USE BREAK #####

	But not using break, can be advantageous
*/


// Program to print the date in legal form

int date(void)
{
	int month, day, year;

	printf("Enter date (mm/dd/yy): ");
	scanf_s("%d/%d/%d", &month, &day, &year);

	printf("Dated this %d", day);
	switch (day){
		case 1: case 21: case 31:
			printf("st"); break;
		case 2: case 22:
			printf("nd"); break;
		case 3: case 23:
			printf("rd"); break;
		default: printf("th"); break;
	}
	printf(" day of ");

	switch (month) {
		case 1: printf("January"); break;
		case 2: printf("February"); break;
		case 3: printf("March"); break;
		case 4: printf("April"); break;
		case 5: printf("May"); break;
		case 6: printf("June"); break;
		case 7: printf("July"); break;
		case 8: printf("August"); break;
		case 9: printf("September"); break;
		case 10: printf("October"); break;
		case 11: printf("November"); break;
		case 12: printf("December"); break;
	}

	printf(", 20%.2d.\n", year);
	return 0;
}
