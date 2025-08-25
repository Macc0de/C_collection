struct List* func(int k)
{	
	struct List *cur, *cur_next;
	int count = 0;
	
	if (First == NULL || k < 1) // Индексация с 1
		return First;

	for (cur = First; cur != NULL; cur = cur->Next)
		count++; // Кол-во элементов в спике

	if (k > count) // Нет такого элемента
		return First;

	if (First->Next == NULL && k == 1) // Если в списке только 1 элемент
		return First;

	if (First->Next != NULL && k == 1) // Удаление первого элемента
	{
		cur = First; // Для препода
		First = First->Next;
		return First;
	}

	if (k == 2) // Удаление 2-го элемента
	{
		cur = First->Next; // Для препода
		First->Next = cur->Next;
	}
	
	cur = First;
	cur_next = cur->Next;
	count = 2;
	while (count != k) // Удаление 3-го и тд элемента
	{
		cur = cur->Next;
		cur_next = cur_next->Next;
		
		count++;
		
		if (count == k) // Удаление
			cur->Next = cur_next->Next;
	}

	return First;
}
