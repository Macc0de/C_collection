#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void cterm(const char *string) 
{
    int len = strlen(string);
    for (int i = 0; i < len; i++)
        printf("\b"); 
}

int main() 
{
    while (1) 
	{
        time_t now = time(NULL); // get the local time
        char curr_time[15];
		
        strftime(curr_time, 15, "%H:%M:%S", localtime(&now)); // write current time to <curr_time>
        printf("%s", curr_time);
		
        fflush(stdout);
        sleep(1); 
        cterm(curr_time); // clear the output
    }
	
    return 0;
}
