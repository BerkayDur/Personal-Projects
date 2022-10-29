#include <stdio.h>

/*
    Directives are handled by the preprocessor. The preprocessor is a piece of
    software that edits C programs just prior to compilation.

    preprocessing directive (begin with #) control the behaviour of the
    preprocessor.

    #define, defines a macro that the preprocessor replaces every value with
    the desired one.

    #include, tells the preprocessor to open a particular file and include its
    contents as part of the file being compiled.

    The following shows the role of a preprocessor in a compilation process:

                C program
                    -->
                | Preprocessor |
                    -->
                Modified C program
                    -->
                | Compiler |
                    -->
                Object code

    The preprocessor handles directives. It executes these directives, removing
    them in the process. The output of the preprocessor is another C program: an
    edited version of the original program, containing no directives. The
    preprocessors output goes directly in to object code.

    The preprocessor doesn't remove lines containing directives; instead, it
    simply makes them empty.


    Most preprocessing directives fall into one of three categories:

        # Macro definition. The #define directive defines a macro; the #undef
                            directive removes a macro definition.

        # File inclusion. The #include directive causes the contents of a
                          specified file to be included in a program.

        # Conditional compilation. The #if, #ifdef, #ifndef, #elif, #else, and
                                   #endif directives allow blocks of text to
                                   be either included in or excluded from a
                                   program, depending on conditions that can
                                   be tested by the preprocessor.

    The remaining directives - #error, #line, and #pragma - are more
    specialized and therefore used less often.

    These are rules which apply to all directives:

        # Directives always begin with the # symbol.

        # Any number of spaces and horizontal tab characters may separate
          the tokens in a directive.

        # Directives always end at the first new-line character, unless
          explicitly continued. To continue a directive to the next line,
          we must end the current line with a \ character.

        # Directives can appear anywhere in a program.

        # Comments may appear on the same line as a directive.


    Simple macros are ones with no parameter. The definition of a simple macro (or
    object-like macro) has the form:

        # define identifier replacement-list

    replacement-list is any sequence of preprocessing tokens (similar to the tokens
    previously discussed).


    do not put any extra symbols in a macro definition - they'll become a part of the
    replacement list.

    Using #define to create names for constants has several significant advantages:

        # It makes the program easier to read.

        # It makes the program easier to modify.

        # It helps avoid inconsistencies and typographical errors.


    Although simple macros are often used to define names for constants, they do have
    other applications:

        # Making minor changes to the syntax of C.

        # Renaming types.

        # Controlling conditional compilation.

    When macros are used as constants, we usually capitalize all letters in their
    name.


    Parameterized Macros (also known as function-like macro) has the form:

        #define identifier(x1,x2,...,xn) replacement-list

    where x1,x2,...,xn are identifiers (the macro's parameters).

    There must be no space between the macro name and the left parenthesis. If a
    space is left, the preprocessor will assume that we're defining a simple macro;
    it will treat (x1,x2,...,xn) as part of the replacement list.


    Whenever a macro invocation of the form identifier(y1,y2,...,yn) appears later
    in the program (where y1,y2,...,yn are sequences of tokens), the preprocessor
    replaces the replacement-list, substituting y1 for x1, y2 for x2, and so forth.

    For example,

        #define MAX(x,y) ((x)>(y)?(x):(y))
        #define IS_EVEN(n) ((n)%2==0)

    Suppose we invoke the two macros in the following way:

        i = MAX(j+k, m-n);
        if (IS_EVEN(i)) i++;

    the preprocessor will replace these lines by

        i = ((i+k)>(m-n)?(j+k):(m-n));
        if (((i)%2==0)) i++;

    Parameterized macros often serve as simple functions.
    For example,

        #define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

    This is a functions that tests if a character is lower-case, if so, then it
    upper-cases it.

    A parameterized macro may have an empty parameter list. For example:

        #define getchar() getc(stdin)

    the empty parameter list isn't really needed, but it makes getchar resemble a
    function.

    using parameterized macro instead of a true function has a couple of advantages:

        # The program may be slightly faster.

        # Macros are "generic". (meaning they have no type)

    But parameterized macros also have disadvantages:

        # The compiled code will often be larger.

        # Arguments aren't type-checked.

        # It's not possible to have a pointer to a macro.

        # A macro may evaluate its arguments more than once.


    Parameterized macros are good for more than just simulating functions. In
    particular, they're often used as patterns for segments of code that we find
    ourselves repeating.

    For example:

        printf("%d\n", i);

    every time we need to print an integer i. We might define the following macro,
    which makes it easier to display integers:

        #define PRINT_INT(n) printf("%d\n", n)

    once PRINT_INT has been defined, the preprocessor will turn the line

        PRINT_INT(1/j);

    into

        printf("%d\n", i/j);



    Macro definitions may contain two special operators, # ans ##. Neither operator
    is recognised by the compiler; instead, they're executed during preprocessing.


    The # operator converts a macro argument into a string literal; it can appear
    only in the replacement list of the parameterized macro. (The operation performed
    by # is known as "stringization".)

    We can change PRINT_INT to label each value that it prints:

        #define PRINT__INT(n) printf(#n " = %d\n", n)

    The # operator in front of n instructs the preprocessor to create a string literal
    from PRINT_INT's argument. Thus, the invocation

        PRINT_INT(i/j);

    will become

        printf("i/j" " = %d\n", i/j);

    We know that the compiler automatically joins adjacent string literals, so this
    statement is equivalent to

        printf("i/j = %d\n", i/j);


    The ## operator can "paste" two tokens (identifiers, for example) together to
    form a single token. (The ## operation is known as "token-pasting.") If one of the
    operands is a macro parameter, pasting occurs after the parameter has been
    replaced by the corresponding argument. Consider the following macro:

        #define MK_ID(n) i##n

    When MK_ID is invoked as follows:

        int MK_ID(1), MK_ID(2), MK_ID(3);

    After preprocessing, this declaration becomes

        int i1, i2, i3;


    General properties of Macros, which apply to both simple and parameterized macro,
    are:

        # A macro's replacement list may contain invocations of other macros.
          For example:

              #define PI 3.14159
              #define TAU (2*PI)

          The preprocessor replaces TWO_PI with (2*PI), then rescans the replacement
          list to see if it contains invocations of other macros, the preprocessor
          will rescan the replacement list as many times as necessary to eliminate
          all macro names.

        # The preprocessor replaces only entire tokens, not portions of tokens.

        # A macro definition normally remains in effect until the end of the file in
          which it appears.

        # A macro may not be defined twice unless the new definition is identical to
          the old one.

        # Macros may be "undefined" by the #undef directive. The #undef directive
          has the form

              #undef identifier

          where identifier is a macro name. For example, the directive

              #undef N

          removes the current definition of the macro N. (If N hasn't been defined as
          a macro, the #undef directive has no effect.) One use of #undef is to remove
          the existing definition of a macro so that it can be given a new definition.


    Parenthesis are needed for replacement lists in our macro definitions. They're
    necessary as the fewer we use, the more likely we'll get an unexpected result.

    There are two rules to follow when deciding to put parenthesis in a macro
    definition:

        # First, if the macro's replacement list contains an operators, always enclose
          the replacement list in parenthesis:

              #define TAU (2*3.14159)

        # Second, if the macro has parameters, put parenthesis around each parameter
          every time it appears in the replacement list:

              #define SCALE(x) ((x)*10)


    We can create longer macros by using the comma operator, which allows us to make
    the replacement list a series of expressions. For example, the following macro
    will read a string and then print it:

        #define ECHO(s) (gets(s), put(s))

    We can invoke ECHO as though it were a function:

        ECHO(str);      ## becomes (gets(str), puts(str));


    C has several predefined macros. Each macro represents an integer constant or
    string literal. These macros provide information about the current compilation
    or about the compiler itself:

        __LINE__        Line number of file being compiled
        __FILE__        Name of file being compiled
        __DATE__        Date of compilation (in the form "Mmm dd yyyy")
        __TIME__        Time of compilation (in the form "hh:mm:ss")
        __STDC__        1 if the compiler conforms to the C standard

    We can use __LINE__ to locate errors.


    We are allowed to have macro calls with an empty argument (since c99). Such a call
    will contain the same number of commas as a normal call.

    For example:

        #define ADD(x,y) (x+y)

    After preprocessing, the statement

        i = ADD(j,k);

    becomes

        i = (j+k);

    whereas the statement

        i = ADD(,k);

    becomes

        i = (+k);

    When an empty argument is an operand of the # or ## operator, special rules apply.
    IF an argument is "stringized" by the # operator, the result is "" (empty string):

        #define MK_STR(x) #x
        ...
        char empty_string[] = MK_STR();

    After preprocessing, the declaration will have the following appearance:

        char empty_string[] = "";

    If one of the arguments of the ## is empty, it's replaced by an invisible
    "placemarker" token. Concatenating an ordinary token with a placemarker token
    yields the original token (placemarker disappears). IF two placemarkers are
    concatenated, the result is a single placemarker. Once macro expansion has been
    completed, placemarker tokens disappear from the program. Consider the following
    example:

        #define JOIN(x,y,z) x##y##z
        ...
        int JOIN(a,b,c), JOIN(a,b,), JOiN(a,,c), JOiN(,,c);

    After preprocessing, the declaration will have the following appearance:

        int abc, ab, ac, c;



    The __func__ identifier is used for debugging. Every function has access to the
    __func__ identifier, which behaves like a string variable that stores the name of
    the currently executing function.

    The existence of this identifier makes it possible to write debugging macros:

        #define FUNCTION_CALLED() printf("%s called \n", __func__);
        #define FUNCTION_RETURNS() printf("%s returns \n", __func__);

    Call of these macros can the be placed inside functions to trace their calls:

        void f(void)
        {
            FUNCTION_CALLED();      ## Displays "f called" ##
            ...
            FUNCTION_RETURNS();     ## Displays "f returns" ##
        }

    We can also use __func__ to let us know the name of the function being called
    (which can be passed to another function).




    A conditional compilation is used to include or exclude a section of a program
    text depending on the outcome of a test performed by the preprocessor.


    We can use the #if and #endif directives when debugging a program to allow us to
    leave the calls in place, but have the compiler ignore them.

    For example:

    First define a macro and give it a non-zero value:

        #define DEBUG 1

    Next surround each group of printf calls by an #if-#endif pair:

        #if DEBUG
        printf("value of i: %d\n", i);
        printf("value of j: %d\n", j);
        #endif // DEBUG

    During the preprocessing, the #if directive will test the value of DEBUG. Since
    its value isn't 0, the preprocessor will leave the two calls of printf in the
    program (the #if and #endif lines will disappear). If we change the value of
    DEBUG to 0 and recompile the program, the preprocessor will remove all four lines
    from the program. The compiler won't see the calls of printf, so they won't occupy
    space in the object code and won't cost any time when the program is run.

    In general, the #if directive has the form:

        #if constant-expression

    The #endif directive has the form:

        #endif

    The #if directive treats undefined identifiers as macros that have the value 0.


    The defined operator produces a 1 if the identifier is a currently defined macro;
    0 otherwise. It is usually used with the #if directive; it allows us to write:

        #if defined(DEBUG)          ## Parenthesis aren't required ##
        ...
        #endif

    So, the lines between will only be included in the program if DEBUG is defined as
    a macro. Since defined tests only if DEBUG is defined or not, it's not necessary
    to give DEBUG a value:

        #define DEBUG


    The #ifdef directive tests whether an identifier is currently defined as a macro:

        #ifdef identifier

    Using #ifdef is similar to using #if:

        #ifdef identifier
        .... Lines to be included if identifier is defined as a macro
        #endif // identifier

    This is similar to #if:

        #ifdef identifier

                <==>

        #if defined(identifier)

    The #ifndef directive is similar to #ifdef, but tests whether an identifier is not
    defined as a macro:

        #ifndef identifier


    These are the same:

        #ifndef identifier

                <==>

        #if !defined(identifier)


    The #if, #ifdef and #ifndef blocks can be nested just like ordinary if statements.
    For added convenience, the preprocessor supports the #elif and #else directives:

        #elif constant-expression

        #else

    #elif and #else can be used in conjunction with #if, #ifdef, or #ifndef to test
    a series of conditions:

        #if expr1
            Lines to be included if expr1 is non-zero.
        #elif expr2
            Lines to be included if expr1 is zero but expr2 is non-zero.
        #else
            Lines to be included otherwise.
        #endif

    #ifdef or #ifndef directives can be used instead of the #if directive. Any number
    of #elif directives - but at most one #else - may appear between #if and #endif.


    We can use Conditional Compilations for debugging, but it has other uses. Here are
    a few other common applications:

        # Writing programs that are portable to several machines or operating systems.

        # Writing programs that can be compiled with different compilers.

        # Proving a default definition for a macro.

        # Temporarily disabling code that contains comments.


    There are a few miscellaneous directives which are specialized and used less often.

    The #error directive has the form

        #error message

    If the preprocessor encounters an #error directive, it prints an error message which
    must include message. The exact form of the error message can vary from one compiler
    to another. Encountering an #error directive indicates a flaw in the program. The
    #error directive is used in conjunction with conditional compilation to check for
    situations that shouldn't arise during a normal compilation.


    The #line directive is used to alter the way program lines are numbered. (lines
    are usually numbered 1, 2, 3, as you'd expect.) We can also use this directive to
    make the compiler think that it's reading the program from a file with a different
    name.

    The #line directive has two forms. In one form, we specify a line number:

        #line n

    n must be a sequence of digits representing an integer between 1 and 2147483647.
    The directive causes subsequent lines in the program to be numbered n, n+1, n+2, and
    so forth.

    In the second form of the #line directive, both a line number and a file name are
    specified:

        #line n "file"

    The lines that follow this directive are assumed to come from file, with line
    numbers starting at n. The values of n and/or the file string can be specified
    macros.

    One effect of the #line directive is to change the value of the __LINE__ macro
    (and possibly the __FILE__ macro). More importantly, most compilers will use the
    information from the #line directive when generating error messages.


    The #pragma directive provides a way to request special behaviour from the compiler.
    This directive is more useful for programs that are large or need to take advantage
    of the capabilities of a particular compiler.

    The #pragma directive has the form

        #pragma tokens


    C99 introduces the _Pragma operator, which is used in conjunction with the
    #pragma directive. A _Pragma directive has the form

        _Pragma ( string-literal )

    When it encounters such an expression, the preprocessor "destringizes" the string
    literal by removing quotes around the string and replacing the escape sequences
    \" and \\ by the characters " and \, respectively.





    338
*/
