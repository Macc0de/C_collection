// 1 2 3 4 5 -> 2 1 4 3 5
struct List* func()
{	
	struct List *current = First, *prev = NULL, *temp;
	int tmp;

	if (First == NULL || First->Next == NULL) 
		return First;

    while (current != NULL && current->Next != NULL) 
	{
        temp = current->Next->Next;
        current->Next->Next = current;

        if (prev != NULL)
            prev->Next = current->Next;
		else // При первом проходе
            First = current->Next;

        current->Next = temp;
		
		// Итерации
        prev = current;
        current = temp;
    }
	
	/* Меняются только инфо части
	struct List* cur = First, *cur_next;
	while (cur != NULL)
	{
		cur_next = cur->Next;
		if (cur_next == NULL)
			break;

		tmp = cur->Value;
		cur->Value = cur_next->Value;
		cur_next->Value = tmp;
		cur = cur_next->Next;
	} 
	*/
	
	return First;
}
