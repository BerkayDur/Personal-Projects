#include <stdio.h>

/*
    A string literal is a sequence of characters enclosed within double
    quotes.

    String literals may contain the same escape sequences as character constants.
    Can use octal and hexa escape sequences in string literals but remember that octals
    end after 3 digits or with the first non-octal character.

    If a string literal is too long to fit on one line, we can continue it onto the
    next line, provided that we end the first line with a backslash character (\).
    No other characters may follow \ on the same line, other than the new-line character

    The \ character can be used to join two or more lines of a program into a single
    line (spicing).

    using \ has one drawback: the string must continue at the beginning of the next line,
    thereby wrecking the program's indented structure.

    The better way to deal with long string literals is to have more than one string
    literal, which is only separated by white space, the compiler will join them into a
    single string. e.g.

        printf("That kid is "
               "not my son");

    String literals are treated as character arrays. When a C compiler encounters a
    string literal of length n, it sets aside n+1 bytes of memory for the string.
    This are of memory will contain the characters in the string, plus one extra
    character - the null character - to mark the end of the string. The null
    character is a byte whose bits all zero, so it's represented by the \0 escape
    sequence.

    For example, the string literal "abc" is stored as an array of four characters:

                a | b | c | \0

    String literals may be empty; the string "" is stored as a single null character:

                \0

    Since a string literal is treated as an array, the compiler treats it as a pointer
    of type char *. Both printf and scanf, for example, expect a value of type char *
    as their first argument. Consider the following example:

        printf("abc");

    When prinf is called, it's passed the address of "abc" (a pointer to where the
    letter a is stored in memory).


    We can use a string literal wherever C allows a char * pointer. For example, a
    string literal can appear on the right side of an assignment:

        char *P;
        p = "abc";

    This assignment doesn't copy the characters in "abc"; it merely makes p point to
    the first character of the string.

    C allows pointers to be subscripted, so we can subscript string literals:

        char ch;
        ch = "abc"[1];

    The new value of ch will be the letter b. The other possible subscripts are 0 (a),
    2 (c), and 3 (the null character).

    This property doesn't have much use. Consider the following function, which
    converts a number between 0 and 15 into a character that represents the
    individual hex digit:

        char digit_to_hex_char(int digit)
        {
            return "0123456789ABCDEF"[digit];
        }

    Attempting to modify a string literal causes undefined behaviour:

        char *p = "abc";

        *p = 'd'            ### Wrong ###

    A program that tries to change a string literal may crash or behave erratically.


    A string literal containing a single character isn't the same as a character
    constant. The string literal "a" is represented by a pointer to a memory location
    that contains the character a (followed by a null character). The character
    constant 'a' is represented by an integer (the numerical code for the character).

    Don't ever use a character when a string is required (the converse is also true).



    Any one-dimensional array of characters can be used to store a string. Let's say
    we need a variable capable of storing a string of up to 80 characters. Since the
    string will need a null character at the end, we'll declare the variable to be
    an array of 81 characters:

        # define STR_LEN 80
        ...
        char str[STR_LEN+1];

    Doing this adds emphasis to the fact that str can store no more than 80
    characters.

    A string can be initialized at the same time it's declared:

        char datel[8] = "June 14";

    datel looks like this:

        J | u | n | e |   | 1 | 4 | \0

    Although "June 14" appears to be a string literal, it's not. Instead, C views it
    as an abbreviation for an array initializer. In fact, we could have written:

        char datel[8] = {'J', 'u', 'n', 'e', ' ', '1', '4', '\0'};

    If the initializer is too short to fill the string variable, the compiler will
    add extra null characters. Thus, the declaration

        char date2[9] = "June 14";

    date2 will have the following appearance:

        J | u | n | e |   | 1 | 4 | \0 | \0

    This behaviour is consistent with all array initializers. When an array
    initializer is shorter than the array itself, the remaining elements are
    initialized to zero. By initializing the leftover elements of a character array
    to \0, the compiler is following the same rule.

    The initializer cannot be longer than the string variable. However, the
    initializer (not counting the null character) to have exactly the same length
    as the variable:

        char date3[7] = "June 14";

    There's no room for the null character, so the compiler makes no attempt to store
    one:

        J | u | n | e |   | 1 | 4

    This makes it unusable as a string.

    Always be sure that the length of the array is longer than the length of the
    initializer. Otherwise, the compiler will omit the null character, making the
    array unusable as a string.

    The declaration of a string variable may omit its length, it which case the
    compiler computes it:

        char date4[] = "June 14";

    The compiler sets aside eight characters for date4, enough to store the characters
    in "June 14" plus a null character (The fact that the length of date4 isn't
    specified doesn't mean that the array's length can be changed later. Once the
    program is compiled, the length of date4 is fixed at eight).


    Let's compare the declaration

        char date[] = "June 14";

    which declares date to be an array, with a similar-looking

        char *date = "June 14";

    which declares date to be a pointer. Either version can be used as a string.
    Any function expecting to be passed a character array or character pointer will
    accept either version of date as an argument.

    However, we must be careful not to make the mistake of thinking that the two
    versions of date are interchangeable. There are significant differences between
    the two:

        # In the array version, the characters stored in date can be modified,
          like the elements of an array. In the pointer version, date points to
          a string literal, and string literals shouldn't be modified.

        # In the array version, date is an array name. In the pointer version, date
          is a variable that can be made to point to other strings during the program
          execution.

    If we need a string that can be modified, it's our responsibility to set up an
    array of characters in which to store the string; declaring a pointer variable
    isn't enough. The declaration

        char *p;

    causes the compiler to set aside enough memory for a pointer variable; but not
    it doesn't allocate space for a string (it couldn't because we haven't indicated
    how long the string would be). Before we can use p as a string, it must point to
    an array of characters. One possibility is to make p point to a string variable:

        char str[STR_LEN+1], *p;

        p = str;

    p now points to the first character of str, so we can use p as a string. Another
    possibility is to make p point to a dynamically allocated string.

    Using an uninitialized  pointer variable as a string is a serious error. Consider
    the following example, which attempts to build the string "abc":

        char *p;

        p[0] = 'a';         ### wrong ###
        p[1] = 'b';         ### wrong ###
        p[2] = 'c';         ### wrong ###
        p[3] = '\0';         ### wrong ###

    Since p hasn't been initialized, we don't know where it's pointing. Using the
    pointer to write characters a, b, c, and \0 in memory causes undefined behaviour.




    We can write strings using printf and puts. The conversion specification %s
    allows printf to write a string. Consider the following example:

        char str[] = "Are we having fun yet?";

        printf("%s\n", str);

    The output will be

        Are we having fun yet?

    printf writes the characters in a string one by one until it encounters a null
    character (if the null character is missing, printf continues past the end of the
    string until - eventually - it finds a null character somewhere in memory).

    To print just part of a string, we can use the conversion specification % .ps,
    where p is the number of characters to be displayed. The statement

        printf("%.6s\n", str);

    will print

        Are we

    A string like a number can be printed within a field. The %ms conversion will
    display a string in a field size m. (A string with more than m characters will
    be printed in full, not truncated.) If the string has fever than m characters,
    it will be right-justified within the field. To for left justification instead,
    we put a minus sign in front of m. The m and p values can be used in combination:
    a conversion specification of the form %m.ps cause the first p characters of a
    string to be displayed in a field of size m.

    printf isn't the only function that can write strings. The c library also
    provides puts, which is used in the following way:

        puts(str);

    puts has only one argument (the string to be printed). After writing the string,
    puts always writes an additional new-line character, thus advancing to the
    beginning of the next output line.


    We can read strings using scanf and gets. The conversion specification %s allows
    scanf to read a string into a character array:

        scanf("%s", str);

    There is no need to put the & operator in front of str in the call of scanf; like
    any array name, str is treated as a pointer when passed to a function.

    When scanf is called, it skips white-space, then reads characters and stores them
    in str until it encounters a white-space character. scanf always stores a null
    character at the end of the string.

    A string read using scanf will never contain white space. Consequently, scanf
    won't usually read a full line of input; a new-line character will cause scanf
    to stop reading, but so will a space or tab character.

    To read an entire line of input, we can use gets. Like scanf, the gets function
    reads input characters into an array, then store a null character.

    But in other respects, however, gets is somewhat different from scanf:

        # gets doesn't skip white space before starting to read the string
          (scanf does).

        # gets reads until it finds a new-line character (scanf stops at any
          white-space character). Incidentally, gets discards the new-line character
          instead of storing it in the array; the null character takes its place.


    To see the difference between scanf and gets, consider the following
    program fragment:

        char sentence[SENT_LEN+1];

        printf("Enter a sequence:\n");
        scanf("%s", sentence);

    suppose that after the prompt

        Enter a sentence:

    the user enters the line

          To C, or not to C: that is the question.

    scanf will store the string "To" in sentence. The next call of scanf will resume
    reading the line at the space after the word To.

    Now suppose we replace scanf by gets:

        gets(sentence);

    When the user enter the same input as before, gets will store the string

        "  To C, or not to C: that is the question."

    in sentence.


    As they read characters into an array, scanf and gets have no way to detect when
    it's full. Consequently, they may store characters past the end of the array,
    causing undefined behaviour. scanf can be made safer by using the conversion
    specification %ns instead of %s, where n is an integer indicating the maximum
    number of characters to be store. gets, unfortunately, is inherently unsafe;
    fgets is a much better alternative.




    Since scanf and gets are risky and insufficiently flexible for many applications,
    we can make our own input function. By reading strings one character at a time,
    these functions provide a greater degree of control than the standard input
    functions.

    If we decide to make our own input function, we'll need to consider the
    following issues:

        # Should the function skip white space before beginning to store the string?

        # What character causes the function to stop reading: a new-line character,
          any white-space character, or some other character? Is this character stored
          in the string or discarded?

        # What should the function do if the input string is too long to store:
          discard the extra characters or leave them for the next input operation.


    Suppose we need a function that doesn't skip white-space characters, stops reading
    at the first new-line character (which isn't stored in the string), and discards
    extra characters. The function might have the following prototype:

        int read_line(char str[], int n);

    str represents the array into which we'll store the input and n is the maximum
    number of characters to be read. If the input line contains more than n
    characters, read_line will discard any additional characters. We'll have
    read_line return the number of characters it actually stores in str (a number
    anywhere from 0 to n). We may not always need read_line's return value, but
    it doesn't hurt to have it available.

    read_line consists primarily of a loop that calls getchar to read a character
    and then stores the character in str, provided that there's room left. The loop
    terminates when the new-line character is read. (Strictly speaking, we should
    also have the loop terminate if getchar should fail to read a character, but
    we'll ignore that complication for now.) Here's the complete definition for
    read_line:

*/

