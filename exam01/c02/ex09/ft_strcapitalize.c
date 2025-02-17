#include <stdio.h>

int	is_low(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strcapitalize(char *str)
{
	char	*ptr_start;
	int		new_word;

	ptr_start = str;
	new_word = 1;
	while (*str)
	{
		// 英数字かどうか
		if (is_low(*str) || is_upper(*str) || is_numeric(*str))
		{
			if (new_word && is_low(*str))
				*str -= 32;
			else if (!new_word && is_upper(*str))
				*str += 32;
			new_word = 0;
		}
		else
		{
			new_word = 1;
		}
		str++;
	}
	return (ptr_start);
}

int	main(void)
{
	char	s[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("%s\n", ft_strcapitalize(s));
	return (0);
}
