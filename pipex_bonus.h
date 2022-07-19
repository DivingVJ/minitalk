#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
char	**get_cmd_path(char **argv, char **envp, int arg);
void	fd_dup(int fd1, int fd2);
void	free_strarray(char **array);
void	child_in(int pfd[], int argc, char **argv, char **envp);
void	child_proc(int pfd[], int cmd_no, char **argv, char **envp);
void	child_out(int pfd[], int argc, char **argv, char **envp);
void	exec_cmd(int argc, char **argv, char **envp);

/* UTILITY FUNCTONS */

int		ft_printf(const char *str, ...);
char	*ft_strnstr(const char	*str, const char *to_find, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif