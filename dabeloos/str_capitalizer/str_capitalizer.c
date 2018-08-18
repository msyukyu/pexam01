#include <unistd.h>

void	ft_put_str(char *str)
{
	int	i;
	int	new;

	new = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			if (new == 0)
				new = 1;
		}
		else if (str[i] <= 'z' && str[i] >= 'a')
		{
			if (new)
			{
				str[i] = str[i] + 'A' - 'a';
				new = 0;
			}
		}
		else
		{
			if (new == 0 && str[i] <= 'Z' && str[i] >= 'A')
				str[i] = str[i] + 'a' - 'A';
			new = 0;
		}
		write(1, &(str[i]), 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_put_str(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	if (argc == 1)
		write(1, "\n", 1);
	return (0);
}
