#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int flip = 0;

int cmpr (const void *p1, const void *p2)
{
    int res;
    if (flip) 
        res = ( *(int *)p1 - *(int *)p2);
    else
        res = ( *(int *)p2 - *(int *)p1);
    return res;
}

void print_arr(int *arr, int lim)
{
    int i;
    for (i = 0; i < lim; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    pid_t cpid;
    int i;
    int arr[20];

    for (i = 0; i < (argc - 1); ++i)
        arr[i] = atoi(argv[i+1]);
    
    printf("Lim:%d\n", argc-1);

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) { 
        printf("Child process\t"
               "Array in ascending order\n");
        flip = 0;
        qsort(arr, argc - 1, sizeof(arr[0]), cmpr);
        print_arr(arr, argc - 1);
        exit(EXIT_SUCCESS);
    }
    else {
        int status;
        wait(&status);
        printf("Parent process\t"
               "Array in descending order\n");
        flip = 1;
        qsort(arr, argc - 1, sizeof(arr[0]), cmpr);
        print_arr(arr, argc - 1);
        exit(EXIT_SUCCESS);
    }

}


