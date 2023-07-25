## Group project for custom printf function implementation in C programming language, ALX Africa.

![](https://cdn.iconscout.com/icon/free/png-256/printer-1695681-1437194.png)

------------

#### Contributors ✨
<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
 <tbody>
  <tr>
   <td align="center" valign="top" width="14.28%"><a href="https://github.com/Chamour15"><img src="https://avatars.githubusercontent.com/u/133526082?v=4" width="100px;" alt="Chamour15"/><br /><sub><b>Chamour15</b></sub></a><br /><a href="https://github.com/dakhamohammed/printf/commits?author=Chamour15" title="Code">💻</a></td>
   <td align="center" valign="top" width="14.28%"><a href="https://github.com/dakhamohammed"><img src="https://avatars.githubusercontent.com/u/131229016?v=4" width="100px;" alt="dakhamohammed"/><br /><sub><b>dakhamohammed</b></sub></a><br /><a href="https://github.com/dakhamohammed/printf/commits?author=dakhamohammed" title="Code">💻</a></td>
  </tr>
 </tbody>
</table>
<!-- markdownlint-restore -->
<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->

------------

#### Table of Contents:
| C FILES  | FUNCTION(s) |
| ------------- | ------------- |
| _printf.c  | _printf() |
| _putchar.c  | _puts() & _putchar() |
| base_function.c  | *convert() & print_binary() & print_octal() & print_hex() & print_HEX |
| main.h  | All functions prototype & macros & structure definition.|
| more_specifiers_functions.c  | print_STRING() & print_address()|
| number_functions.c  | _isdigit() & _strlen() & print_number() & print_number_right_shift() & print_number_left_shift|
| parameters_precision.c  | init_params() & *get_precision()|
| printer.c  | print_from_to()|
| specifiers.c  | (*get_specifier(char *s))() & get_print_func() & get_flag() & get_modifier() & *get_width() &|
| specifiers_functions.c  | print_character() & print_string() & print_percent() & print_int() & print_unsigned()|

------------

#### Task list:
- [x] TASK 0: Write a function that produces output according to a format.
- [x] TASK 1: Handle the following conversion specifiers: %d, %i
- [x] TASK 2: Handle the following custom conversion specifiers: %b
- [x] TASK 3: Handle the following conversion specifiers: %u, %o, %x, %X
- [x] TASK 4: Use a local buffer of 1024 chars in order to call write as little as possible.
- [x] TASK 5: Handle the following custom conversion specifier: %S
- [x] TASK 6: Handle the following conversion specifier: %p.
- [x] TASK 7: Handle the following flag characters for non-custom conversion specifiers: %+, space, %#
- [x] TASK 8: Handle the following length modifiers for non-custom conversion specifiers: %l, %h
- [x] TASK 9: Handle the field width for non-custom conversion specifiers.
- [ ] TASK 10: Handle the precision for non-custom conversion specifiers.
- [x] TASK 11: Handle the 0 flag character for non-custom conversion specifiers.
- [x] TASK 12: Handle the - flag character for non-custom conversion specifiers.
- [x] TASK 13: Handle the following custom conversion specifier: %r
- [x] TASK 14: Handle the following custom conversion specifier: %R

------------

####FlowChart:
```flow
st=>start: Start
op1=>operation: _printf()
cond=>condition: If not specifier
op2=>operation: print_from_to()
op3=>operation: _putchar()
op4=>operation: get_specifier()
op5=>operation: get_print_func()
cond1=>condition: If flag or width or .precision or length
op6=>operation: %[flags()] ->[width()] ->[.precision()] ->[length()]
op7=>operation: _putchar()
e=>end: End
e1=>end:End

st->op1->cond->op2->op3->op4->op5->cond1->op6->op7
cond(yes)->op2->op3->e
cond(no)->op4
cond1(yes)->op6->op7
cond1(no)->op7
```
