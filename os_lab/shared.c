#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/wait.h>  
#include <unistd.h>   
#define SHMSIZE 27
int main() {
   int shmid;
   char *shm;

   if(fork() == 0) {
      shmid = shmget(2009, SHMSIZE, 0);
      shm = shmat(shmid, 0, 0);
      char *s = (char *) shm;
      *s = '\0';  
      int i;
      for(i=1; i<5; i++) {
         int n;  
         printf("Enter number<%i>: ", i);
         scanf("%d", &n);
         sprintf(s, "%s%d", s, n);  
      }
      printf ("Child wrote <%s>\n",shm);
      shmdt(shm);
   }
   else {
      shmid = shmget(2009, SHMSIZE, 0666 | IPC_CREAT);
      shm = shmat(shmid, 0, 0);
      wait(NULL);
      printf ("Parent reads <%s>\n",shm) ;
      shmdt(shm);
      shmctl(shmid, IPC_RMID, NULL);
   }
   return 0;
}
