#include <unistd.h>

void	ft_union(char *str1, char *str2)
{
	int	i;
	int j;
	int l;

	i = 0;
	while (str1[i])
	{
		j = 0;
		while (j < i)
		{
			if (str1[j] == str1[i])
				break ;
			j++;
		}
		if (j == i)
			write(1, &(str1[i]), 1);
		i++;
	}
	l = i;
	i = 0;
	while (str2[i])
	{
		j = 0;
		while (j < l)
		{
			if (str2[i] == str1[j])
				break;
			j++;
		}
		if (j == l)
		{
			j = 0;
			while (j < i)
			{
				if (str2[j] == str2[i])
					break;
				j++;
			}
			if (j == i)
				write(1, &(str2[i]), 1);
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
