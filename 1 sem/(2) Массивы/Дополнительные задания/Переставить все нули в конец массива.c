#include <stdio.h>
 
 // Функция для нахождения и перемещения всех нулей массива в его конец
void reorder(int A[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        // Перезаписываем в массив все элементы отличные от 0
        if (A[i] != 0) 
            A[k++] = A[i];
    }
 
    // Запись оставшихся элементов в массив(нулями)
    for (int i = k; i < n; i++) // От последнего индекса k до конца
        A[i] = 0;
}
 
int main()
{
    int A[] = {6, 0, 8, 2, 3, 0, 4, 0, 1};
    int n = sizeof(A) / sizeof(A[0]);
 
    reorder(A, n);
 
    for (int i = 0; i < n; i++) 
        printf("%d ", A[i]);
 
    return 0;
}
