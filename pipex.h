#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>

/* MAIN FUNCTIONS */
int		check_file(char *fname, int type);
char	**extract_path(char **envp);
char	**get_cmd_path(char **argv, int arg, char **path_array);
void	free_strarray(char **array);
void	child_in(int pfd[], char **argv, char **envp, char **p_array);
void	child_out(int pfd[], char **argv, char **envp, char **p_array);
void	exec_cmd( char **argv, char **envp, char **p_array);

/* UTILITY FUNCTONS */

int		ft_printf(const char *str, ...);
char	*ft_strnstr(const char	*str, const char *to_find, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif