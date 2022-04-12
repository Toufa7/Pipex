#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
    (void)ac;
    pid_t p1;
    int status;
    pid_t pid = 0;
    char *cmd = "/usr/bin/wc";
    int rslt = 15 + 5;

    p1 = fork();
    if (p1 == 0)
    {
        printf("I'm a Child Processes my PID[%d]\n",getpid());
        printf("Starting Executing %s\n", cmd);
        printf("-----------------------\n");
        execve(cmd, av, NULL));
        sleep(10);
        printf("Exiting ... %s\n", cmd);
		exit(1);
        return (rslt);
    }
    else

    {
        pid = waitpid(p1, &status, 0);
    
    }

    printf("Parent pid = %d\n",getpid());
    printf("Child pid = %d , Return status : %d\n", pid, WEXITSTATUS(status));
    return (0);
}