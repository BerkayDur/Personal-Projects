#include <stdio.h>

/*
    In modern computers, main memory is divided into bytes, with each byte able to store
    eight bits of information (a bit is a 1 or 0 in binary). Each byte has a unique address
    to distinguish it from the other bytes in storage. If there are n bytes in memory, we
    can think of addresses as numbers that range from 0 to n-1. Each variable in a program
    occupies one or more bytes of memory; the address of the first byte is said to be
    the address of the variable. If the variable i occupies the bytes at addresses 2000 and
    2001, the i's address is 2000.

    Although addresses are represented by numbers, their range of values may differ from that
    of integers, so we can't necessarily store them in ordinary integer variables. We can,
    however, store the in special pointer variables. When we store the address of a variable i
    in the pointer variable p, we say that p points to i. So, a pointer is just an address, and
    a pointer variable is just a variable that can store an address.

    Pointers are declared in a similar way to variables:

        type-name *pointer-name;

    e.g.
        int *p;

    This declaration states that p is a pointer variable capable of pointing to objects of
    type int. Pointer variables can appear in declarations along with other variables:

        int i, j, a[10], b[20], *p, *q;

    In this example, both p and q are pointers to integer objects.

    Pointers can only point to objects of the declared type of the pointer (the reference type).

    The reference type can be anything. In fact, a pointer variable can even point to another
    pointer.


    There are certain operators designed specifically for use with pointers. To find the
    address of a variable, we use the & (address) operator. If x is a variable, the &x is the
    address of x in memory. To gain access to the object that a pointer points to, we use the
    * (indirection) operator. If p is a pointer, *p represents the object to which p currently
    points.

    Declaring a pointer variable sets aside space for a pointer but doesn't make it point to an
    object:

        int *p;     # points nowhere in particular #

    P must be initialized before use. One way to initialize a pointer variable is to assign it
    the address of some variable - or, more generally, lvalue - using the & operator:

        int i, *p;
        ...
        p = &i;

    By assigning the address of i to the variable p, this statement makes p point to i.
    We can also initialize a pointer variable when we declare it:

        int i;
        int *p = &i;


    Once a pointer variable points to an object, we can use the * (indirection) operator to
    access what's stored in the object. If p points to i, for example, we can print the
    value of i as follows:

        printf("%d\n", *p);

    printf will display the value of i, not the address of i.

    Applying * to the pointer, will take us back to the original value:

            j = *&i;        <==>        j = i;

    As long as p points to i, *p is an alias for i. Not only does *p have the same value as i,
    but changing the value of *p also changes the value of i. (*p is an lvalue, so assignment
    to it is legal).

    e.g.
        p = &i;

                        # p points to i #

        i = 1;

                        # p points to i, which now has a value of 1 #

        printf("%d\n", i);              # prints 1 #
        printf("%d\n", *p);             # prints 1 #

        *p = 2;

                        # p points to i, which now has a value of 2 #

        printf("%d\n", i);              # prints 2 #
        printf("%d\n", *p);             # prints 2 #



    Never apply the indirection operator to an uninitialized pointer variable. If a pointer
    variable p hasn't been initialized, attempting to use the value of p in any way causes
    undefined behaviour.
    e.g.
        int *p;
        printf("%d", *p);              ## WRONG ##

    Assigning a value to *p is dangerous. If p happens to contain a valid memory address, the
    following assignment will attempt to modify the data stored at that address:

        int *p;
        *p = 1;                        ## WRONG ##


    In c, we can use the assignment operator to copy pointers, provided that they have the
    same type. Suppose that i, j, p, and q have been declared as follows:

        int i, j, *p, *q;

    The statement

        p = &i;

    is an example of pointer assignment; the address of i is copied into p. Here's another
    example of pointer assignment:

        q = p;

    This statement copies the contents of p (the address of i) into q, in effect making
    q point to the same place as p:

                        # both p and q point to i #

    As both p and q point to i, we can change i by assigning a new value to either
    *p or *q:

        *p = 1;

                        # both p and q point to i, which now has the value 1 #

        *q = 2;

                        # both p and q point to i, which now has the value 2 #


    Any number of pointer variables may point to the same object.

    Be careful not to confuse:

        q = p;

    with

        *q = *p;

    The first statement is a pointer assignment; the second isn't, as the following example
    shows:

        p = &i;
        q = &j;
        i = 1;

                        # p points to i, which now has value 1 #
                        # q points to j #

        *q = *p;

                        # p points to i, which has value 1 #
                        # q points to j, which now has value 1 #


    The assignment *q = *p copies the value that points to (the value of i) into the object
    that q points to (the variable j).



    When we supply a variable as an argument in a function call, it is protected against
    change, because c passes arguments by reference. So, to modify this variable, we can use
    a pointer as the argument.

    e.g.

        void decompose(double x, long *int_part, double *frac_part)
        {
            *int_part = (long) x;
            *frac_part = x - * int_part;
        }

    The prototype for decompose could be either:

        void decompose(double x, long *int_part, double *frac_part);

    or
        void decompose(double x, long *, double *);

    We'll call decompose in the following way:

        decompose(3.14159, &i, &d);

    Because of the & operator in front of the i and d, the arguments to decompose are pointers
    to i and d, not values of i and d. When decompose is called, the value 3.14159 is copied
    into x, a pointer to i is stored in int_part, and a pointer to d is stored in frac_part:

        # x has value 3.14159 #
        # int_part points to i #
        # frac_part points to d #

    The first assignment in the body of decompose converts the value of x to type long and
    stores it in the object pointed to by the int_part. Since int_part points to i, the
    assignment puts the value 3 in i:

        # x has value 3.14159 #
        # int_part points to i, which now has the value 3 #
        # frac_part points to d #

    The second assignment fetches the value the int_part points to (the value of i), which is
    3. This value is converted to type double and subtracted from x, giving .14159, which is
    then stored in the object that frac_part points to:

        # x has value 3.14159 #
        # int_part points to i, which has the value 3 #
        # frac_part points to d, which now has the value .14159 #

    When decompose return, i and d will have the values 3 and .14159, just as we originally
    wanted.

    We've used pointers before in a scanf function:

        int i;
        ...
        scanf("%d", &i);

    We just used the & operator in front of i so that scanf is given a pointer to i; that
    pointer tells scanf where to put the value that it reads. Without the &, scanf would be
    supplied with the value of i.

    Although scanf's arguments must be pointers, it's not always true that every argument needs
    the & operator. In the following example, scanf is passed a pointer variable:

        int i, *p;
        ...
        p = &i;
        scanf("%d", p);

    Since p contains the address of i, scanf will read an integer and store it in i. Using the
    & operator in the call would be wrong:

        scanf("%d", &p);

    scanf would read an integer and store it in p instead of i.


    If a function expects a pointer and we do not provide one, the program will change an
    unknown place in memory instead.
*/


