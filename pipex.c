#include "pipex.h"
#include "libft/libft.h"

int main(int argc, char **argv, char **envp)
{
    int len;
	int	fid;
	char	*ptrPath;

    if (argc != 2)
    {
        printf("Need 1 arg\n");
        return (-1);
    }

	while (*envp)
	{
        ptrPath = strstr(*envp, "PATH");
//        printf("%s\n", (ptrPath));
      if (ptrPath) printf("%s\n", (ptrPath+5));
        *envp++;
    }
	fid = access("infile", R_OK );
	printf("FID = %d\n", fid);
    len = ft_strlen(argv[1]);
    printf("Argv = %s : %d\n", argv[1], len);
    return (0);
}
