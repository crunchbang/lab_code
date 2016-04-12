#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();
    if (pid > 0) 
        printf("Parent process of child %d\n", pid);
    else if (!pid)
        printf("Child process\n");
    else if (pid == -1)
        perror("fork");

    return 0;
}