// Function that reads input line:

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n'){
        if (i < n){
            str[i++] = ch;
        }
    str[i] = '\0';              // terminates string
    return i;                   // number of characters stored
    }
}


/*
    note that ch has int type rather than char type, because getchar returns the
    character that it reads as an int value.

    before returning, read_line puts a null character at the end of the string.
    Standard functions such as scanf and gets automatically put a null character at
    the end of an input string; if we're writing our own input function, however,
    we must take on that responsibility .



    We can use subscripting to access the characters in a string, since strings are
    stored as arrays. To process every character in a string s, for example, we can
    set up a loop that increments a counters i and selects characters via the
    expression s[i]. Suppose that we need a function that counts the number of
    spaces in a string. Using array subscripting, we might write the function in the
    following way:
*/

// Function that counts the number of spaces in a string using array indexing

int count_spaces1(const char s[])
{
    int count = 0, i;

    for (i = 0; s[i] != '\0'; i++){
        if (s[i] == ' '){
            count++;
        }
    }
    return count;
}

/*
    const is included in the declaration of s to indicate that count_spaces doesn't
    change the array that s represents. If s were not a string, the function wouldn't
    need a second argument specifying the length of the array. Since s is a string,
    however, count_spaces can determine where it end by testing for the null character.

    We can also use pointers to keep track of the current position within the string.

    Let's rewrite count_spaces using pointer arithmetic instead of array subscripting.
    We'll eliminate the variable i and use s itself to keep track of our position in
    the string. By incrementing s repeatedly, count_spaces can step through each
    character in the string:
*/

