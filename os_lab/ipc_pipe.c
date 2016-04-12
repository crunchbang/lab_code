#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    pid_t cpid;
    int pipefd[2];

    if (pipe(pipefd) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if ((cpid = fork()) < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (cpid > 0) {
        char *msg = "Hello, pipe\n";

        close(pipefd[0]);
        write(pipefd[1], msg, strlen(msg));
    }
    else {
        char line[100];
        ssize_t n;

        close(pipefd[1]);
        n = read(pipefd[0], line, sizeof(line));
        if (n > 0) 
            write(STDOUT_FILENO, line, n);
    }

    return 0;
}
