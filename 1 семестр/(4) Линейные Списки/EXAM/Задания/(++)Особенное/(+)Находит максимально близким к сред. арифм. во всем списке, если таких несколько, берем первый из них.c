struct List* func()
{
	struct List* cur, *res;
	int sum, count;
	float mid_arifm, min_dif, tmp_dif;
	
	if(First == NULL || First->Next == NULL) 
		return First;
	
	count = 0;
	sum = 0;
	cur = First;
	while(cur != NULL) // Подсчет кол-ва элементов
	{
		count++;
		sum += cur->Value;
		
		cur = cur->Next;
	}
	mid_arifm = (float)sum / (float)count; // Среднее арифметическое
	
	min_dif = mid_arifm - (float)First->Value; // Начальное знач.
	
	if(mid_arifm > First->Value)
		min_dif = mid_arifm - First->Value;
	else
		min_dif = First->Value - mid_arifm;
	
	res = First; // Начальное знач.
	for(cur = First; cur != NULL; cur = cur->Next)
	{
		if(cur->Value < mid_arifm)
			tmp_dif = mid_arifm - cur->Value;
		else
			tmp_dif = cur->Value - mid_arifm;
		
		if(tmp_dif < min_dif) // Первый из макс.
		{
			res = cur;
			min_dif = tmp_dif;
		}
	}
	
	return res;
}
