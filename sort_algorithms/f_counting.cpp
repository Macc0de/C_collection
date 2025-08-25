//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define SIZE 392304
//
//float x[SIZE];
//
//void countSort() {
//    int min = (int)(x[0] * 100), max = (int)(x[0] * 100);
//    for (int i = 1; i < SIZE; i++) {
//        int val = (int)(x[i] * 100);
//        if (val > max) 
//            max = val;
//        if (val < min) 
//            min = val;
//    }
//
//    // Создаем вспомогательный массив для подсчета
//    // Размер массива count будет зависеть от диапазона значений
//    int range = max - min + 1;
//    int* count = (int*)calloc(range, sizeof(int));  // Массив для подсчета
//    if (count == NULL) {
//        printf("Memory allocation failed!\n");
//        return;
//    }
//
//    // Заполняем массив count, сдвигаем индексы так, чтобы все они стали положительными
//    for (int i = 0; i < SIZE; i++) {
//        count[(int)(x[i] * 100) - min]++; // Индекс сдвигается на значение min
//    }
//
//    // Воссоздаем отсортированный массив
//    int k = 0;
//    for (int i = 0; i < range; i++) {
//        while (count[i] > 0) {
//            x[k++] = (i + min) / 100.0f;  // Восстанавливаем исходное значение
//            count[i]--;
//        }
//    }
//    free(count);
//}
//
//int main() {
//    FILE* file = fopen("C:\\Users\\Max\\Desktop\\temperatures.txt", "r");  // Открываем файл для чтения
//    if (file == NULL) {
//        printf("File not found!");
//        return 1;
//    }
//
//    // Считываем данные из файла в статический массив
//    for (int i = 0; i < SIZE; i++) {
//        if (fscanf(file, "%f", &x[i]) != 1) {
//            printf("Error with %d\n", i + 1);
//            fclose(file);
//            return 1;
//        }
//    }
//    fclose(file);
//
//    clock_t start = clock();
//
//    countSort();
//
//    clock_t end = clock();
//    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
//
//    printf("Sorted Data:\n");
//    for (int i = 0; i < SIZE; i++) {
//        printf("%.2f ", x[i]);
//    }
//    printf("\n\nTime - %.3f s\n", elapsed_time);
//
//    return 0;
//}