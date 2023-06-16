#include "../dactylo.h"

char	*get_the_text(void)
{
	int		len;
	FILE	*fp;
	char	*text;

	fp = fopen("tmp.txt", "r");
	len = file_len("tmp.txt") + 1;
	text = malloc(sizeof(char) * len + 1);
	fgets(text, len, fp);
	text[len + 1] = 0;
	fclose(fp);
	return (text);
}

void	print_txt(char *txt)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (txt[i])
	{
		if (c % 25 == 0 && c > 1)
			write(1, "\n", 1);
		if (txt[i] != ' ')
			c++;
		while (txt[i] != ' ' && txt[i])
		{
			write(1, &txt[i], 1);
			i++;
		}
		if (txt[i] == ' ')
		{
			write(1, &txt[i], 1);
			i++;
		}
	}
}