// Program that finds the largest and smallest elements in an array

#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int maxmin(void)
{
    int b[N], i, big, small;

    printf("Enter %d integers: ", N);
    for (i=0; i<N; i++){
        scanf("%d", &b[i]);
    }
    max_min(b, N, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
    int i;

    *max = *min = a[0];
    for (i=1; i<n; i++){
        if (a[i]>*max){
            *max=a[i];
        }
        else if (a[i]<*min){
            *min=a[i];
        }
    }
}


/*
    When we call a function and pass it a pointer to a variable, we normally assume that the
    function will modify the variable (otherwise, why would the function require a pointer).
    For example, if we see a statement like:

        f(&x);

    We'd probably expect f to change the value of x. It's possible, though, that f merely
    needs to examine the value of x, not change it. The reason for the pointer might be
    efficiency: passing the value of a variable can waste time and space if the variable
    requires a large amount of storage.

    So, we can use the word const to document that a function won't change an object whose
    address is passed to the function. const goes in the parameter's declaration, just
    before the specification of its type:

        void f(const int *p)
        {
            *p = 0;            # WRONG #
        }

    The use of const indicates that p is a pointer to a "constant integer." Attempting to
    modify *p is an error that the compiler will detect.


    We can also write functions that return pointers. Such functions are relatively common
    (see chapter 13).

    The following function, when given pointers to two integers, returns a pointer to
    whichever integer is larger:

        int *max(int *a, int *b)
        {
            if (*a > *b){
                return a;
            }
            else {
                return b;
            }
        }

    When we call max, we'll pass pointers to two int variables and store the result in a
    pointer variable:

        int *p, i, j:
        ...
        p = max(&i, &j);

    During the call of max, *a is an alias for i, while *b is an alias for j. If i has a
    larger value than j, max returns the address of i; otherwise, it returns the address of j.
    After the call, p points to either i or j.

    Although the max function returns one of the pointers passed to it as an argument, that's
    not the only possibility. A function could also return a pointer to an external variable
    or to a local variable that's been declared static.

    Never return a pointer to an automatic local variable:

        int *f(void)
        {
            int i;
            ...
            return &i;
        }

    The variable i doesn't exist once f returns, so the pointer to it will be invalid.
    Some compilers will issue a warning.


    use the conversion specification %p to print address of a variable that has a pointer.

*/
