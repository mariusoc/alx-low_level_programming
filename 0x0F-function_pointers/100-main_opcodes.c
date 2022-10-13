#include "function_pointers.h"

/**
* int_index - Searches for an integer
*
* @array: An array of integers
*
* @size: Number of elements in the @array
*
* @cmp: Pointer to the function to be used to compare values
*
* Return: Integers, index integer in @array that matches
* condition of @cmp was found (SUCCESS) or
* -1 if size <= 0 or integer that matches condition of @cmp
*  wasn't found in @array or
*  NULL if @array || @cmp is NULL
*/

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0 || !array || !cmp)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}
#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
* get_op_func - Selects correct function to perform based on @s
*
* @s: The operator
*
* Return: The pointer to the operator's function or
* NULL if not found
*/

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;

	while (i < 5)
	{
		if (*(ops[i].op) == *s)
			return (ops[i].f);

		i++;
	}

	return (ops[i].f);
}
#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
* op_add - Adds two numbers @a and @b
*
* @a: A number
*
* @b: A number
*
* Return: Sum of @a and @b
*/

int op_add(int a, int b)
{
	return (a + b);
}

/**
* op_sub - Calculates the difference of @c and @b
*
* @a: A number
*
* @b: A number
*
* Return: Difference of @a and @b
*/

int op_sub(int a, int b)
{
	return (a - b);
}

/**
* op_mul - Multiplies two numbers
*
* @a: A number
*
* @b: A number
*
* Return: Product of @a and @b
*/

int op_mul(int a, int b)
{
	return (a * b);
}

/**
* op_div - Divides @a by @b
*
* @a: A number
*
* @b: A number
*
* Return: Result of the division of @a by @b without remainder
*/

int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
* op_mod - Calculates the remainder of @a divided by @b
*
* @a: A number
*
* @b: A number
*
* Return: Remainder of @a divider by @b
*/

int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
