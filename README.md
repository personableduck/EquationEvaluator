# Equation Evaluator

Equation Evaluator
Your task is to write a command-line program to evaluate a set of equations.
An equation is defined by:

<LHS> = <RHS>

• Each equation is specified on a separate line.

• <LHS> is the left-hand side of the equation and is always a variable name.

• A variable name is composed of letters from the alphabet ( for which isalpha(c) is true ).

• <RHS> is the right hand side of the equation and can be composed of:

• variables

• unsigned integers

• the + operator

Here is one example set of equations:

offset = 4 + random + 1

location = 1 + origin + offset

origin = 3 + 5

random = 2

Requirements

• Your program should take a filename as input. The file contains a set of equations, like
the above.

• It should evaluate the set of equations and print the value of each variable.

• The output should be sorted in ascending order by variable name.

• If any variable doesn’t have a well defined and unique solution, this indicates an error in input. Print the exact contents of input file and exit.

• To allow automated evaluation, do not print any error messages or debug output. The output for the example above would be:

location = 16
offset = 7
origin = 8
random = 2

Evaluation

You will not be judged based on time it takes to complete this assignment. Please take the time and show us your best work.
The Challenge will be evaluated around these areas:

• Code Modularity: Is the software properly split across files, functions, classes and structs?

• Correctness: Is the output of the software correct, when testing against our test suite?

• Efficiency: Is this the most efficient algorithm for the task?

• Language: Does the code make proper use of language-specific constructs/features?

• Readability: Is the code easy to understand and properly commented?

• Packaging: Does the software include a working build script for Unix-based systems (Makefile etc) or clear instructions?

