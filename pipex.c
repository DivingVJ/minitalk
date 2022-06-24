#include "pipex.h"
#include "libft/libft.h"

char **extract_path(char **envp)
{
	int	i;
	char *ptrPath;
	char **paths;

	i = 0;
	while (*envp != NULL)
	{
       	ptrPath = ft_strnstr(*envp, "PATH=", 5);
      	if (ptrPath) 
		{
			paths = ft_split(ptrPath+5, ':');
			return (paths);
		}	
       	envp++;
  	}
	return (NULL);
}

char *get_cmd_path(char *cmd, char **patharray)
{
	char *temp1, *temp2;
	int test;

	while (*patharray)
	{
		temp1 = ft_strjoin(*patharray, "/");
		temp2 = ft_strjoin(temp1, cmd);
		if (access(temp2, X_OK) == 0)
		{
			printf("%s\n", temp2);
			return (temp2);
		}
		patharray++;
	}
	return (NULL);
}

int	check_file(char *name)
{
	if (access(name, R_OK | W_OK))
		return (0);
	return (1);	
}

char **split_cmd(char *cmd)
{
	char **retval;
	char *temp;
	int		len;

	if(cmd[0] == '\"')
	{
		len = ft_strlen(cmd);
		temp = ft_substr(cmd, 1, len - 2);
	}
		retval = ft_split(temp, ' ');
	return (retval);
}

void exec_cmd(char *args, char *envp, char **patharray)
{
	int	fd[2];
	int pid;

	if (pipe(fd) < 0) 
		return ;
	pid = fork();
	if (pid < 0) { return ;}
	else if (pid == 0)
	{	//child
		char **argv;
		char **envp;
		char *pathcmd;
		char **splitcmd;
		char *argk[] = {"cat", NULL};
		printf("child");
//		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
	//	splitcmd = split_cmd(argv[2]);
		pathcmd = get_cmd_path(argv[2], patharray);
		printf("Path %s\n", pathcmd);
		if (!pathcmd) 
		{ 
			printf("Command not found : %s\n", argv[2]);
			return ;
		}
		execve(pathcmd, argk, envp);
		
	}
	else
	{	// parent
		printf("parent\n");
	}
}


int main(int argc, char **argv, char **envp)
{
    int len, i,k, pid, test;
	int	fd[2];
	char *ptrPath;
	char *cmd;
	char *filename;
	char **patharray;

	i = 0;
    if (argc != 3)
    {
        printf("Need 2 arg\n");
        return (-1);
    }
	if (!check_file(argv[1]))
	{
		printf("No such file or directory : %s\n", argv[1]);
		return 1;
	}
	patharray = extract_path(envp);
	for(k = 0; **patharray != '\0'; k++)
		printf("%s\n", patharray[k]);


	exec_cmd(*argv, *envp, patharray);



	
    len = ft_strlen(argv[1]);
    printf("Argv = %s : %d\n", argv[1], len);
    return (0);
}
