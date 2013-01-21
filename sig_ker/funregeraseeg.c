#include<stdio.h>
#include<signal.h>

void foo1()
{
	static int cnt=0;
	printf("\n foo:cnt:%d \n",cnt++);
	return;
}
void catcher(int sig)
{
	static int cnt=0;
	if(sig == SIGALRM)
			printf("\n ALarm \n");
    else if(sig == SIGINT)
	{
		printf("\n Sig: %d cnt:%d \n",sig, cnt++);
	    foo1();
    }	
	return;
}

int main()
{
	signal(SIGINT,catcher);
	while(1)
	{
		foo1();
        sleep(10);
        printf("\n After sleep\n");
	}

	return 0;
}

