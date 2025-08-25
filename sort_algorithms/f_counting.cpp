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
//    // ������� ��������������� ������ ��� ��������
//    // ������ ������� count ����� �������� �� ��������� ��������
//    int range = max - min + 1;
//    int* count = (int*)calloc(range, sizeof(int));  // ������ ��� ��������
//    if (count == NULL) {
//        printf("Memory allocation failed!\n");
//        return;
//    }
//
//    // ��������� ������ count, �������� ������� ���, ����� ��� ��� ����� ��������������
//    for (int i = 0; i < SIZE; i++) {
//        count[(int)(x[i] * 100) - min]++; // ������ ���������� �� �������� min
//    }
//
//    // ���������� ��������������� ������
//    int k = 0;
//    for (int i = 0; i < range; i++) {
//        while (count[i] > 0) {
//            x[k++] = (i + min) / 100.0f;  // ��������������� �������� ��������
//            count[i]--;
//        }
//    }
//    free(count);
//}
//
//int main() {
//    FILE* file = fopen("C:\\Users\\Max\\Desktop\\temperatures.txt", "r");  // ��������� ���� ��� ������
//    if (file == NULL) {
//        printf("File not found!");
//        return 1;
//    }
//
//    // ��������� ������ �� ����� � ����������� ������
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