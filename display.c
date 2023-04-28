/**
 * my_strcspn - get length of prefix
 * substring that doesn't contain specified characters
 * @s: string to search
 * @reject: string containing characters to exclude
 *
 * Return: number of characters in s that do not occur in reject
 */
size_t _strcspn(const char *s, const char *reject)
{
	const char *p, *q;
	
	for (p = s; *p; p++)
	{
		for (q = reject; *q; q++)
		{
			if (*p == *q)
			{
				return (p - s);
			}
		}
	}
	return (p - s);
}