// Function that counts the number of spaces in a string using pointer arithmetic

int count_spaces2(const char *s)
{
    int count = 0;

    for (; *s != '\0'; s++){
        if (*s == ' '){
            count++;
        }
    }
    return count;
}

/*
    Note that const doesn't prevent the the function from modifying s; it's there to
    prevent the function from modifying what s points to. And since s in a copy of
    the pointer that's passed to count_spaces, incrementing s doesn't affect the
    original pointer.

    This function raises some questions about how to write string functions:

        # Is it better to use array operations or pointer operations to access
          characters in a string?

          We're free to use whichever is more convenient; we can also mix the two.
          In the second version, treating s as a pointer simplifies the function
          slightly by removing the need for the variable i. (Traditionally c
          programmers tend to use pointer operations for processing strings).


        # Should a string parameter be declared as an array or a pointer?

          There's no difference between the 2 declarations, as the compiler treats
          an array parameter as though it has been declared as a pointer.


        # Does the form of the parameter (s[] or *s) affect what can be supplied as
          an argument?

          No. When the function is called, the argument could be an array name, a
          pointer variable, or a string literal - the function can't tell the
          difference.



    In C, the operators are useless for working with strings. Strings are treated as
    arrays in C, so they're restricted in the same way as arrays - in particular,
    they can't be copied or compared using operators.

    Direct attempts to copy or compare strings will fail. For example, suppose that
    str1 and str2 have been declared as follows:

        char str1[10], str2[10];

    Copying a string into a character array using = is not possible:

        str1 = "abc";       ### Wrong ###
        str2 = str1;        ### Wrong ###

    Using an array name as the left operand of = is illegal. Initializing a character
    array using = is legal, though:

        char str1[10] = "abc";

    In the context of a declaration, = is not the assignment operator.

    Attempting to compare string using the relational or equality operator is legal
    but won't produce the desired result:

        if (str1 == str2) ...       ### Wrong ###

    This statement compares str1 and str2 as pointers; it doesn't compare the
    contents of the 2 arrays. Since str1 and str2 have different addresses, the
    expression str1 == str2 must have the value 0.


    C library provides a set of functions for performing operations on strings.
    Prototypes for these functions reside in the <string.h> header, so programs
    that need string operations should contain the following line:

        #include <string.h>

    Most of the functions declared in <string.h> require at least one string as an
    argument. String parameters are declared to have type char *, allowing the
    argument to be a character array, a variable of type char *, or a string
    literal - all are suitable as strings. Watch out for string parameters that
    aren't declared const, however. Such a parameter may be modified when the function
    is called, so the corresponding argument shouldn't be a string literal.

    Assuming str1 and str2 are character arrays used as strings, there are a few
    basic functions in <string.h>.

    the strcpy (String Copy) function has the following prototype in <string.h>:

        char *strcpy(char *s1, const char *s2);

    strcpy copies the string s2 into the string s2. (More precisely, "strcpy copies
    the string pointed to by s2 into the array pointed to by s1.") That is, strcpy
    copies characters from s2 to s1 up to (and including) the first null character
    in s2. strcpy returns s1 (a pointer to the destination string). The string pointed
    to by s2 isn't modified, so it's declared const.

    The existence of strcpy compensates for the fact that we can't use the assignment
    operator to copy strings. For example, suppose that we want to store the string
    "abcd" in str2. We can't use the assignment

        str2 = "abcd";              ### Wrong ###

    because str2 is an array name and can't appear on the left side of an assignment.
    Instead, we can call strcpy:

        strcpy(str2, "abcd");       ## str2 now contains "abcd" ##

    Similarly, we can't assign str2 to str1 directly, but we can call strcpy:

        strcpy(str1, str2);         ## str1 now contains "abcd" ##

    Most of the time, we'll discard the value that strcpy returns. But it can be
    useful for its return value. For example, we could chain a series of
    strcpy calls:

        strcpy(str1, strcpy(str2, "abcd"));

        ## both str1 and str2 now contain "abcd" ##


    In the call strcpy(str1, str2), strcpy has no way of checking if the string
    pointed to by str2 will actually fit in the array pointed to by str1. If str2
    points to a string than str1, the behaviour is undefined.


    strncpy function is a safer, albeit slower, way of copying a string. strncpy is
    similar to strcpy but has a third argument that limits the number of characters
    that will be copied. To copy str2 into str1, we could use the following call of
    strncpy:

        strncpy(str1, str2, sizeof(str1));

    As long as str1 is large enough to hold the string stored in str2 (including the
    null character), the copy will be done correctly.

    strncpy isn't without danger. It will leave the string in str1 without a
    terminating null character if the length of the string stored in str2 is greater
    than or equal to the size of the str1 array. Here's a safer way of using strncpy:

        strncpy(str1, str2, sizeof(str1) - 1);
        str1[sizeof(str1)-1] = '\0';

    The second argument guarantees that str1 is always null-terminated, even if
    strncpy fails to copy a null character from str2.


    The strlen (String Length) function is used to determine the length of a string.
    If has the following prototype:

        size_t strlen(const char *s);

    size_t, which is defined in the C library, is a typedef name that represents one
    of C's unsigned integer types. This is useful if we're dealing with extremely
    long integer types - we can simply treat the return value of strlen as an integer.

    strlen returns the length of a string s: the number of characters in s up to, but
    not including, the first null character. For example:

        int len;

        len = strlen("abc");        # len is now 3 #
        len = strlen("");           # len is now 0 #
        strcpy(str1, "abc");
        len = strlen(str1);         # len is now 3 #

    The last example illustrates the point that: when given an array as its argument,
    strlen doesn't measure the length of the array itself; instead, it returns the
    length of the string stored in the array.


    The strcat (String Concatenation) function is used to add strings. It has the
    following prototype:

        char *strcat(char *s1, const char *s2);

    strcat appends the contents of the string s2 to the end of the string s1; it
    returns s1 (a pointer to the resulting string).

    Here some examples:

        strcpy(str1, "abc");
        strcat(str1, "def");        # str1 now contains "abcdef" #
        strcpy(str1, "abc");
        strcpy(str1, str2);
        strcat(str1, str2);         # str1 now contains "abcdef" #

    As with strcpy, the value returned by strcat is normally discarded. The following
    example shows how the return value might be used:

        strcpy(str1, "abc");
        strcpy(str2, "def");
        strcat(str1, strcat(str2, "ghi"));

        # str1 now contains "abcdefghi" ; str2 contains "defghi" #

    The effect of calling strcat(str1, str2) is undefined if the array pointed to by
    str1 isn't long enough to accommodate the additional characters from str2.
    Consider the following example:

        char str1[6] = "abc";

        strcat(str1, "def");        ### Wrong ###

    strcat will attempt to add the characters d, e, f, and \0 to the end of the string
    already stored in str1. Unfortunately, str1 is limited to six characters, causing
    strcat to write past the end of the array.

    The strncat function is a safer but slower version of strcat. Like strncpy, it
    has a third argument that limits the number of characters it will copy. Here's
    what a call might look like:

        strncat(str1, str2, sizeof(str1) - strlen(str1) - 1);

    strncat will terminate str1 with a null character, which isn't included in the
    third argument (the number of characters to be copied). In this example, the third
    argument calculates the amount of space remaining in str1 (given by the expression
    sizeof(str1) - strlen(str1)) and then subtracts 1 to ensure that there will be
    room for the null character.



    The strcmp (String Comparison) function is used to compare 2 strings.
    It has the following prototype:

        int strcmp(const char *s1, const char *s2);

    strcmp compares the strings s1 and s2, returning a value less than, equal to, or
    greater than 0, depending on whether s1 is less than, equal to, or greater than
    s2. For example, to see if str1 is less than str2, we'd write

        if (strcmp(str1, str2) < 0)         # is str1 < str2? #
            ...

    To test whether str1 is less than or equal to str2, we'd write

        if (strcmp(str1, str2) <= 0)        # is str1 <= str2? #
            ...

    So by using relational operators or equality operators, we can test any possible
    relation between str1 and str2.

    strcmp compares strings based on their lexicographic ordering, which resembles
    the way words are arranged in a dictionary. More precisely, strcmp considers
    s1 to be less than s2 if either one of the following conditions is satisfied:

        # The first i characters of s1 and s2 match, but the (i+1)st character of s1
          less than the (i+1)st character of s2.

          For example, "abc" is less than "bcd", and "abd" is less than "abe".


        # All characters of s1 match s2, but s1 is shorter than s2. For example,
          "abc" is less than "abcd"

    As it compares characters from two strings, strcmp looks at the numerical codes
    that represent the characters. Some knowledge of the underlying character set is
    helpful in order to predict what strcmp will do. For example, here are a few
    important properties of the ASCII character set:

        # The characters in each of the sequence A-Z, a-z, and 0-9 have consecutive
          codes.

        # All upper-case letters are less than all lower-case letter. (In ASCII,
          codes between 65 and 90 represent upper-case letters; codes between 97 and
          122 represent lower-case letters.)

        # Digits are less than letters. (Codes between 48 and 57 represent digits.)

        # Spaces are less than all printing characters. (The space character had the
          value 32 in ASCII.)

*/

