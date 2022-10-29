#include <stdio.h>

/*
    Pointers can be used with arrays and one of the primary reasons is for efficiency.

    We can use pointers to point to array element. For example, suppose that a and p have
    been declared as follows:

        int a[10], *p;

    We can make p point to a[0] by writing

        p = &a[0];

                    # p points to a[0] #

    We can now access a[0] through p; for example, we can store the value 5 in a[0] by writing

        *p = 5;

                    # p points to a[0], which now has the value 5 #

    We can now perform pointer arithmetic (or address arithmetic) on p, we can access the other
    elements of a. In c, there are 3 forms of pointer arithmetic:

        Adding an integer to a pointer.
        Subtracting an integer from a pointer.
        Subtracting one pointer from another.

    The examples ahead assume that the following declarations are in effect:

        int a[10], *p, *q, i;


    Adding an Integer to a Pointer:

        Adding an integer j to a pointer p yields a pointer to the element j places after the
        one that p points to. More precisely, if p points to the array element a[i], then
        p + j points to a [i + j] (provided [i + j] exists).
        For example,

            p = &a[2];

                        # p points to a[2] #

            q = p + 3;

                        # q points to a[5] #

             p += 6;
                        # p now points to a[8] #


    Subtracting an Integer from a Pointer:

        If p points to an array element a[i], then p - j points to a[i - j].
        For example,

            p = &a[8];

                        # p points to a[8] #

            q = p - 3;

                        # q points to a[5] #

            p -= 6;

                        # p now points to a[2] #


    Subtracting one pointer from another:

        When one pointer is subtracted from another, the result is the distance (measured in
        array elements) between the pointers. Thus if p points to a[i] and q points to a[j],
        then p - q is equal to i - j.
        For example,

            p = &a[5];
            q = &a[1];

                        # p points to a[5] #
                        # q points to a[1] #

            i = p - q;      # i is 4 #
            i = q - p;      # i is -4 #


    Performing pointer arithmetic on a pointer that doesn't point to an array element causes
    undefined behaviour. Furthermore, the effect of subtracting one pointer from another is
    undefined unless both point elements of the same array.


    We can compare pointer using the relational operators (<, <=, >, >=) and the equality
    operators (== and !=). Using relational operators to compare two pointers is meaningful
    only when both point to elements of the same array. The outcome of the comparison
    depends on the relative positions of the two elements in the array.
    For example, after the assignments

        p = &a[5];
        q = &a[1];

    the value of p <= q is 0, and the value of p >= q is 1.


    It's legal for a pointer to point to an element within an array created by a compound
    literal (a compound literal can be used to create an array with no name).
    Consider the following example,

        int *p = (int []){3, 0, 3, 4, 1};

    p points to the first element of the five-dimensional array containing the integers
    3, 0, 3, 4, 1. Using a compound literal saves us the trouble of declaring an array
    variable and then making p point to the first element of that array:

        int a[] = {3, 0, 3, 4, 1};
        int *p = &a[0];                 <=>             int *p = (int []){3, 0, 3, 4, 1};



    Pointer arithmetic allows us to visit the elements of an array by repeatedly incrementing
    a pointer variable.

    The following program fragment, which sums the elements of an array a, illustrates the
    technique. In this example, the pointer variable p initially points to a[0]. Each time
    through the loop, p is incremented; as a result, it points to a[1], the a[2], and so forth.
    The loop terminates when p steps past the last element of a.

        #define N 10
        ...
        int a[N], sum, *p;
        ...
        sum = 0;
        for (p = &a[0]; p < &a[N]; p++){
            sum += *p;
        }

    At the end of the first iteration:

        # p points to a[0], which has the value 11 #
        # sum is now 11 #

    At the end of the second iteration:

        # p now points to a[1], which has the value 34 #
        # sum is now 45 #

    At the end of the third iteration:

        # p now points to a[2], which has the value 82 #
        # sum is now 127 #


    In the condition p < &a[N] in the for statement is strange. It's legal to apply the the
    address operator on a[N], even though this element doesn't exist (a is indexed from 0
    to N-1). Using a[N] in this fashion is perfectly safe, since the loop doesn't attempt to
    examine its value. The of the loop will be executed with p equal to &a[0], &a[1], ...,
    &a[N-1], but when p is equal to &a[N], the loop terminates.

    The loop could've been written without pointers, using subscripting instead. But using
    pointer arithmetic is usually faster than subscripting.


    C programmers often combine the * (indirection) and ++ operators in the statements that
    process array elements. Consider the simple case of storing a value into an array element
    and then advancing to the next element. Using simple array subscripting, we might write:

        a[i++] = j;

    If p is pointing to an array element, the corresponding statement would be

        *p++ = j;

    Because the postfix version of ++ takes precedence over *, the compiler sees this as

        *(p++) = j;

    The value of p++ is p. (Since we're using the postfix version of ++, p won't be
    incremented until after the expression has been evaluated.) Thus, the value of *(p++)
    will be *p - the object to which p is pointing.

    This isn't the only legal combination of * and ++. We could write (*p)++, for example,
    which returns the value of the object that p points to, and the increments the object
    (p itself is unchanged).Below explains:

        Expression              Meaning

        *p++ or *(p++)          Value of expression is *p before increment; increment p later.
        (*p)++                  Value of expression is *p before increment; increment *p later.
        *++p or *(++p)          Increment p first; value of expression is *p after increment.
        ++*p or ++(*p)          Increment *p first; value of expression is *p after increment.


    All four combinations appear in programs. The most frequently used one is *p++, which is
    handy in loop.
    Instead of writing

        for (p = &a[0]; p < &a[N]; p++)
            sum += *p;

    to sum elements of the array a, we could write

        p = &a[0];
        while (p < &a[N])
            sum += *p++;

    The * and -- operators mix in the same way.



    The name of an array can be used as a pointer to the first element in the array.

    Suppose a is declared as follows:

        int a[10];

    Using a as a pointer to the first element in the array, we can modify a[0]:

        *a = 7;

                    # a points to a[0], which now has value 7 #

    We can modify a[1] through the pointer a+1:

        *(a+1) = 12;

                    # a+1 points to a[1], which now has value 12 #

    a+i is the same as &a[i] (both represent a pointer to element i of a) and *(a+i) is
    equivalent to a[i] (both represent element i itself). In other words, array subscripting
    can be viewed as a form of pointer arithmetic.

    The fact that an array name can serve as a pointer makes it easier to write loops that
    step through an array. Consider the following for loop:

        for (p = &a[0]; p < &a[N]; p++)
            sum += *p;

    To simplify the loop, we can replace &a[0] by a and &a[N] by a+N:

        for (p = a; p < a+N; p++)
            sum += *p;

    Although an array name can be used as a pointer, it's not possible to assign it a new value.
    Attempting to make it point elsewhere is an error:

        while (*a != 0)
            a++;                ### WRONG ###

    This is at no great loss; we can always copy a into a pointer variable, then change the
    pointer variable:

        p = a;
        while (*p != 0)
            p++;

*/


