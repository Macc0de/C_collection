#include <stdio.h>

int main()
{
	// Для четного кол-ва элементов (1)
	int mas[] = {1,2,3,3,2,1};
	int i = 0, j = 5, flag = 0;
	
	// Комментарии - для нечетного кол-ва элементов (2)
	while(i < j)
	{
		//j--;
		if (mas[i++] != mas[j--]) // mas[i] != mas[j]
		{
			flag = 1;
			break;
		}
		//i++;
	}
	
	if (!flag)
	{
		printf("Yes!");
		return 1;
	}
	else
		printf("no.");
	
	return 0;
}
