#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

size_t	ft_strlen(const char *str);
void	ft_strncpy(char *dest, char *src, int len);
char	**ft_split(char *str, char c);
void	*strclear(char **str);
long	ft_atoi(char *str);
int		check_string(char *str);

int parse(int argc, char *argv[]);


#endif
