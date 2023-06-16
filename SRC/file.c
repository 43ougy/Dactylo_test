#include "../dactylo.h"

int	file_len(char *str)
{
	int		i;
	char	c;
	FILE	*file;

	i = 0;
	file = fopen(str, "r");
	if (!file)
	{
		printf("Can't open file\n");
		return (0);
	}
	for (c = getc(file); c != EOF; c = getc(file))
		i += 1;
	fclose(file);
	return (i);
}
