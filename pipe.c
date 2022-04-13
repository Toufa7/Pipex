#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int ac, char *av[])
{
    int p[2];
    pid_t pid;

    if (pipe(p) == -1)
    {
        perror("Error\n");
        exit(1);
    }
    pid = fork();
    if (pid == 0)
    {
        // Child
        int x;
        read(p[0], &x, sizeof);

    }

}