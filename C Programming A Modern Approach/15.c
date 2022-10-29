#include <stdio.h>

/*
    Most c programs require more than one file: source files and header files.

    Source files contain definitions of functions and external variables.

    Header files contain information to be shared among source files.

    Source files have extension .c. One of the source files must contain a function called main, which is the starting point
    of the program.

    Splitting a program across multiple source files has significant advantages:

        # Grouping related functions and variables into a single file helps clarify the structure of the program.

        # Each source file can be compiled separately - saves a lot of time if program is large and frequently changed.

        # Functions are more easily reused in other programs when in separate source files.


    The #include directive is used to include other source files.

    It has two forms:

        Used for header files that belong to C's own library:

            #include <filename>

        The second is used for all other header files, including any we write:

            #include "filename"


    The Difference between the two has to do with how the compiler locates the header file.
    The rules that most compilers follow are:

        #include <filename>:
                            Search the directory (or directories) in which system header files reside.

        #include "filename":
                            Search the current directory, then search the directory (or directories) in which
                            the system header files reside.

    ### Don't use <> when naming header files you have written ###

    For portability, it isn't best to specify the drive and/or path information, just the file name.


    the #include directive has a third form:

        #include tokens

    where tokens is any sequence of preprocessing tokens. The preprocessor will scan the tokens and replace any
    macros it finds. After replacement, the resulting directive must match appearance to one of the first two forms.
    The advantage of this kind is that the file name can be defined by a macro rather than being "hard-coded" into
    the directive itself, for example:

        #if defined(IA32)
            #define CPU_FILE "ia32.h"
        #elif defined(IA64)
            #define CPU_FILE "ia64.h"
        #elif defined(AMD4)
            #define CPU_FILE "amd64.h"
        #endif // defined

        #include CPU_FILE

    Most large programs contain macro definitions and type definitions that need to be shared by several source files.
    These definitions should go in the header files.

    Let's say we have a header file named "boolean.h", and it has inside it:

        #define TRUE 1
        #define False 0
        typedef int bool;

    And any source file that requires these macros will simply contain the line

        #include "boolean.h"

    Doing this have obvious benefits. First, we don't have to copy the definitions into the source files when they're
    needed. Second, The program becomes easier to modify. Changing the definition of a macro or type requires only that
    we edit a single header file; we don't have to modify many source files in which the macro or type is used. Thirdly,
    we don't have to worry about inconsistencies caused by source files containing different definitions of the same macro
    or type.

    Suppose that a source file contains a call of a function f that is defined in another file, "foo.c". Calling f without
    declaring it first is very risky. Without a prototype to rely on, the compiler is forced to assume that f's return type
    is int and that the number of parameters matches the number of arguments in the call of f. If the assumptions are wrong,
    the program probably won't work and you'll be clueless as to why. (For this reason, C99 prohibits calling a function for
    which the compiler hasn't seen a declaration or definition).

    ### When calling a function that's defined in another file, always make sure that the compiler has seen a prototype for
    it prior to the call ###

    always include the header file in the source file containing the definition of the function. Failure to do so can cause
    hard-to-find bugs, since calls of the function elsewhere in the program may not match it's definition.



    We can also share variables across programs. But up till now, we haven't needed to distinguish between a variable's
    declaration and it's definition. For example:

        int i;      ## Declares i and defines it ##

    This declares it as a variable of type int, and defines it by causing the compiler to set aside space for i. To declare i
    without defining it, we must put the keyword extern at the beginning of its declaration:

        extern int i; ## Declares i without defining it ##

    extern informs the compiler that i is defined elsewhere in the program, so there is no need to allocate space for it.

    extern works with variables of all types. When we use it in the declaration of an array, we can omit the length of the array:

        extern int a[];

    Since the compiler doesn't allocate space for a this time, there's no need for it to know a's length.

    To share a variable i among several source files, we first put a definition of i in one file:

        int i;

    If i needs to be initialized, the initializer would go here. When this file is compiled, the compiler will allocate storage for
    i. The other files will contain the declarations of i:

        extern int i;

    Declaring i in each file, it becomes possible to access and/or modify i with those files. Because of the word extern, however,
    the compiler doesn't allocate additional storage for i each time one of the files is compiled.

    When declarations of the same variable appear in different files, the compiler can't check that the declarations match the
    variable's definition.

    To avoid this, declarations of shared variables are usually put in header files. A source file that needs access to a particular
    variable can then include the appropriate header file. In addition, each header file that contains a variable declaration is
    included in the source file that contains the variable's definition, enabling the compiler to check that the two match.



    A header itself may include the #include directive. We can use it to include typedefs and definitions from other header files,
    let's say when we have a function prototype in a header file of a made up return type, then we have to include the header file
    that defines that typedef.

    Including the same header file twice in a source file causes it to be compiled twice and it could cause a compilation error.
    As a precautionary measure we want to protect against this.

    This is done by enclosing the contents of the file in an #ifndef - #endif pair, for example:

        #ifndef BOOLEAN_H
        #define BOOLEAN_H

        #define TRUE 1
        #define FALSE 0
        typedef int Bool;

        #endif // BOOLEAN_H


    When this file is included the first time, the BOOLEAN_H macro won't be defined, so the preprocessor will allow the lines
    in the #ifndef - #endif pair to stay. Else, the lines between the #ifndef - #endif pair will not stay.


    The #error directive is often put in a header file to check for conditions under which the header file shouldn't be included.
    For example, suppose that a header file uses a feature that didn't exist prior to the original C89 standard. To prevent the
    header file from being used with older, nonstandard compilers, it could contain an #ifndef directive that tests for the
    existence of the __STDC__ macro:

        #ifndef __STDC__
        #error This header requires a Standard c compiler
        #endif // __STDC__


    /// SKIPPED SECTION 15.3 ///


    When using a multiple-file program, the basic process is the same:

        # Compiling. Each source file in the program must be compiled separately. (Header files don't need to be compiled, they're
                     compiled automatically whenever a source file that includes it is compiled.) For each source file, the
                     compiler generates a file containing the object code. These files - known as object files - have the extension
                     .o in unix and .obj in windows.

          # Linking. The linker combines the object files created along with the code for library functions - to produce an
                     executable file. The linker is also responsible for resolving external references left behind by the
                     compiler. (An external reference occurs when a function in one file calls a function defined in another file
                     or accesses a variable defined in another file.)

    Most compilers allow for the building of a program in a single step. Using the GCC compilers:

        gcc -o executable_name source_1 source_2 ...


    Some errors that can't be detected during compilation will be found during linking. In particular, if the definition of a
    a function or variable is missing from a program. The linker will be unable to resolve external references to it, causing an
    error message such as "undefined symbol" or "undefined reference."

    These errors detected by the linker are easy to fix. The most common causes for these errors are:

        # Misspellings. If the name of a variable or function is misspelled, the linker will report it as missing.

        # Missing files. If the linker can't find the functions that are in a file, it may not know about the file. Check the makefile
                         or project file to make sure the necessary file is included.

        # Missing libraries. The linker may not be able to find all library functions used in the program. For example, many unix
                             programs that are use the <math.h> header. Simply including the header in a program may not be enough;
                             many versions of unix require that the -lm option be specified when the program is linked, causing the
                             linker to search a system file that contains compiled versions of the <math.h> functions. Failing to use
                             this option may cause "undefined reference" messages during linking.


