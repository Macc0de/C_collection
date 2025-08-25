#include <stdio.h> 
#include <unistd.h> 

int main()
{  
	int i = 0;
	while (1)
	{    
		printf("\r%d",i); // \r - возврат каретки на начало строки
		fflush(stdout); // Сброс буфера - строка отобразится в консоли
		sleep(1);
		i++;
	}
   
	return 0;
} 
