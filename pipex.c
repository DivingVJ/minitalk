#include "pipex.h"
#include "libft/libft.h"

char **extract_path(char **envp)
{
	int	i;
	char *ptrPath;
	char **paths;

	i = 0;
	while (envp[i] != NULL)
	{
       	ptrPath = ft_strnstr(envp[i], "PATH=", 5);
      	if (ptrPath) 
		{
			paths = ft_split(ptrPath+5, ':');
			return (paths);
		}	
       	i++;
  	}
	return (NULL);
}
int	check_file(char *name)
{
	if (access(name, R_OK | W_OK))
		return (0);
	return (1);	
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
	for(k = 0; patharray[k]!= (void*)0;k++ )
		printf("%s\n", patharray[k]);
	if (pipe(fd) < 0) 
		return 2;

	test = access("/usr/bin/cat", X_OK);
	printf("test %d\n", test);
	pid = fork();
	if (pid < 0) { return 3;}
	else if (pid == 0)
	{
		//child
		char **argv;
		char **envp;
		printf("Child\n");
		
	}
	else
	{
		printf("parent\n");
	}
	
    len = ft_strlen(argv[1]);
    printf("Argv = %s : %d\n", argv[1], len);
    return (0);
}
