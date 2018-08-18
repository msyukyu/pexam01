#include <stdlib.h>

const char g_base[] = "0123456789ABCDEF";

char	*ft_write_base(int value, int base, int count, char *str)
{
	int sign;

	sign = (value < 0) ? -1 : 1;
	if ((base != 10 && value < base) || 
			(base == 10 && value > -10 && value < 10))
	{
		count++;
		if (value < 0)
			count++;
		str = (char *)malloc(sizeof(char) * (count + 1));
		str[count] = '\0';
		if (value < 0)
		{
			str[count - 1] = '-';
			str[count - 2] = g_base[sign * value];
		}
		else
			str[count - 1] = g_base[sign * value];
		return (str);
	}
	else
	{
		count++;
		str = ft_write_base(value / base, base, count, str);
		str[count - 1] = g_base[sign * (value % base)];
		return (str);
	}
}

char	*ft_strrev(char *str)
{
	int i;
	int l;
	char tmp;

	i = 0;
	while (str[i])
		i++;
	l = i - 1;
	i = 0;
	while (i < l / 2 + 1)
	{
		tmp = str[i];
		str[i] = str[l - i];
		str[l - i] = tmp;
		i++;
	}
	return (str);
}

char	*ft_itoa_base(int value, int base)
{
	char *str;

	str = NULL;
	if (base < 2 || base > 16 || (base != 10 && value < 0))
		return (str);
	str = ft_write_base(value, base, 0, str);
	str = ft_strrev(str);
	return (str);
}
