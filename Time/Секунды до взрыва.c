#include <stdio.h>
#include <unistd.h>

int main()
{
	int i = 0, seconds;
	printf("Enter the need time in seconds:\n");
	scanf("%d", &seconds);
	
	printf("\n");
	while(seconds > 0)
	{
		printf("\r%d", seconds--);
		fflush(stdout);
		sleep(1);
	}
	printf("\rBOOM");

	return 0;
}
