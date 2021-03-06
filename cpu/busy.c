/*
 * File name    : busy.c
 * Author       : crond
 * email        : cronddaemon@gmail.com
 * About File   : The output from this binary will do the following,
 *      1. Recv the num of minute to be in while loop as arg
 *      2. the minute value passed must be less than MAX_MIN. Otherwise not processed
 *
 */
#include<stdio.h>
#include<stdarg.h>
#include<time.h>

#define MAX_MIN 3

int main(int argc,char *argv[])
{
    if(argc != 2){
        printf("Syntax: busy <NUM_OF_MINUTE>\n");
        return 0;
    }
    int min = atoi((char *)argv[1]);
    if(min > MAX_MIN){
        printf("MAX_MIN is :%d \n",MAX_MIN);
        return 0;
    }
    printf("Making busy for %d min\n",min);
    time_t start,curr;
    start = time(NULL);
    curr =  time(NULL);
    while((min*60) > (curr-start)){
        curr =  time(NULL);
    }
    return 0;
}
