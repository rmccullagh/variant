Variant Records
===============
Variant Record, Tagged Union, Discriminated Union. Using this system allows a system to implement data structures with dynamic types. The struct holds the Type type value which indicates it's implicit type. For fast output, the system provides `var_print` which will deduce the correct information to pass to various `stdio.h` calls like printf.

Type
====
typedef enum {
	IS_LONG,
	IS_FLOAT,
	IS_STRING
} Type;


