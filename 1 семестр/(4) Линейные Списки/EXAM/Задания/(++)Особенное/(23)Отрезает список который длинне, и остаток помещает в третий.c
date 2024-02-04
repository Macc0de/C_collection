// Дано 2 Глоб.ук.
struct List* func()
{
    struct List *F3 = NULL, *cur;
    int k, k1, k2;
    k = k1 = k2 = 0;
	
	// Подсчет элементов
    for (cur = F1; cur != NULL; cur = cur->Next)
        k1++;
    for (cur = F2; cur != NULL; cur = cur->Next)
        k2++;

    if (k1 == k2) // Кол-во элементов равные
        return F3;
	
    if (k1 > k2)
    {
		if(F2 == NULL) // Если второй список пуст
		{
			F3 = F1;
			F1 = NULL; // В третий список добавит полностью первый
			return F3;
		}
        for (cur = F1; ; cur = cur->Next)
        {
            k++;
            if (k == k2)
            {
                F3 = cur->Next; // Кроме самого первого элемента
                cur->Next = NULL; // Удаление из первого списка
                return F3;
            }
        }
    }
    else // k2 > k1
    {
		if(F1 == NULL) // Если первый список пуст
		{
			F3 = F2;
			F2 = NULL; // В третий список добавит полностью второй
			return F3;
		}
        for (cur = F2; ; cur = cur->Next)
        {
            k++;
            if (k == k1)
            {
                F3 = cur->Next; // Кроме самого первого элемента
                cur->Next = NULL; // Удаление из второго списка
                return F3;
            }
        }
    }
}
