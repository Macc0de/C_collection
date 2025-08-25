//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <time.h>
//
//#define ROWS 50000
//#define COLS 15
//#define SIZE ROWS * COLS
//
//int x[SIZE];
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
//    int m = l;
//    int pivot = x[r]; // Опорный элемент
//    for (int i = l; i < r; i++) {
//        if (x[i] <= pivot) {
//            swap(i, m);
//            m++;
//        }
//    }
//    swap(m, r); // Ставим pivot на правильное место
//    return m;
//}
//
//
//void fs(int l, int r) {
//    while (l < r) {
//        int k = part(l, r);
//        if (k - l < r - k) {
//            fs(l, k - 1); // Сортируем меньшую часть
//            l = k + 1;
//        }
//        else {
//            fs(k + 1, r); // Сортируем большую часть
//            r = k - 1;
//        }
//    }
//}
//
//int main() {
//    FILE* file = fopen("C:\\Users\\Max\\Desktop\\defectogramm.txt", "r");  // Открываем файл для чтения
//    if (file == NULL) {
//        printf("File not found!");
//        return 1;
//    }
//
//    // Считываем данные из файла в статический массив
//    for (int i = 0; i < SIZE; i++) {
//        if (fscanf(file, "%d", &x[i]) != 1) {  // Читаем числа из файла
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
//        printf("%d ", x[i]);
//    }
//    printf("\n\nTime - %.3f s\n", elapsed_time);
//
//    return 0;
//}