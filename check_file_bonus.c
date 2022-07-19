#include "pipex_bonus.h"
#include "libft/libft.h"

void	fd_dup(int fd1, int fd2)
{
	if (dup2(fd1, fd2) < 0)
		perror("Dup2 failed");
	close(fd1);
	return ;
}

void	free_strarray(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**extract_path(char **envp)
{
	char	*ptrPath;
	char	**paths;

	while (*envp != NULL)
	{
		ptrPath = ft_strnstr(*envp, "PATH=", 5);
		if (ptrPath)
		{
			paths = ft_split (ptrPath + 5, ':');
			return (paths);
		}	
		envp++;
	}
	return (NULL);
}

char	**get_cmd_path(char **argv, char **envp, int arg)
{
	char	**cmd_path;
	char	**cmd_arg;
	char	*test_path;
	char	*temp;
	char	**path_array;

	path_array = extract_path(envp);
	temp = ft_strjoin("/", argv[arg]);
	cmd_arg = ft_split(temp, ' ');
	while (*path_array)
	{
		test_path = ft_strjoin(*path_array, cmd_arg[0]);
		if (access(test_path, X_OK) == 0)
		{
			temp = ft_strjoin(*path_array, temp);
			cmd_path = ft_split(temp, ' ');
			// free_strarray(path_array);
			return (cmd_path);
		}
		path_array++;
	}
	ft_printf("Command not found : %s\n", cmd_arg[0]);
	exit (1);
}

int	check_file(char *fname, int type)
{
	if (type == 0)
	{
		if ((access(fname, F_OK) == 0) && (access(fname, R_OK) == 0))
			return (open(fname, O_RDONLY));
		else
			perror(fname);
	}
	else
	{
		if (access(fname, F_OK) == 0)
		{
			if (access(fname, W_OK) == 0)
				return (open(fname, O_WRONLY | O_APPEND));
			else
				perror(fname);
		}
		else
			return (open(fname, O_WRONLY | O_CREAT, 0644));
	}
	exit (1);
}
