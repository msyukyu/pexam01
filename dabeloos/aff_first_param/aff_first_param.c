#include <unistd.h>

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
	if (argc > 1)
	{
		ft_put_str(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
