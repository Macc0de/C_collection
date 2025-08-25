//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define SIZE 392304
//
//float x[SIZE];
//
//void merge(int a, int c, int b) {
//    float* res = (float*)malloc((b - a + 1) * sizeof(float));
//    if (res == NULL) {
//        printf("Memory allocation failed!\n");
//        return;
//    }
//
//    int i = a;
//    int j = c;
//    for (int k = 0; k < b - a + 1; k++) {
//        if (i >= c) {  // Если левая часть закончилась
//            res[k] = x[j++];  // Копируем оставшиеся элементы правой части
//        }
//        else if (j > b) {  // Если правая часть закончилась
//            res[k] = x[i++];  // Копируем оставшиеся элементы левой части
//        }
//        else if (x[i] <= x[j]) {
//            res[k] = x[i++];  // Копируем меньший элемент из левой части
//        }
//        else {
//            res[k] = x[j++];  // Копируем меньший элемент из правой части
//        }
//    }
//
//    // Переносим отсортированные элементы обратно в основной массив
//    for (int i = 0; i < b - a + 1; i++) {
//        x[a + i] = res[i];
//    }
//    free(res);
//}
//
//// Рекурсивная функция сортировки
//void sort(int a, int b) {
//    if (a >= b)
//        return;  // Базовый случай: если уже один элемент
//    
//    int c = (a + b) / 2;  // Середина
//    sort(a, c);             // Сортируем левую часть
//    sort(c + 1, b);         // Сортируем правую часть
//    merge(a, c + 1, b);     // Объединяем отсортированные части
//}
//
//int main() {
//    FILE* file = fopen("C:\\Users\\Max\\Desktop\\temperatures.txt", "r");
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
//    sort(0, SIZE - 1);
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
