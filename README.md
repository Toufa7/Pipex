Pipex a 1337's a project that aims to teach you the concept of processes and pipe and the way commands using '|' can communicate with each others
let's take an example

        $ls | wc -l
        
so the list command lists all files and directories and gives his output to the second command and then the output print on the STDOUT

The three important phases to understand the project are follows:

# Fork

[Man Fork](https://man7.org/linux/man-pages/man2/fork.2.html)

The fork() function creates a new child process by sharing the same code as the calling process and duplicating the calling process's data to give the child process an exact copy. Most process resources are inherited.

        #include <unistd.h>
        #include <stdio.h>

        int main(void)
        {
                pid_t   pid;

                pid = fork();

                if (pid == 0)
                {
                        printf("I'm a Child Process\n");
                }
                return (0);
        }

Good question well be why we need to creat a process ?!

For this case, we need to create a process that will handle the running of the first command and so on ...

# Execve

[Man Execve](https://man7.org/linux/man-pages/man2/execve.2.html)

Forking creates a process but it is not enough to run a new program


        #include <unistd.h>
        #include <stdio.h>
       
        int main(int ac, char *av[], char **env)
        {
            pid_t   pid;
        
            pid = fork();
        
            if (pid == 0)
            {
                execve("/bin/ls", &av[0], env);
            }
            return (0);
        }
        
This program will run a process and will list for us files and directories in the current directory and take as argument the option for command like "-la"

# Wait

[Man Wait](https://man7.org/linux/man-pages/man2/wait.2.html)

[See Also Waitpid](https://man7.org/linux/man-pages/man3/waitpid.3p.html)

While the child is executing a new program, the parent process normally waits for the child process to die.
It picks the exit status of the child before it does something else.

        #include <unistd.h>
        #include <stdio.h>
        
        int main(int ac, char *av[], char **env)
        {
            pid_t   pid;
        
            pid = fork();
        
            if (pid == 0)
            {
                execve("/bin/ls", &av[0], env);
            }
            waitpid(pid, NULL, 0);
            return (0);
        }
        



# What's a Process :

Process A process is defined as an “instance” of an executing program

Splitting the path by : and check it the command passed is located to some of the paths then return it

This function well return the directories to be searched to find a command */

Creating a Child and start executing the command passed av[1] by the path return it before


O_RDWR: read and write
O_CREAT: create file if it doesn’t exist
If the file exists and is a regular file, and the file is successfully opened O_RDWR or O_WRONLY, its length shall be truncated to 0, and the mode and owner shall be unchanged. It shall have no effect on FIFO special files or terminal device files. Its effect on other file types is implementation-defined. The result of using O_TRUNC with O_RDONLY is undefined.
O_TRUNC If the file already exists and is a regular file, then truncate it to zero length, destroying any existing data. 

        dup2(fd[WRITE_END], STDOUT_FILENO);
        close(fd[WRITE_END]);

        dup2(fd[READ_END], STDIN_FILENO);
        close(fd[READ_END]);

The fork() system call allows one process (the parent), to create a new process (the child)
This is done by making the new child process an (almost) exact duplicate of the parent: the child obtains copies of the parent’s stack, data, heap,
and text segments

The exit(status) library function terminates a process, The status argument is an integer that
determines the termination status for the process.


The wait(&status) system call has two purposes.

- First, if a child of this process has not yet terminated by calling exit()
then wait() suspends execution of the process until one of its children has terminated. 
- Second, the termination status of the child is returned in the status argument of wait().



std IN   = 0
std OUT  = 1
std ERR  = 1


The execve(pathname, argv, envp) 
pathname = 
argv = 
envp = 
system call loads a new program (pathname, with argument list argv, and environment list envp) into a process’s memory.
The most frequent use of execve() is in the child produced by a fork(), although
it is also occasionally used in applications without a preceding fork().
Never returns on success; returns –1 on error


fork() and exec() into a single operation—a so-called spawn—that creates a new process that then executes a specified program


creating multiple processes can be a useful way of dividing up a task




The dup() call takes oldfd, an open file descriptor, and returns a new descriptor that 
refers to the same open file description


int dup2(int oldfd, int newfd);

Makes a duplicate of the file descriptor given in oldfd using
the descriptor number supplied in newfd. If the file descriptor specified in newfd is
already open, dup2() closes it first.


int access(const char *pathname, int mode) ==>  Checking File Accessibility
Returns 0 if all permissions are granted, otherwise –1
The access() system call checks the accessibility of the file specified in pathname

access modes

    F_OK => Does the file exist?
    R_OK => Can the file be read?
    W_OK => Can the file be written?
    X_OK => Can the file be executed?

Waiting on a Child Process ;

In many applications where a parent creates child processes, it is useful for the
parent to be able to monitor the children to find out when and how they terminate.
This facility is provided by wait() and a number of related system calls.


The wait() system call waits for one of the children of the calling
process to terminate and returns the termination status.

waitpid was designed to ;

If a parent process has created multiple children, it is not possible to wait() for the
completion of a specific child; we can only wait for the next child that terminates

# Ressources

https://www.rozmichelle.com/pipes-forks-dups/

https://www.gnu.org/software/libc/manual/html_node/Processes.html

http://www.qnx.com/developers/docs/7.1/

The Amazing book by Michael Kerrisk

The Linux Programming Interface: A Linux and UNIX System Programming Handbook

https://en.wikipedia.org/wiki/The_Linux_Programming_Interface
