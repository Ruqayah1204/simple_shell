#include "shell.h"


/**
 * interactive - checks whether or not the shell is interactive
 * @address: refers to the address of struct
 *
 * Return: 1 or 0 if or not it is interactive
 */

int interactive(address_t *address)
{
	return (isatty(STDIN_FILENO) && address->readfd <= 2);
}


/**
 * is_delim - this program checks if character is a delimeter
 * @t: this is the character in check
 * @dlmt: this represents the delimiter
 * Return: 1 or 0 if true or false
 */

int is_delim(char t, char *dlmt)
{
	while (*dlmt)
		if (*dlmt++ == t)
			return (1);
	return (0);
}


/**
 * _isalpha - this program checks for alphabets
 * @t: input
 * Return: 1 or 0 if or not it is alphabet
 */

int _isalpha(int t)
{
	if ((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z'))
		return (1);
	else
		return (0);
}


/**
 * _atoi - this program converts string to integer
 * @s: the string
 * Return: 0 or otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}

