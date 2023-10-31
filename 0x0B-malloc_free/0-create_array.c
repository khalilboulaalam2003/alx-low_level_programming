#include "main.h"
#include <stdlib.h>
/**
 * create_array - Main Entry
 * @size: input
 * @c: input
 * Return: 0
 */
char *create_array(unsigned int size, char c)
{
		char *ari;
		unsigned int i;

		if (size == 0)
		{
			return (NULL);
		}

		ari = malloc(sizeof(char) * size);

		if (ari == NULL)
		{

			return (NULL);
		}

		for (i = 0; i < size; i++)
		{
			ari[i] = c;
		}

		return (ari);
}