// Program that prints a one month reminder list

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50       // maximum number of reminders
#define MSG_LEN 60          // max length of reminder message

int read_line(char str[], int n);

int remind(void)
{
    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[3], msg_str[MSG_LEN+1];
    int day, i, j, num_remind = 0;

    for(;;){
        if (num_remind == MAX_REMIND){
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0){
            break;
        }
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++){
            if (strcmp(day_str,reminders[i]) < 0){
                break;
            }
        }
        for (j = num_remind; j > i; j--){
            strcpy(reminders[j], reminders[j-1]);
        }
        strcpy(reminders[i], day_str);
        strcpy(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++){
        printf(" %s\n", reminders[i]);
    }
    return 0;
}

int read_line2(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n'){
        if (i < n){
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}


/*
    sprintf(expr1, expr2, expr3 ...) is used to store the string expr2 with conversion
    specifications for expr3 (inclusive) onwards into the variable expr1.
*/



/*
    String Idioms


    Many string operations require searching for the end of a string. The strlen
    function is a prime example. The following version of strlen searches its string
    argument to find the end, using a variable to keep track of the string's length
    (fast version):

        size_t strlen(const char *s)
        {
            const char *p = s;
            while (*s){
                s++;
            }
            return s - p;
        }

    This version computes the length of the string by locating the position of the
    null character, then subtracting from it the position of the first character in
    the string.

    The statement

        while (*s){
            s++;
        }

    and the related

        while (*s++){
            ;
        }

    are idioms meaning "search for the null character at the end of a string."
    The first version leaves s pointing to the null character. The second version
    is more concise, but leaves s pointing just past the null character.


    Copying a string is a common operation. Here's a condensed version:

        char *strcat(char *s1, const char *s2)
        {
            char *p = s1;

            while (*p){
                p++
            }
            while (*p++ = *s2++){
                ;
            }
            return s1;
        }


    In this version, there is the string copy idiom:

        while (*p++ = *s2++){
            ;
        }

    If we ignore the two ++ operators, the expression inside the braces simplifies to
    an ordinary assignment:

        *p = *s2

    This expression copies a character from where s2 points to where p points. After
    the assignment, both p and s2 are incremented. Repeatedly executing this expression
    has the effect of copying a series of characters where s2 points to where p points.

    But what causes this loop to terminate? Since the primary operator inside the
    braces is assignment, the while loop tests the value of the assignment - the
    character that was copied. All characters except the null has been copied. And
    since the loop won't terminate until the null character has been copied. And since
    the loop terminates after the assignment, we don't need a separate statement to
    put a null character at the end of the new string.


    If we fill an two-dimensional array with varying length strings, there is a lot
    of wasted space, as a lot of the elements will be the null character.

    So what we need is a ragged array: a two-dimensional array whose rows can have
    different lengths. C doesn't provide a ragged array type, but it does give us the
    tools to simulate one. The way to do this is create an array whose elements are
    pointers to strings.

    e.g.

        char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn",
                           "Uranus", "Neptune", "Pluto"};

    So this is stored like this:

        0   points to   M | e | r | c | u | r | y | \0
        1   points to   V | e | n | u | s | \0
        2   points to   E | a | r | t | h | \0
        3   points to   M | a | r | s | \0
        4   points to   J | u | p | i | t | e | r | \0
        5   points to   S | a | t | u | r | n | \0
        6   points to   U | r | a | n | u | s | \0
        7   points to   N | e | p | t | u | n | e | \0
        8   points to   P | l | u | t | o | \0

    Each elements of planets is a pointer to a null-terminated string. There are no
    longer any wasted characters in the strings, although we've had to allocate space
    for the pointers in the planets array.

    To access one of the planet names, all we need do is subscripts the planets array.

    To search the planets array for strings beginning with the letter M, for example,
    we could use the following loop:

        for (i = 0; i < 9; i++){
            if (planets[i][0] == 'M'){
                printf("%s begins with M\n", planets[i]);
            }
        }

    Command-line information is available to all program (stuff in the unix command),
    not just operating-system commands. To obtain access to these command-line
    arguments (called program parameters in the C standard), we must define main as a
    function with two parameters, which are customarily named argc and argv:

        int main(int argc, char *argv[])
        {
            ...
        }

    argc ("argument count") is the number of command-line arguments (including the
    name of the program itself). argv ("argument vector") is an array of pointers to
    the command-line arguments, which are stored in string form. argv[0] points to the
    name of the program, while argv[1] through argv[argc-1] points to the remaining
    command-line arguments.

    argv has one additional element, argv[argc]. Which is always a null pointer -
    a special pointer that points to nothing. The macro NULL represents a null pointer.

    If the user enters the command line

        ls -1 remind.c

    then argc will be 3, argv[0] will point to a string containing the program name,
    argv[1] will point to the string "-1", argv[2] will point to the string
    "remind.c", and argv[3] will be a null pointer:

        0   points to   program name
        1   points to   - | 1 | \0
        2   points to   r | e | m | i | n | d | . | c | \0
        3   null pointer

    If the program name isn't available, arg[0] points to an empty string.

    We can easily access elements as since argv is an array of pointers. For example,
    the following loop prints the command-line arguments, one per line:

        int i;

        for (i = 1; i < argc; i++){
            printf("%s\n", argv[i])
        }

    Another technique is to set up a pointer to argv[1], the increment the pointer
    repeatedly to step through the rest of the array. Since the last element of argv is
    always a null pointer, the loop can terminate when it finds a null pointer in the
    array:

        char *p;

        for (p = &arg[1]; *p != NULL; p++){
            printf("%s\n", *p);
        }

    Since p is a pointer to a pointer to a character, we've got to use it carefully.
    Setting p equal to &argv[1] makes sense; argv[1] is a pointer to a character, so
    &argv[1] will be a pointer to a pointer. The test is ok, since both operands are
    pointers. printing *p points to the first character in a string.


*/

// Program that checks planet names

#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int planet(int argc, char *argv[])
{
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};

    int i, j;

    for (i = 1; i < argc; i++){
        for (j = 0; j < NUM_PLANETS; j++){
            if (strcmp(argv[i], planets[j]) == 0){
                printf("%s is planet %d\n", argv[i], j+1);
                break;
            }
        }
        if (j == NUM_PLANETS){
            printf("%s is not a planet\n", argv[i]);
        }
    }
    return 0;
}

/*
    The program visits each command-line argument in turn, comparing it with the
    strings in the planets array until it finds a match or reaches the end of the
    array. The most interesting part is the call of strcmp, in which the arguments
    are argv[i] (a pointer to a command-line argument) and planets[j] (a pointer
    to a planet name).


    writing a[] is the same as writing *a.
*/





