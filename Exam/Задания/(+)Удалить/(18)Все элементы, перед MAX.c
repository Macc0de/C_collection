// Максимальных может быть несколько, и перед каждым надо удалить элемент
// 1 2 3 2 1 3 -> 1 3 2 3
struct List* func()
{	
	struct List *cur, *cur_next, *elem;
	int tmp, max;

	if (First == NULL || First->Next == NULL) 
		return First;
	
	max = First->Value; // Поиск максимального
	for (cur = First->Next; cur != NULL; cur = cur->Next)
		if (cur->Value > max) 
			max = cur->Value;
	
	cur = First->Next;
	while(cur != NULL && cur->Value == max) // Если голова стоит перед MAX
	{
		cur = First; // Для препода
		First = First->Next;
		cur = First->Next;
	}

	cur = First;
	if(cur->Next != NULL) // Нужна проверка
	{
		cur_next = First->Next;
		while (cur_next->Next != NULL)
		{
			elem = cur_next->Next;
			if (elem->Value == max)
			{
				cur->Next = cur_next->Next; // cur_next - элемент перед MAX
				cur_next = elem; // Без этого cur_next пропадет
			}
			else
			{ // Итерации
				cur = cur_next;
				cur_next = elem;
			}
		}
	}

	return First;
}
