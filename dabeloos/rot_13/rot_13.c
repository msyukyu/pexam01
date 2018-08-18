#include <unistd.h>

void	ft_rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] = (str[i] - 'a' + 13) % 26 + 'a';
		else if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] = (str[i] - 'A' + 13) % 26 + 'A';
		i++;
	}
}

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &(str[i]), 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_rot_13(argv[1]);
		ft_put_str(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
