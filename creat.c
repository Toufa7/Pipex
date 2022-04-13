#include <stdio.h>
#include <fcntl.h>

int main(int ac, char *av[])
{
    int fd1;
    if (ac > 0)
    {
        fd1 = open(av[1], O_CREAT, 0777);
        for (int i = 0 ; av[i] ; i++)
        {
            printf("%s --> %d\n",av[i],i);
        }
    }
}
