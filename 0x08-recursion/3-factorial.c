#include "main.h"

/**
* factorial - finding factorial of n
* @n: given number
* Return: factorial of number, -1 if negative n
*/

int factorial(int n)
{
if (n < 0)
return (-1);
else if (n == 0 || n == 1)
return (n);
else
return (n * factorial(n - 1));
}
