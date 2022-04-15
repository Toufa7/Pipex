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