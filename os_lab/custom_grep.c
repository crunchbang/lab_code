#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void custom_grep(char *substr, char *file)
{
    size_t len = 0;
    char *line = NULL;
    FILE *fp = fopen(file, "r");

    if (fp == NULL) {
        printf("Error");
        exit(1);
    }

    while (getline(&line, &len, fp) != -1) {
        if (strstr(line, substr) != NULL)
            printf("->%s", line);
    }
}

int main(int argc, char* argv[])
{
    if (argc == 3) {
        custom_grep(argv[1], argv[2]);
    }
    else if (argc == 1) {
        printf("Usage: custom_grep <pattern> <filename>\n");
        return 0;
    }

    return 0;
}
