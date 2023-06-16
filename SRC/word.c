#include "../dactylo.h"

char	**word_list(char **av)
{
	char	**list;
	char	*tmp;
	int		lenght;
	FILE	*file;

	file = fopen(av[1], "r");
	if (!file)
		return (NULL);
	lenght = file_len(av[1]);
	tmp = malloc(sizeof(char) * lenght + 1);
	tmp[lenght] = 0;
	if (!tmp)
		return (NULL);
	fgets(tmp, lenght, file);
	list = ft_split(tmp);
	free(tmp);
	fclose(file);
	return (list);
}

void	rand_word(int nbw, char **list)
{
	int		r;
	int		p;
	int		i;
	FILE	*fp;

	r = -1;
	while (list[r])
		r++;
	fp = fopen("tmp.txt", "w");
	for (i = 1; i < nbw + 1; i++)
	{
		p = rand() % r;
		fprintf(fp, "%s", list[p]);
		if (i < nbw)
			fprintf(fp, " ");
	}
	fprintf(fp, "\n");
	for (i = 0; list[i]; i++)
		free(list[i]);
	free(list);
	fclose(fp);
}
