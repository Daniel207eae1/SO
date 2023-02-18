#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
  
// Driver code
int main()
{
    int pid, pid1, pid2;

    pid = fork();

    if (pid == 0) {
        int b=0;
        for (int i = 0; i <= 5; i++)
        {
            b+=i;
            printf("child[1] --> pid = %d and ppid = %d, el valor de i es: %d\n",
               getpid(), getppid(),b);
        }
    }
  
    else {
        wait(NULL);
        pid1 = fork();
        if (pid1 == 0) {
            int b=0;
            for (int i = 0; i <= 5; i++)
            {    
                b+=i;
                printf("child[2] --> pid = %d and ppid = %d, el valor de i es: %d\n",
                getpid(), getppid(),b);
            }
        }
        else {
            wait(NULL);
            pid2 = fork();
            if (pid2 == 0) {
                int b=0;
                for (int i = 0; i <= 5; i++)
                {
                    b+=i;
                    printf("child[3] --> pid = %d and ppid = %d, el valor de i es: %d\n",
                    getpid(), getppid(),b);
                }
            }

            else {
                wait(NULL);
                printf("parent --> pid = %d\n", getpid());
            }
        }
    }
  
    return 0;
}