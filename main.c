#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    len = _printf("Let's try to printf a simple sentence. %c %b %s \n", 'W', 98, "Hwhvrhhbdb");
    len2 = printf("Let's try to printf a simple sentence. %c %d %s \n", 'W', 98, "Hwhvrhhbdb");
    _printf(NULL);
    printf("%d %d\n", len, len2);
}
