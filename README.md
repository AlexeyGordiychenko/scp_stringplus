# scp_string+ (Group project, 2 members)

## My part of the project
My part was to make:
+ part of sprintf (i, d, c, s specifiers)
+ part 5 (C# functions)
+ sscanf
+ edit and refactor Makefile
+ some misc functions

So for my code you can check files
+ [scp_sprintf.c](src/src/scp_sprintf.c) ([i & d](src/src/scp_sprintf.c?plain=1#L211), [c](src/src/scp_sprintf.c?plain=1#L422), [s](src/src/scp_sprintf.c?plain=1#L446) specifiers)
+ [scp_csharp.c](src/src/scp_csharp.c)
+ [scp_sscanf.c](src/src/scp_sscanf.c)
+ [Makefile](src/makefile)
+ misc functions [int_to_str_min_len](src/src/scp_common.c?plain=1#L165) and below

## Score:
The final score is 150% (max)

## Task
Implementation of the string.h library with additions.

### string.h Functions

memchr, memcmp, memcpy, memset, strncat, strchr, strncmp, strncpy, strcspn, strerror, strlen, strpbrk, strrchr, strstr, strtok

### sprintf and sscanf

sprintf, sscanf with specifiers: c, d, i, e, E, f, g, G, o, s, u, x, X, p, n, %

sprintf Flags: -, +, (space), #, 0

sprintf And sscanf width: (number), *

sprintf precision: .number, .*

sprintf And sscanf length: h, l, L

### Special string processing functions (from the String class in C#)

to_upper, to_lower, insert, trim

