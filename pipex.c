#include "pipex.h"
#include "libft/libft.h"

int main(int argc, char **argv, char **envp)
{
    int len;
    if (argc != 2)
    {
        printf("Need 1 arg\n");
        return (-1);
    }
    len = ft_strlen(argv[1]);
    printf("Argv = %s : %d\n", argv[1], len);
    return (0);
}