//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <time.h>
//
//#define SIZE 392304
//
//float x[SIZE];
//
//void swap(int k, int j) {
//    if (k == j)
//        return;
//    x[k] = x[k] + x[j];
//    x[j] = x[k] - x[j];
//    x[k] = x[k] - x[j];
//}
//
//int part(int l, int r) {
//    int m = l;  // Индекс для элементов < pivot
//    float pivot = x[r];  // Опорный элемент
//    for (int i = l; i < r; i++) {  // Перебираем массив
//        if (x[i] <= pivot) {  // <= чтобы сортировка была стабильнее
//            swap(i, m);
//            m++;
//        }
//    }
//    swap(m, r);  // Ставим pivot на правильное место
//    return m;
//}
//
//
//void fs(int l, int r) {
//    while (l < r) {  // Используем цикл вместо глубокого рекурсивного вызова
//        int k = part(l, r);
//
//        // Сортируем сначала меньшую часть, чтобы стек был меньше
//        if (k - l < r - k) {
//            fs(l, k - 1); // Сортируем меньшую часть
//            l = k + 1;  // Сортируем вторую часть в том же вызове (без рекурсии)
//        }
//        else {
//            fs(k + 1, r); // Сортируем большую часть
//            r = k - 1; // Сортируем меньшую часть
//        }
//    }
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
//    fs(0, SIZE - 1);
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