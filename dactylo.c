#include "dactylo.h"

int	main(int ac, char **av)
{
	char	**words;
	int		nb_word;
	char	term[1000];
	char	*txt;

	if (ac != 3)
		return (1);
	srand(time(NULL));
	nb_word = ft_atoi(av[2]);
	words = word_list(av);
	rand_word(nb_word, words);
	if (!(txt = get_the_text()))
		return (1);
	print_txt(txt);
	write(1, "\n\n", 2);
	fgets(term, 1000, stdin);
	comp_txt(term, txt);
	free(txt);
	return (0);
}
