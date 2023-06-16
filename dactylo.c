#include "dactylo.h"

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
