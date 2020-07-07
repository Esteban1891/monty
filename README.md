# C - Stacks, Queues - LIFO, FIFO :egg:

This project is focused on knowing the use of fifo and lifo etc.
<p><audio class="audio-for-speech" src="http://www.unit-conversion.info/texttools/text-to-html/"></audio></p>
<div class="translate-tooltip-mtz hidden">
<div class="header">
<div class="header-controls">&nbsp;</div>
<div class="translate-icons">&nbsp;</div>
</div>
<div class="translated-text">&nbsp;</div>
</div>
<p><span><img src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcSoWJxuVdsxR60KhJbmLThog70lqHsMTrxetNE7WKhWsA8pQRe8&amp;usqp=CAU" alt="" width="250" height="202" /></span></p>
<p><span><strong>FIFO</strong> is an abbreviation for&nbsp;</span><strong>first in, first out</strong><span>. It is a method for handling data structures where the&nbsp;</span><strong>first element</strong><span>&nbsp;is processed first and the&nbsp;</span><strong>newest element</strong><span>&nbsp;is processed last.</span></p>
<p><span><strong>Real life example:</strong></span></p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p><img src="https://media.geeksforgeeks.org/wp-content/uploads/FIFO.jpg" alt="" width="262" height="145" /></p>
<p><strong>LIFO</strong>&nbsp;is an abbreviation for&nbsp;<strong>Last in, first out</strong>&nbsp;is same as fist in, last out (FILO). It is a method for handling data structures where the&nbsp;<strong>last element</strong>&nbsp;is processed first and the&nbsp;<strong>first element</strong>&nbsp;is processed last.</p>
<p><strong>Real life example:</strong></p>
<p><strong><img src="https://media.geeksforgeeks.org/wp-content/uploads/LIFO.jpg" alt="" width="242" height="271" /></strong></p>
<p>&nbsp;</p>
<p>&nbsp;</p>


## General :loud_sound:
-   What do LIFO and FIFO mean
-   What is a stack, and when to use it
-   What is a queue, and when to use it
-   What are the common implementations of stacks and queues
-   What are the most common use cases of stacks and queues
-   What is the proper way to use global variables

## Data structures :bell:

Please use the following data structures for this project. Don’t forget to include them in your header file.
```
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

```

```
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```
### Compilation & Output :dvd:

-  Your code will be compiled this way:

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty

```

-  Any output must be printed on  `stdout`
-  Any error message must be printed on  `stderr`

 ### The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

**Monty byte code files**

Files containing Monty byte codes usually have the  `.m`  extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                     pall    $
push 4$
     push 5    $
	push    6        $
pall$
julien@ubuntu:~/monty$

```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                     pall    $
$
$
		             $
push 4$
$
	push 5    $
	     push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$

```

**The monty program**

-   Usage:  `monty file`
    -   where  `file`  is the path to the file containing Monty byte code
-   If the user does not give any file or more than one argument to your program, print the error message  `USAGE: monty file`, followed by a new line, and exit with the status  `EXIT_FAILURE`
-   If, for any reason, it’s not possible to open the file, print the error message  `Error: Can't open file <file>`, followed by a new line, and exit with the status  `EXIT_FAILURE`
        -   where  `<file>`  is the name of the file
-   If the file contains an invalid instruction, print the error message  `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status  `EXIT_FAILURE`
    -   where  is the line number where the instruction appears.
    -   Line numbers always start at 1
-   The monty program runs the bytecodes line by line and stop if either:
    -   it executed properly every line of the file
    -   it finds an error in the file
    -   an error occured
-   If you can’t malloc anymore, print the error message  `Error: malloc failed`, followed by a new line, and exit with status  `EXIT_FAILURE`.
-   You have to use  `malloc`  and  `free`  and are not allowed to use any other function from  `man malloc`  (realloc, calloc, …))


## Author :octocat:

[Roberto Palacios](https://www.linkedin.com/in/roberto-palacios-32917654/) | [Twitter](https://twitter.com/robpalacios11)
| [GitHub](https://github.com/robpalacios1)

[Esteban De La Hoz](https://www.linkedin.com/in/esteban-de-la-hoz-romero-b6270017b/) | [Twitter](https://twitter.com/Esteban18911)
| [GitHub](https://github.com/Esteban18911)
