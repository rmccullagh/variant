Variant Records
===============
Variant Record, Tagged Union, Discriminated Union. Using this system allows a system to implement data structures with dynamic types. The struct holds the Type type value which indicates it's implicit type. For fast output, the system provides `var_print` which will deduce the correct information to pass to various `stdio.h` calls like printf.

Type
====
```c
typedef enum {
	IS_LONG,
	IS_FLOAT,
	IS_STRING
} Type;
```
Var
===
```c
struct var {
	Type type;
	union {
		long lval;
		float flval;
		struct {
			size_t len;
			char* sval;
		} str;
	} val;
}; 
```
`struct var` is typedef'd to Var for easy access and declaration.

API
===

```c
Var* var_long(long)
```

```c
Var* var_float(float)
```

```c
Var* var_string(char*)
```

```c
void var_print(Var*)
```

```c
void var_destroy(Var*)
```

```c
Type var_type_of(Var*)
```

```c
const char* const var_type_of_token(Type);
```

Description
===========
While accessing members of the object via direct access is possible, it is recommened to use the macros to get values.

Macros
======
```c
VAR_FLVAL
```
This macros expands to extract a `float` value from a `Var` object

```c
VAR_LVAL
```
This macros expands to extract a `long` value from a `Var` object

```c
VAR_SVAL
```
This macros expands to extract a `char*` pointer from a `Var` object. The `char*` pointer is located in the `str` struct inside the union `val`. The `char*` pointer is always terminated by a null byte.

```c
VAR_SLEN
```
This macro expands to return a `size_t` value that is the length of a string.

```c
VAR_TYPE
```
This macro expands to extract the `Type` value from a `Var` object.

TODO
====
[*] Create a build system to allow for this system to be compiled as a libary
