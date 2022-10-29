
/*
    C's data structures are normally fixed in size. Fixed-size data structures can be a problem, since we're forced to choose their
    sizes when writing a program; we can't change their sizes without modifying the program and compiling again.

    C supports dynamic storage allocation: the ability to allocate storage during program execution. Using dynamic storage allocation,
    we can design data structures that grow (and shrink) as needed. It works with all data types.

    To allocate storage dynamically, we'll need to call one of the three memory allocation functions declared in the <stdlib.h> header:

        # malloc - Allocates a block of memory but doesn't initialise it.

        # calloc - Allocates a block of memory and clears it.

        # realloc - Resizes a previously allocated block of memory.

    Of the three, malloc is the most used. It's more efficient than calloc, since it doesn't have to clear the memory block that it
    allocates.

    void * is a generic pointer - just a memory address.

    When a memory allocation function is called, there's always a possibility that it won't be able to locate a block of memory large
    enough to satisfy our request. If this should happen, the function will return a null pointer - a pointer to nothing.

    ####    Always check the return value of any memory allocation function    ####

    The null pointer is represented by a macro named NULL, so we can test malloc's return value in the following way:

        p = malloc(10000);
        if (p = NULL) {
            ### allocation failed; take the appropriate action ###
        }

    The NULL macro is defined in six headers: <locale.h>, <stddef.h>, <stdio.h>, <stdlib.h>, <string.h>, and <time.h>. (The C99 header
    <wchar.h> also defines NULL). As long as one of these headers is included, the compiler recognises NULL. (OFC any program using
    memory allocation functions will include <stdlib.h>).

    If C, pointers test true or false in the same way as numbers. All non-null pointers test true; only null pointers are false. Thus,
    instead of writing

        if (p == NULL) ...

    we could write

        if (!p) ...

    and instead of writing

        if (p != NULL) ...

    we could write

        if (p) ...

    Dynamic storage allocation is often used with strings. Strings are stored in character arrays, and it can be hard to anticipate
    how long these arrays need to be. By allocating storage dynamically, we can postpone the decision until the program is running.

    The malloc function has the following prototype:

        void *malloc(size_t size);

    malloc allocates a block of size bytes and returns a pointer to it.

    Using malloc to allocate memory for a string is easy, because C guarantees that a char value requires exactly one byte of storage
    (sizeof(char) is 1). To allocate space for a string of n characters, we'd write

        p = malloc(n + 1);

    where p is a char * variable. The generic pointer that malloc returns will be converted to char * when the assignment is
    performed; no cast is necessary. But we are able to if we desire:

        p = (char *) malloc(n + 1);

    ### When using malloc to allocate space for a string, don't forget to include room for the null character ###

    Memory allocation using malloc isn't cleared or initialized in any way, so p will always point to an uninitialized array of
    n+1 characters.

    Calling strcpy is one way of initializing this array.


    Dynamic storage allocation makes it possible to write functions that return a pointer to a "new" string - a string that didn't
    exist before the function was called.

    Suppose we write a function that concatenates two strings without changing either of them:

        char *concat(const char *s1, const char *s2)
        {
            char *result;

            result = malloc(strlen(s1) + strlen(s2) + 1);
            if (result == NULL){
                printf("Error: malloc failed in concat\n");
                exit(EXIT_FAILURE);
            }
            strcpy(result, s1);
            strcat(result, s2);
            return result;
        }

    If we call:

        p = concat("abc", "def");

    After the call, p will point to the string "abcdef". Which is stored in a dynamically allocated array. The array is seven
    characters long, including the null character at the end.

    Functions, such as above, that dynamically allocate storage must be used with care. When the string that concat returns is no
    longer needed, we'll want to call the free function to release the space that the string occupies. If we don't, the program may
    eventually run out of memory.

    We can also dynamically allocate arrays. Although malloc can be used to allocate space for an array, the calloc function is
    sometimes used instead, since it initializes the memory that it allocates. The realloc function allows us to make an array
    "grow" or "shrink" as desired.

    We use malloc to allocate space for an array in much the same way we used it to allocate space for a string. The primary
    difference is that the elements of an arbitrary array won't necessarily be one byte long, as they are in a string. As a result,
    we'll need to use the sizeof operator to calculate the amount of space required for each element.

    Suppose, we're writing a program that needs an array of n integers, where n is to be computed during the execution of the
    program. We'll first declare a pointer variable:

        int *a;

    Once the value of n is known, we'll have the program call malloc to allocate space for the array:

        a = malloc(n * sizeof(int));

    #### Always use sizeof when calculating how much space is needed for an array ####

    Once it points to a dynamically allocated block of memory, we can ignore the fact that a is a pointer and use it instead as an
    array name.

    Although malloc can be used to allocate memory for an array, C provides an alternative - the calloc function. calloc has the
    following function prototype in <stdlib.h>:

        void *callod(size_t nmemb, size_t size);

    calloc allocates space for an array with nmemb elements, each of which is size bytes long; it returns a null pointer if the
    requested space isn't available. After allocating the memory, calloc initializes it by setting all bits to 0. For example, the
    following call allocates space for an array of n integers, which are all guaranteed to be 0 initially:

        a = calloc(n, sizeof(int));

    Since calloc clears the memory that it allocates but malloc doesn't, we may occasionally want to use calloc to allocate space for
    an object rather than an array. By calling calloc with 1 as its first argument, we can allocate space for a data item of any type:

        struct pont { int x, y; } *p;

        p = calloc(1, sizeof(struct point));

    After this statement has been executed, p will point to a structure whose x and y members have been set to 0.

    Once we've already allocated memory for an array, we may later find that it's too large or too small. The realloc function
    can resize the array to better suit our needs. realloc has the following prototype which appears in <stdlib.h>:

        void *realloc(void *ptr, size_t size);

    When realloc is called, ptr must point to a memory block obtained by the previous call of malloc, calloc, or malloc. The size
    parameter represents the new size of the block, which may be larger of smaller than the original size. Although realloc doesn't
    require that ptr point to memory that's being used as an array, in practice it usually does.

    ### Be sure that a pointer passed to realloc came from a previous call of malloc, calloc, or realloc. If not, calling realloc
        causes undefined behaviour. ###

    The C standard's rules for realloc are:

        # When it expands a memory block, realloc doesn't initialize the bytes that are added to the block.

        # If realloc can't enlarge the memory block as requested, it returns a null pointer; the data in the old memory block is
          unchanged.

        # If realloc is called with a null pointer as its first argument, it behaves like malloc.

        # If realloc is called with 0 as its second argument, it frees the memory block.

    When reducing or expand the size of a memory block, realloc should shrink or enlarge the block without moving it. If realloc
    cannot enlarge the block, it will allocate a new block elsewhere, then copy the contents of the old block into the new one.

    ### Once realloc has returned, be sure to update all pointers to the memory block, since it's possible that realloc has moved
        the block elsewhere ###



*/



