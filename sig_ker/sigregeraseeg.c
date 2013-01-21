/*
 * example program to show, a signal handler is treated as a normal function
 * 
 * 
 */


#include<stdio.h>
#include<signal.h>

void catcher(int sig);
void catcher2(int sig);
static int cnt=0;

void catcher2(int sig)
{
	if(sig == SIGALRM)
			printf("\n ALarm \n");
	printf("\n 2.  Sig: %d cnt:%d \n",sig, ++cnt);
    return;
}
void catcher(int sig)
{
	if(sig == SIGALRM)
			printf("\n ALarm \n");
	else
	{
		printf("\n Sig: %d cnt:%d \n",sig, ++cnt);
		signal(SIGINT,catcher2);
	}	
	return;
}

int main()
{
	signal(SIGINT,catcher);
	signal(SIGALRM,catcher);
	while(1)
	{
        cnt++;
		printf("\n cnt:%d \n",++cnt);
		sleep(5);
	}

	return 0;
}

