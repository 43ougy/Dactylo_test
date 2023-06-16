#include "../dactylo.h"

int	ft_atoi(char *str)
{
	long long	nb;
	int			sig;

	nb = 0;
	sig = 1;
	if (*str == '-')
		sig = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
		nb = nb * 10 + (*str++ - '0');
	if (!check_atoi(nb * sig))
		return (0);
	return (nb * sig);
}

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}
