//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define ROWS 50000
//#define COLS 15
//#define SIZE ROWS * COLS
//
//int x[SIZE];
//
//void countSort() {
//    int min = x[0], max = x[0];
//    for (int i = 1; i < SIZE; i++) {
//        if (x[i] > max) {
//            max = x[i];
//        }
//        if (x[i] < min) {
//            min = x[i];
//        }
//    }
//
//    int range = max - min + 1;
//    int* count = (int*)calloc(range, sizeof(int)); // ћассив дл€ подсчета
//    if (count == NULL) {
//        printf("Memory allocation failed!\n");
//        return;
//    }
//
//    // «аполн€ем массив count, сдвигаем индексы так, чтобы все они стали положительными
//    for (int i = 0; i < SIZE; i++) {
//        count[x[i] - min]++;
//    }
//
//    // ¬оссоздаем отсортированный массив
//    int k = 0;
//    for (int i = 0; i < range; i++) {
//        while (count[i] > 0) {
//            x[k++] = i + min;
//            count[i]--;
//        }
//    }
//    free(count);
//}
//
//int main() {
//    FILE* file = fopen("C:\\Users\\Max\\Desktop\\defectogramm.txt", "r");
//    if (file == NULL) {
//        printf("File not found!");
//        return 1;
//    }
//
//    // —читываем данные из файла в статический массив
//    for (int i = 0; i < SIZE; i++) {
//        if (fscanf(file, "%d", &x[i]) != 1) {
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
//	printf("Sorted Data:\n");
//    for (int i = 0; i < SIZE; i++) {
//        printf("%d ", x[i]);
//    }
//    printf("\n\nTime - %.3f s\n", elapsed_time);
//
//    return 0;
//}