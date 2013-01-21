/*
 * example pgm to show , the intr sys call
 * in linux, dont resume the sys call again.
 *
 * Verify: after the child PID print, before 5 sec, giving Ctrl+c will cause
 * the child to terminate [ and catches the signal too ] from sleep, before it 
 * completes.
 * leave it un-touched for more than 5 sec, sleep will complete and wont be 
 * any error code. [ atleat, not through this proc ]
 */
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<errno.h>

void catcher(int sig)
{
    if(sig == SIGINT)
        printf("\n %d: SIGINT sig:%d \n",getpid(),sig);
    else if(sig == SIGCHLD)
        printf("\n %d: SIGCHLD sig:%d \n",getpid(),sig);
    else
        printf("\n %d: sig:%d \n",getpid(),sig);
}
int main()
{
    pid_t parPid=0;
   parPid = getpid();
   printf("\n Parent PID: %d \n",parPid);
   signal(SIGCHLD,catcher);
   signal(SIGINT,catcher);
   if((fork())== 0)
   {
     int ret=0;
     printf("\n Child Pid:%d \n",getpid());
     errno = 0;
     ret = sleep(5);
     printf("\n Child Exitting. Ret:%d Err:%d %s \n",ret,errno,strerror(errno));
     _exit(0);
   } 
   while(1)
       usleep(5000);

    return 0;
}
