#include "pipex_bonus.h"
#include "libft/libft.h"

void	child_in(int pfd[], int argc, char **argv, char **envp)
{
	pid_t	pid;
	char	**cmd_path;
	int		fd_input;

	fd_input = check_file(argv[argc], 0);
	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		return ;
	}
	else if (pid == 0)
	{
		cmd_path = get_cmd_path(argv, envp, 2);
		close(pfd[0]);
		fd_dup(fd_input, STDIN_FILENO);
		fd_dup(pfd[1], STDOUT_FILENO);
		execve(cmd_path[0], cmd_path, envp);
		ft_printf("Execve1 failed!\n");
	}
	else
		waitpid(-1, NULL, 0);
}

void	child_proc(int pfd[], int cmd_no, char **argv, char **envp)
{	
	pid_t	pid;
	char	**cmd_path;	

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		return ;
	}
	else if (pid == 0)
	{
		cmd_path = get_cmd_path(argv, envp, cmd_no);
		ft_printf("CMD %s\n", cmd_path[0]);
		ft_printf("CMD %s\n", cmd_path[1]);
		ft_printf("CMD %s\n", cmd_path[2]);
		fd_dup(pfd[0], STDIN_FILENO);
		fd_dup(pfd[1], STDOUT_FILENO);
		execve(cmd_path[0], cmd_path, envp);
		ft_printf("Execve2 failed!\n");
	}
	else
	{
		waitpid(-1, NULL, 0);
	}
}

void	child_out(int pfd[], int argc, char **argv, char **envp)
{	
	pid_t	pid;
	char	**cmd_path;	
	int		fd_output;

	fd_output = check_file(argv[(argc - 1)], 1);
	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		return ;
	}
	else if (pid == 0)
	{
		cmd_path = get_cmd_path(argv, envp, (argc - 2));
		close(pfd[1]);
		fd_dup(pfd[0], STDIN_FILENO);
		fd_dup(fd_output, STDOUT_FILENO);
		execve(cmd_path[0], cmd_path, envp);
		ft_printf("Execve2 failed!\n");
	}
	else
	{
		close(pfd[1]);
		close(pfd[0]);
		waitpid(-1, NULL, 0);
	}
}

void	exec_cmd(int argc, char **argv, char **envp)
{
	int		i;
	int		pfd[2];

	i = 5;
	if (pipe(pfd) < 0)
	{
		perror("Pipe Failed");
		return ;
	}
	child_in(pfd, 1, argv, envp);
	while (i < argc)
	{
		child_proc(pfd, (i - 2), argv, envp);
		i++;
	}
	child_out(pfd, argc, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		ft_printf("Need minimum 4 arguments: \n");
		ft_printf("<infile> <cmd1> <cmd2> <outfile>\n");
		return (1);
	}
	exec_cmd(argc, argv, envp);
	ft_printf("Bonus End");
	return (0);
}
