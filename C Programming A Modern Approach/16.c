

/*
    3 extra types (on top of arrays) are:

        # Structure. A collection of values (members), possibly of different types.

        # Union. Similar to a structure but its members share the same storage; as a result, a union can store one member at a time,
                 not all members simultaneously.

        # Enumeration. An integer type whose values are named by the programmer.

    In a structure, its elements (members) aren't required to have the same type. And members of the structure have names; to select
    a particular member, we specify its name, not its position.

    Declaring a structure looks like:

        struct {
            data-type-2 member-1;
            data-type-1 member-2;
            ....

        } variable-1, variable-2 ...;

    so we specify a member name and its data type. But we also declare the variables which are of this type.

    Members of a structure are stored in memory in the order in which they are declared. There are no gaps in memory between members.

    each structure represents a new scope. (In c, we say that each structure has a separate name space for its members).

    A structure variable may we initialized at the same time it's declared. For example:

        struct{
            int number;
            char name[NAME_LEN+1];
            int on_hand;
        } part1 = {528, "Disk drive", 10},
          part2 = {914, "Printer cable", 5};

    The values in the initializer must appear in the same order as the members of the structure. An initializer can also have fewer
    member than the structure it's initializing; as with arrays, any "leftover" members are given 0 as their initial value.

    We can also use designated initializers:

        part1 = {.number=528, .name="Disk drive", .on_hand=10};

    The combination of the period and the member name is called a designator (different form to that of arrays). Designated
    initializers have the advantage of that their order in the designation doesn't matter.

    This initialization also works:

        part1 = {.number=528, "Disk drive", .on_hand=10};

    This is as the compiler assumes that it initializes the member that follows number in the structure.

    To access a member in a structure we write:

        variable_name.member

    For example,

        printf("Part number: %d\n", part1.number);

    The members of a structure are lvalues, so they can appear on the left side of an assignment. The period is an actual c operator.
    It has the same precedence as the postfix ++ and -- operators, so it takes precedence over nearly all other operators.

    Another major structure operation is assignment:

        variable_2 = variable_1;

    This copies the member values of variable_1 into variable_2. Which is very useful as the equality operator doesn't work with
    array, so we can embed an array within a structure and copy its value to another structure variable, copying the array. This
    is called creating "dummy" structures to enclose arrays that will be copied later. e.g.

        struct {int a[10];} a1,a2;

        a1 = a2;

    This is a legal operation.

    The = operator can only be used with structures of compatible types. Two structures declared at the same time are compatible.

    There are no more operations on entire structures. In particular, we can't use the == and != operators to test whether two
    structures are equal or not.

    If two different structure variables are exactly the same but the structures are declared at different times, the compiler
    doesn't allow them to operate on one another. This is as the compiler says these variables are of incompatible data types.

    To avoid these difficulties above, C provides two ways to name structures: We can either declare a "structure tag" or use
    typedef to define a type name.

        A structure tag is a name used to identify a particular kind of structure. For example, this structure is called part:

            struct part{
            int number;
            char name[NAME_LEN+1];
            int on_hand;
            };

        There must now be a semicolon at the end of the declaration to terminate it.

        Once we've created the 'part' tag, we can use it to declare variables. For example,

            struct part part1, part2;

        Unfortunately, we can't abbreviate this declaration by drop the 'struct'. 'part' isn't a type name; without the word
        'struct', it is meaningless.

        ### Structure tags are meaningless without the 'struct' keyword ###

        So we could give one of structure variables the same name as the structure tag. We can also declare a structure tag with
        the declaration of structure variables:

            struct part{
            int number;
            char name[NAME_LEN+1];
            int on_hand;
            } part1, part2;

        All structures variables declared to have the same structure tag, are compatible with one another.




        The alternative to declaring a structure tag, we can use typedef to define a genuine type name. For example,

            typedef struct{
            int number;
            char name[NAME_LEN+1];
            int on_hand;
            } part;

        Note, that the name of the type, 'part', must come at the end, not after the word 'struct'. This allows us to use part in
        the same way as built-in type. For example, we might use it to declare variables:

            part part1, part2;

        since 'part' is a 'typedef' name, we're not allowed to write the 'struct part'. All 'part' variables, regardless of where
        they're declared, are compatible.

    When it comes to name a structure, we can choose either method. However, declaring a structure tag is mandatory when the
    structure is to be used in a linked list.


    Functions may have structures as arguments and return values. For example:

        struct part build_part(int number, const char *name, int on_hand)
        {
            struct part p;

            p.number = number;
            strcpy(p.name, name);
            p.on_hand = on_hand;
            return p;
        }
    The functions parameters are allowed to have names that match the members of the structure, since the structure has its own
    name space. A call of this function might look like:

        part1 = build_part(528, "Disk drive", 10);

    Passing a structure to a function and returning a structure from a function both require making a copy of all members in the
    structure. As a result, these operations impose a fair amount of overhead on a program, especially if the structure is large.
    To avoid this overhead, it's sometimes advisable to pass a pointer to a structure instead of passing the structure itself.
    Similarly, we may have a function return a pointer to a structure instead of returning an actual structure.

    It's possible to initialize a structure variable inside a function to match another structure. For example:

        void f(struct part part1)
        {
            struct part part2 = part1;
            ...
        }

    C permits initializers of this kind, provided that the structure we're initializing has automatic storage duration (it's
    local to a function and hasn't been declared static). The initializer can be any expression of the proper type, including a
    function call that returns a structure.

    Compound literals are used to create unnamed arrays, usually for the purpose of passing the array to a function. A compound
    literal can also be used to create a structure "one the fly", without storing it in a variable. The resulting structure can
    be passed as a parameter, returned by a function, or assigned to a variable.

    For example, we can pass it into a function:

        print_part((atruct part) [528, "Disk drive", 10});

    A compound literal can be assigned to a variable:

        part1 = (struct part) {528, "Disk drive", 10};

    This statement resembles a declaration containing an initializer, but it's not the same - initializers can appear only in
    declarations, not in statements such as this one above.

    For a compound literal that represents a structure, the type name can be a structure name preceded by the word 'struct' or
    a 'typedef' name. A compound literal may contain designators, like a designated initializer:

        print_part((atruct part) [.on_hand = 10,
                                  .name = "Disk drive",
                                  .number = 528});

    Structures and arrays can be combined without restriction. Arrays may have structures as their elements, and structures may
    contain arrays and structures as members.

    Nested structures has a lot of uses. For example:

        struct person_name {
            char first[FIRST_NAME_LEN+1];
            char middle_initial;
            char last[LAST_NAME_LEN+1];
        };

    The larger structure is:

        struct student {
            struct person_name name;
            int id, age;
            char sex;
        } student1, student2;

    We can access one of the larger structure variables and access one of its deeper members by, for example:

        strcpy(student1.name.first, "Fred");

    An advantage of using this is that it allows for grouping of relevant data. For example, we can pass one argument in a function:

        display_name(student1.name);

    Likewise, copying the information from a one structure variable to another will only take a single assignment, for example:

        struct person_name new_name;
        ...
        atudent1.name=new_name;

    We are also able to store structures in an array. For example, this array of 'part' structures is capable of storing information
    about 100 parts:

        struct part inventory[100];

    To access one of the parts in the array, we'd use subscripting. To print the part stored in position i, for example, we write:

        print_part(inventory[i]);

    Accessing a member within a part structure requires a combination of subscripting and member selection. For example, to assign
    883 to the number member of 'inventory[i]'; we could write:

        inventory[i].number = 883;

    We could also access a single character in a part name by subscripting, followed by a selection, then subscripting the index
    we want to change:

        inventory[i].name[0] = '\n';

    Initializing an array of structures is done in the same way as initializing a multidimensional array. Each structure has its own
    brace-enclosed initialiser, the initializer for the array simply wraps another set of braces around the structure initialiser.

    One reason for initializing an array of structures is that we're planning to treat it as a database of information that won't
    change during program execution. For example, suppose we're working on a program that will need access to country codes used
    when making international telephone calls. First, we'll set up a structure that can store the name of a country along with its
    code:

        struct dialing_code {
            char *country;
            int code;
        };

    Take note that country is a pointer, not an array of characters. Next, we'll declare an array of these structures and initialise
    it to contain the codes for some of the world's most populous nations:

        const struct dialing_code country_codes[] =
            {{"Germany", 49}, {"France", 33},
             {"United Kingdom", 44}, {"Turkey", 90},
             {"United states", 1}, {"Japan", 81}};

    The inner braces around each structure value are optional (But its best to still use them).



###### SKIPPED PROGRAM HERE, ADD LATER ######


    A union consists of one or more members, possibly of different types, like a structure. However, the compiler allocates only
    enough space for the largest of the members, which overlay each other within this space. As a result, assigning a new value to
    one member alters the values of the other members as well.

    For example:

        union {
            int i;
            double d;
        } u;

    This declaration of a union is resemblant of a structure declaration:

        srruct {
            int i;
            double d;
        } s;

    Structures and unions only differ in one way: the members of a structure are stored at different addresses in memory, while
    members of a union are stored at the same address.

    So if s is stored at memory address 2000, i is stored at 2000 (-2003), and d is stored at 2004 (- 2011). But for the union
    u, if s is stored at memory address 3000, i is stored at 3000 (-3003), and d is stored at 3000 (-3007).

    So, in the structure s, i and d occupy different memory locations; the total size of s is 12 bytes. In the union, i and d
    overlap (i is really the first four bytes of d), so u occupies only 8 bytes. Also, i and d have the same address.

    Members of a union are accessed in the same way as members of a structure. For example, to store 82 in the i member of u:

        u,i = 82;

    To store the value 74.8 in the d member, we would write:

        u.d = 74.8;

    Since the compiler overlays storage for the members of a union, changing one member alters any value previously stored in any of
    the other members. Thus, if we store a value in 'u.d', any value previously stored in 'u.i' will be lost. Similarly, changing
    'u.i' corrupts 'u.d'. Because of this property, we can think of u as a place to store either i or d, but not both.

    The properties of unions are almost identical to the properties of structures. We can declare union tags and union types in the
    same way we declare structure tags and types. Like structures, unions can be copied using the = (equality) operator, passed to
    functions, and returned by functions.

    Unions can be initialized in a manner similar to structures. However, only the first member of a union can be given an initial
    value. For example:

        union {
            int i;
            double d;
        } u = {0};

    Designated initialisers may also be used with unions. A designated initialiser allows us to specify which member of the union
    should be initialised. For example:

        union {
            int i;
            double d;
        } u = {.d = 10.0};

    Only one member can be initialised, but it doesn't have to be the first one.

    One use of unions is to save space in structures. For example, suppose we're designing a structure to contain information about
    an item that's sold through a gift catalog. The catalog carries only 3 kinds of merchandise: books, mugs, and shirts. Each item
    has a stock number and a price, as well as other information that depends on the type:

        struct catalog_item {
            int stock_number;
            double price;
            int item_type;
            char title[TITLE_LEN+1];
            char author[AUTHOR_LEN+1];
            int num_pages;
            char design[DESOGM_LEN+1];
            int colors;
            int sizes;
        };

    The item_typw member would have one of the values BOOK, MUG, or SHIRT. The colors and sizes members would stores encoded
    combinations of colors and sizes.

    Although this structure is perfectly usable, it wastes space, since only part of the information in the structure is common to
    all items in the catalog. If an item a book, for example, there's no need to store design, colours, and sizes. By putting a
    union inside the catalog_item structure, we can reduce the space required by the structure. The members of the union will be
    structures, each containing the data that's needed for a particular kind of catalog item:

        struct catalog_item {
            int stock_number;
            double price;
            int item_type;
            union {
                struct {
                    char title[TITLE_LEN+1];
                    char author[AUTHOR_LEN+1];
                    int num_pages;
                } book;
                struct {
                    char design[DESOGM_LEN+1];
                } mug;
                struct {
                    char design[DESOGM_LEN+1];
                    int colors;
                    int sizes;
                } shirt;
            } item;
        };

    To print the book's title:

        printf("%s", c.item.book.title);

    Suppose we assign a value to one of the design members:

        strcpy(c.item.mug.design, "Cats");

    To design member in the other structure will be defined to have the same value:

        printf("%d", c.item.shirt.design);      ## Prints "Cats" ##

    Another application of unions is creating data structures that contain a mixture of data of different types. For example:

        typedef union {
            int i;
            double d;
        } Number;

    Next, create an array whose elements are Number values:

        Number number_array[1000];

    Each element of number_array is a Number union. A number union can store either an int value or a double value, making it
    possible to store a mixture of int and double values in number_array. For example, suppose we want element 0 of number_array to
    store 5, while element 1 store 8.395. The following assignments will have the desired effect:

        number_array[0].i = 5;
        number_array[1].d = 8395;

    The problem with unions is that there's no easy way to tell which member of a union was last changed and therefore has a
    meaningful value. To keep track of of this information, we can embed the union within a structure that has one other member:
    a "tag field" or "discriminant", whose purpose is to remind us what's currently stored in the union. For example, in the
    catalog_item structure earlier, item_type served this purpose. Let's convert the Number type into a structure with an embedded
    union:

        #define INT_KIND 0
        #define DOUBLE_KIND 1

        typedef struct {
            int kind;     ## tag field ##
            union {
                int i;
                double d;
            } u;
        } Number;

    Number has two members. kind and u. The value of kind will either be INT_KIND or DOUBLE_KIND.

    Each time we assign a value to a member of u. We'll also change kind to remind us which member of u be modified. For example:

        n.kind = INT_KIND;
        n.u.i = 82;

    So to print the value:

        void print_number (Number n)
        {
            if (n.kind == INT_KIND){
                printf("%d",n.u.i);
            }
            else {
                printf("%g",n.u.d);
            }
        }

    An enumerated type is a type whose values are listed ("enumerated") by the programmer, who must create a name (an enumeration
    constant) for each of the values. For example, the following enumerates the values (CLUBS, DIAMONDS, HEARTS, and SPADES) that
    can be assigned to the variables s1 and s2:

        enum {CLUBS, DIAMONDS, HEARTS, SPADES} s1, s2;

    The names of enumeration constants must be different form other identifiers declared in the enclosing scope. Enumeration
    constants are similar to constants created with the #define directive, but they're not equivalent. Enumeration constants are
    subject to C's scope rules: if an enumeration is declared inside a function, its constants won't be visible outside the function.

    There are two ways to name an enumeration:

        # By declaring a tag. For example:

            enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

          suit variables would be declared in the following way:

            enum suit s1, s2;

        # By using typedef to create a genuine type name, For example:

            typedef enum {CLUBS, DIAMONDS, HEARTS, SPADES} suit;
            suit s1, s2;

    C treats enumeration variables and constants as integers, By default, the compiler assigns the inters 0,1,2,... to the constants
    in a particular enumeration. For example above, CLUBS, DIAMONDS, HEARTS, and SPADES represent 0, 1, 2, and 3, respectively.
    We're free to choose different values for enumeration constants if we like. For example:

        enum suit {DIAMONDS = 2, CLUBS = 1, HEARTS = 3, SPADES = 4};

    As we can see above, the order doesn't matter. It's also legal for two or more enumeration constants to have the same value.

    When no value is specified for an enumeration constant, its value is one greater than the previous constant. (By default the
    first enumeration constant has the value 0).

    Since enumeration values are nothing but disguised integers, C allows us to mix them with ordinary integers. For example:

        int i;
        enum {CLUBS, DIAMONDS, HEARTS, SPADES} s;

        i = DIAMONDS;           ## i is now 1 ##
        s = 0;                  ## s is now 0 (CLUBS) ##
        s++;                    ## s is now 1 (DIAMONDS) ##
        i = s + 2;              ## i is now 3 ##

    The compiler treats s as a variable of some integer type: CLUBS, DIAMONDS, HEARTS, and SPADES are just names for the integers
    0, 1, 2, and 3.

    Enumerations are excellent for using with unions to determine the type that has been used. For example:

        typedef struct {
            enum {INT_KIND, DOUBLE_KIND} kind;
            union {
                int i;
                double d;
            } u;
        } Number;

    So instead of defining macros as before, we have used enumeration constants.


    When placing a structure type in header, only declare the structure tag, not variables of this type.








*/


























