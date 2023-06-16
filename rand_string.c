#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		++i;
	return (i);
}

char	*word_dupe(char *str)
{
	int i = 0;
	int len = ft_wordlen(str);
	char *word = malloc(sizeof(char) * (len + 1));
	
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

void	fill_words(char **array, char *str)
{
	int word_index = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		array[word_index] = word_dupe(str);
		++word_index;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
}

int		count_words(char *str)
{
	int num_words = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		++num_words;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
	return (num_words);
}

char	**ft_split(char *str)
{
	int		num_words;
	char	**array;
	
	num_words = count_words(str);
	array = malloc(sizeof(char *) * (num_words + 1));
	
	array[num_words] = 0;
	fill_words(array, str);
	return (array);
}

int	check_atoi(long long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (1);
}

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

int	main(int ac, char **av)
{
	char	**words;
	int		nb_word;
	char	term[1000];
	char	*txt;

	if (ac < 2)
		return (0);
	srand(time(NULL));
	nb_word = ft_atoi(av[2]);
	words = word_list(av);
	rand_word(nb_word, words);
	txt = get_the_text();
	print_txt(txt);
	printf("\n\n");
	fgets(term, 1000, stdin);
	comp_txt(term, txt);
	free(txt);
	return (0);
}
