struct List* func()
{	
	struct List *T, *T1, *T2, *T3;

	if (First == NULL || First->Next == NULL) // Вопрос
		return First;

	// (Случай) Если второй элемент равен голове, то удаляем его
	T = First->Next;
	if (T->Value == First->Value)
		First->Next = T->Next;
	
	T1 = First;
	T2 = T1->Next;
	
	if(T2 != NULL) // Если удаляется второй элемент
		T3 = T2->Next;
	
	while (T1 != NULL && T2 != NULL && T3 != NULL)
	{
		if (T1->Value + T3->Value == T2->Value) // T2 - средний элемент м/ду ними
			T1->Next = T2->Next; // Удаление
		else
			T1 = T1->Next;
		
		T2 = T1->Next;
		T3 = T2->Next;
	}
	
	// (Случай) Если последний элемент списка равен предыдущему, то удаляем его
	for (T = First; T != NULL && T->Next != NULL; T = T->Next) // && T->Next
	{
		if (T->Next->Next == NULL)
		{
			T1 = T->Next; // T1 - последний элемент
			break;
		}
	}
	
	if (T->Value == T1->Value) // Удаление
		T->Next = NULL;

	return First;
}
