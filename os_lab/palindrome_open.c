#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>

#define MAXSIZE 10000

bool is_palindrome(char *str) 
{
    char *p1;
    char *p2;
    if (!str || !(*str))
        return false;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        if (*p2 != *p1)
            return false;
    }
    return true;
}
int main(int argc, char* argv[]) 
{
    int rfd, wfd;
    char buf[MAXSIZE];
    char *token;
    char *delim = "., ";
    ssize_t nread;
    if (argc < 3) {
        printf("Usage:%s <inputfile> <outputfile>\n", argv[0]);
        return 0;
    }
    rfd = open(argv[1], O_RDONLY);
    wfd = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, 0640);
    //equivalent to creat("path", mode_t mode)

    if (rfd == -1 || wfd == -1) {
        printf("%s\n", strerror(errno));
        return -1;
    }

    while ((nread = read(rfd, buf, MAXSIZE-1)) > 0) {
        if (nread == -1) {
            printf("%s\n", strerror(errno));
            return -1;
        }
        buf[nread] = '\0';
        token = strtok(buf, delim);
        while (token != NULL) {
            if (is_palindrome(token)) { 
                write(wfd, token, strlen(token)); 
                token = "\n";
                write(wfd, token, strlen(token)); 
            }
            token = strtok(NULL, delim);
        }
    }

    close(rfd);
    close(wfd);
    return 0;
}
