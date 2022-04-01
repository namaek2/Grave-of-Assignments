#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pid;
    int arrival_time;
    int code_bytes;
} process;

int main(int argc, char * argv[])
{
    int i = 0;
    int num1=0;
    int num2=0;

    process data;

    while(fread(&data, sizeof(process), 1, stdin) ==1)
    {
        fprintf(stdout, "%d %d %d\n", data.pid, data.arrival_time, data.code_bytes);
        
        for(i=0; i<data.code_bytes/2; i++)
        {
            fread(&num1, sizeof(char), 1, stdin);
            fread(&num2, sizeof(char), 1, stdin);
            printf("%d %d\n", num1, num2);
        }
            
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pid;
    int arrival_time;
    int code_bytes;
} process;

int main(int argc, char * argv[])
{
    int i = 0;
    int num1=0;
    int num2=0;

    process data;

    while(fread(&data, sizeof(process), 1, stdin) ==1)
    {
        fprintf(stdout, "%d %d %d\n", data.pid, data.arrival_time, data.code_bytes);
        
        for(i=0; i<data.code_bytes/2; i++)
        {
            fread(&num1, sizeof(char), 1, stdin);
            fread(&num2, sizeof(char), 1, stdin);
            printf("%d %d\n", num1, num2);
        }
            
    }

    return 0;
}
