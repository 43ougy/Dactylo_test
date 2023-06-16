#ifndef DACTYLO_H
# define DACTYLO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

int		ft_atoi(char *str);
int		file_len(char *str);
int		ft_strlen(char *str);
int		check_atoi(long long nb);
char	*get_the_text(void);
char	**ft_split(char *str);
char	**word_list(char **av);
void	print_txt(char *txt);
void	comp_txt(char *ret, char *lst);
void	rand_word(int nbw, char **list);

#endif
