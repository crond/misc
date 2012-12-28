#include<stdio.h>
#include<asm/msr.h>


int main()
{
    unsigned long ini,end;
    rdtscl(ini);rdtscl(end);
    printf("\n Time Diff:[%ld - %ld]= %d",end,ini,(end-ini));
    return 0;

}
