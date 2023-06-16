#include "../dactylo.h"

int	check_atoi(long long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (1);
}

void	comp_txt(char *ret, char *lst)
{
	int	i;
	int	l_c;
	int	r_c;

	i = -1;
	l_c = 0;
	while (lst[++i])
	{
		if (lst[i] != ' ')
			l_c++;
	}
	i = -1;
	r_c = 0;
	while (ret[++i])
	{
		if (ret[i] != ' ')
			r_c++;
	}
	printf("\nThere are [ %5d ] char\nYou have written [ %5d ] char\n\n", l_c - 1, r_c - 1);
}
