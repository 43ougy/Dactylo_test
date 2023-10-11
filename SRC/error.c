#include "../dactylo.h"

int	check_atoi(long long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (1);
}

int	_ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	len;

	i = 0;
	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
void	comp_txt(char *ret, char *lst)
{
	char	**liste;
	char	**value;
	int		i = 0;
	int		fd = open("tmp.txt", O_RDWR);

	liste = ft_split(lst);
	value = ft_split(ret);
	write(1, "\n", 1);
	while (value[i] && liste[i])
	{
		if (_ft_strcmp(value[i], liste[i]))
			dprintf(fd, "\x1B[31m'%s' bad --> %s\x1B[0m\n", liste[i], value[i]);
		else
			dprintf(fd, "\x1B[32m'%s' good --> %s\x1B[0m\n", liste[i], value[i]);
		i++;
	}
}
