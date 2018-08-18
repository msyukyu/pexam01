#include <stdlib.h>
#include <stdio.h>

int		ft_next_prime(int n)
{
	int i;

	i = 0;
	if (n < 2)
		return (2);
	if (n % 2 == 0)
		n++;
	else
		n += 2;
	while (1)
	{
		i = 3;
		while (i * i <= n)
		{
			if (n % i == 0)
				break ;
			i++;
		}
		if (i * i > n)
			return (n);
		n += 2;
	}
}

void	ft_print_fact(int n)
{
	int d;

	d = 1;
	while (n / d != 1)
	{
		n /= d;
		if (d == 1)
			d = 2;
		else
			printf("*");
		d = (d == 1) ? 2 : d;
		while (n % d != 0)
			d = ft_next_prime(d);
		printf("%d", d);
	}
	if (d == 1)
		printf("%d", 1);
}

int		main(int argc, char *argv[])
{
	int n;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		ft_print_fact(n);
	}
	printf("\n");
	return (0);
}
