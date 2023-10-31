#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - Entry point
 *@size: size of the array
 *@c: character
 * Return: a pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *arra = NULL;
	unsigned int i;

	if (size == 0)
		return (NULL);
	if (size != 0)
	{
		arra = (char *)malloc(size * sizeof(char));
		if (arra != NULL)
		{
			for (i = 0; i < size; i++)
				arra[i] = c;
		}
	}
	return (arra);
}