// Program that reverses a series of numbers (pointer version)

#include <stdio.h>

#define N 10

int reverse3(void)
{
    int a[N], *p;

    printf("Enter %d number: ", N);
    for (p =a; p < a+N; p++){
        scanf("%d", p);
    }

    printf("In reverse order:");
    for (p = a+N-1; p >= a; p--){
        printf(" %d", *p);
    }
    printf("\n");

    return 0;
}

/*
    In the original program, an integer variable i kept track of the current position within
    the array. The new version replaces i with p, a pointer variable. The numbers are still
    stored in an array, we're simply using a different technique to keep track of where we are
    in the array.


    When passed to a function, an array name is always treated as a pointer. Consider the
    following function, which returns the largest element in an array of integers:

        int find_largest(int a[], int n)
        {
            int i, max;

            max = a[0];
            for (i = 1; i < n; i++){
                if (a[i] > max)
                    max = a[i]
            return max;
        }

    Suppose that we call find_largest as follows:

        largest = find_largest(b, N);

    This call causes a pointer to the first element of b to be assigned to a: the array itself
    isn't copied.

    The fact that an array argument is treated as a pointer has some important consequences:

            # When an ordinary variable is passed to a function, its value is copied; any
              changes to the corresponding parameter don't affect the variable, In contrast,
              an array used as an argument isn't protected against change, since no copy is
              made of the array itself. For example, in the following function modifies an
              array by storing zero into each of its elements:

                    void store_zeros(int a[], int n)
                    {
                        int i;

                        for (i = 0; i < n; i++)
                            a[i] = 0;
                    }

              To indicate that an array parameter won't be changed, we can include the word
              const in its declaration:

                    int find_largest(const int a[], int n)
                    {
                        ...
                    }

              If const is present, the compiler will check that no assignment to an element
              of a appears in the body of find_largest.


            # The time required to pass an array to a function doesn't depend on the size of
              the array. There's no penalty for passing a large array, since no copy of the
              array is made.

            # An array parameter can be declared as a pointer if desired. For example,
              find_largest could be defined as follows:

                    int find_largest(int *a, int n)
                    {
                        ...
                    }

              Declaring a to be a pointer is equivalent to declaring it be an array; the
              compiler treats the declarations as though they were identical.

    Although declaring a parameter to be an array is the same as declaring it to be
    a pointer, the same isn't true for a variable. The declaration

        int a[10];

    causes the compiler to set aside space for 10 integers. In contrast, the
    declaration

        int *a;

    causes the compiler to allocate space for pointer variable. In the latter case, a
    is not an array; attempting to use it as an array can have disastrous results.
    For example, the assignment

        *a = 0;  ### WRONG ###

    will store 0 to where a is pointing. Since we don't know where a is pointing, the
    effect on the program is undefined.

            # A function with an array parameter can be passed an array "slice" - a sequence
              of consecutive elements. Suppose that we want find_largest to locate the
              largest element in some portion of an array b, sat element b[5], ..., b[14].
              When we call find_largest, we'll pass the address of b[5] and the number 10,
              indicating that we want find_largest to examine 10 array elements, starting
              at b[5]:

                    largest = find_largest(&b[5], 10);



    If we can use an array name as a pointer, c will allows us to subscript a pointer as though
    it were an array name.
    For example:

        #define N 10
        ...
        int a[N], i, sum = 0, *p = a;
        ...
        for (i = 0; i < N; i++)
            sum += p[i];

    The compiler treats p[i] as *(p+i), which is a legal use of pointer arithmetic.



    Pointers can also point to elements of a multidimensional array.

    For simplicity, we'll stick to two-dimensional arrays.

    C stores two-dimensional arrays in row-major order; in other words, the elements of row 0
    come first, followed by the elements of row 1, etc.

    We can take advantage of this layout when working with pointers. If we make a pointer p to
    the first element in a two-dimensional array (the element in row 0, column 0), we can visit
    every element by incrementing p repeatedly.

    For example, let's look at the problem of initializing all elements of a two-dimensional
    array to zero. Suppose that the array has been declared as follows:

        int a[NUM_ROWS][NUM_COLS];

    The obvious technique would be to use nested for loops:

        int row, col;
        ...
        for (row = 0; row < NUM_ROWS; row++)
            for (col = 0; col < NUM_COLS; col++)
                a[row][col] = 0;

    But if we view a as a one-dimensional array of integers (which is how it's stores), we can
    replace the pair of loops by a single loop:

        int *p;
        ...
        for (p = &a[0][0]; p <= &a[NUM_ROWS-1][NUM_COLS-1]; p++)
            *p = 0;

    The loop begins by pointing at a[0][0]. Successive increments of p make it point to a[0][1],
    a[0][2], a[0][3], and so on. When p reaches a[0][NUM_COLS-1] (the last element in row 0),
    incrementing it again makes p point to a[1][0]. The process continues until p goes past
    a[NUM_ROWS-1][NUM_COLS-1], the last element in the array.

    With modern compilers, there's little or no speed advantage to doing it this way.


    With processing one row of a two-dimensional array, we have the option of using a pointer
    variable p. To visit the elements of row i, we'd initialize p to point to element 0 in row
    i in the array a:

        p = &a[i][0];

    or

        p = &a[i];

    since, for any two-dimensional array a, the expression a[i] is a pointer to the first element
    in row i. We'll use this simplification in the following loop, which clears row i of the
    array i:

        int a[NUM_ROWS][NUM_COLS], *p, i;
        ...
        for (p = a[i]; p < a[i] + NUM_COLS; p++)
            *P = 0;

    Since a[i] is a pointer to row i of the array a, we can pass a[i] to a function that's
    expecting a one-dimensional array as its argument. So, we could use one of our previous
    functions like find_largest to find the largest element in row i of a two-dimensional
    array a:

        largest = find_largest(a[i], NUM_COLS);


    Processing the elements of a two-dimensional array isn't as easy, because arrays are stored
    by row, not column. Here's a loop that clears column i of array a:

        int a[NUM_ROWS][NUM_COLS], (*p)[NUM_COLS], i;
        ...
        for (p = &a[0]; p < &a[NUM_ROWS]; p++)
            (*p)[i] = 0;

    p has been declared to be a pointer to an array of length NUM_COLS whose elements are integers.
    In (*p)[NUM_COLS] brackets are required; as without them, the compiler will treat p as an
    array of pointers instead of a pointer to an array. The braces around (*p)[i] are essential,
    because the compiler would interpret *p[i] as *(p[i]).


    The name of a multidimensional array can be used as a pointer. Some care is required, though.
    Consider the following array:

        int a[NUM_ROWS]{NUM_COLS];

    a is not a pointer to a[0][0]; instead, it's a pointer to a[0]. This makes more sense if we
    look at it from the standpoint of c, which regards a not as a two-dimensional array but as
    a one-dimensional array whose elements are one-dimensional arrays. When used as a pointer,
    a has type int (*)[NUM_COLS] (pointer to an integer array of length NUM_COLS).

    Knowing that a points to a[0] is useful for simplifying loops that process the elements of a
    two-dimensional array. For example, instead of writing

        for (p = &a[0]; p < &a[NUM_ROWS]; p++)
            (*p)[i] = 0;

    to clear column i of the array a, we can write

    for (p = a; p < a+NUM_ROWS; p++)
        (*p)[i] = 0;

    This is useful if we want to "trick" a function into thinking a multidimensional array is
    really one-dimensional. For example, consider how we might use find_largest to find the
    largest element in a. As the first argument to find_largest, let's try passing a (the address
    of the array); as the second, we'll pass NUM_ROWS * NUM_COLS (the total number of element in
    a):

        largest = find_largest(a, NUM_ROWS * NUM_COLS);        ### WRONG ###

    Unfortunately, the compiler will object to this statement, because the type of a is int
    (*)[NUM_COLS] but find_largest is expecting an argument of type int *. The correct call is

        largest = find_largest(a[0], NUM_ROWS * NUM_COLS);

    a[0] points to element 0 in row 0, and it has type int *(after conversion by the compiler),
    so the latter call will work correctly.


    Pointers are allowed to point to elements of variable-length arrays (VLAs), a feature of c99.
    An ordinary pointer variable would be used to point to an element of a one-dimensional
    VLA:

        void f(int n)
        {
            int a[n], *p;
            p = a;
            ...
        }

    When the VLA has more than one dimension, the type of the pointer depends on the length of
    each dimension except the first. A two-dimensional case:

        void f(int m, int n)
        {
            int a[m][n], (*p)[n];
            p = a;
            ...
        }

    Since the type of p depends on n, which isn't constant, p is said to have a variability
    modified type.

    Note that the validity of an assignment such as p = a can't always be determined by the
    compiler. For example, the following code will compile but is correct only if m and n
    are equal:

        int a[n][m], (*p)[m];
        p = a;

    If m!=m, any subsequent use of p will cause undefined behaviour.

    Variably modified types are subject to certain restrictions, just as VLAs are. The most
    important restriction is that the declaration of variably modified type must be inside the
    body of a function or in a function prototype.

    Pointer arithmetic works with VLAs just as it does for ordinary arrays. Returning to the
    example that clears a single column of a two-dimensional array a, let's declare a as a VLA
    this time:

        int a[m][n];

    A pointer capable of pointing to a row of a would be declared as follows:

        int (*P)[n];

    The loop that clears column i is almost identical to the one we used:

        for (p = a; p < a+m; p++)
            (*p)[i] = 0;

*/
