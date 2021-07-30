# _printf

## DESCRIPTION
Prints ARGUMENT(s) based on FORMAT

If format includes format specifiers (subsequences beginning with %), the \
additional arguments following format are formatted and inserted in the resulting\
 string replacing their respective specifiers.

_printf will also take an indefinite amount of arguments.

Upon successful return, these functions return the number of characters printed\
  (excluding the null byte used to end output to strings).

If an output error is encountered, a negative value is returned.

## AUTHORS
-Luis Velasquez.

-Smith Flores.

## _printf("end").