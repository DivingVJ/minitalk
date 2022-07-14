#include "pipex.h"
#include "libft/libft.h"

void	fd_dup(int fd1, int fd2)
{
	if (dup2(fd1, fd2) < 0)
		perror("Dup2 failed");
	close(fd1);
	return ;
}

void	child_in(int pfd[], char **argv, char **envp, char **p_array)
{
	pid_t	pid;
	char	**cmd_path;
	int		fd_input;

	fd_input = check_file(argv[1], 0);
	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		return ;
	}
	else if (pid == 0)
	{
		cmd_path = get_cmd_path(argv, 2, p_array);
		close(pfd[0]);
		fd_dup(fd_input, STDIN_FILENO);
		fd_dup(pfd[1], STDOUT_FILENO);
		execve(cmd_path[0], cmd_path, envp);
		ft_printf("Execve1 failed!\n");
	}
	else
		waitpid(-1, NULL, 0);
}

void	child_out(int pfd[], char **argv, char **envp, char **p_array)
{	
	pid_t	pid;
	char	**cmd_path;	
	int		fd_output;

	fd_output = check_file(argv[4], 1);
	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		return ;
	}
	else if (pid == 0)
	{
		cmd_path = get_cmd_path(argv, 3, p_array);
		close(pfd[1]);
		fd_dup(pfd[0], STDIN_FILENO);
		fd_dup(fd_output, STDOUT_FILENO);
		execve(cmd_path[0], cmd_path, envp);
		ft_printf("Execve2 failed!\n");
	}
	else
	{
		close(pfd[1]);
		waitpid(-1, NULL, 0);
	}
}

void	exec_cmd( char **argv, char **envp, char **p_array)
{
	int		pfd[2];
	pid_t	pid;
	char	**cmd_path;

	if (pipe(pfd) < 0)
	{
		perror("Pipe Failed");
		return ;
	}
	child_in(pfd, argv, envp, p_array);
	child_out(pfd, argv, envp, p_array);
}

int	main(int argc, char **argv, char **envp)
{
	char	**path_array;

	if (argc != 5)
	{
		ft_printf("Need 4 arguments: <infile> <cmd1> <cmd2> <outfile>\n");
		return (1);
	}
	path_array = extract_path(envp);
	exec_cmd(argv, envp, path_array);
	return (0);
}
