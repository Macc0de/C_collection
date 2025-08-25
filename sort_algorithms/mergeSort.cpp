//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define ROWS 50000
//#define COLS 15
//#define SIZE (ROWS * COLS)
//
//int x[SIZE];
//
//void merge(int a, int c, int b) {
//    int* res = (int*)malloc((b - a + 1) * sizeof(int));
//    if (res == NULL) {
//        printf("Memory allocation failed!\n");
//        return;
//    }
//
//    int i = a;
//    int j = c;
//    for (int k = 0; k < b - a + 1; k++) {
//        if (i >= c) {  // ���� ����� ����� �����������
//            res[k] = x[j++]; // �������� ���������� �������� ������ �����
//        }
//        else if (j > b) { // ���� ������ ����� �����������
//            res[k] = x[i++]; // �������� ���������� �������� ����� �����
//        }
//        else if (x[i] <= x[j]) {
//            res[k] = x[i++]; // �������� ������� ������� �� ����� �����
//        }
//        else {
//            res[k] = x[j++]; // �������� ������� ������� �� ������ �����
//        }
//    }
//
//    // ��������� ��������������� �������� ������� � �������� ������
//    for (int i = 0; i < b - a + 1; i++) {
//        x[a + i] = res[i];
//    }
//    free(res);
//}
//
//void sort(int a, int b) {
//    if (a >= b)
//        return;
//    
//    int c = (a + b) / 2;
//    sort(a, c); // ��������� ����� �����
//    sort(c + 1, b); // ��������� ������ �����
//    merge(a, c + 1, b); // ���������� ��������������� �����
//}
//
//int main() {
//    FILE* file = fopen("C:\\Users\\Max\\Desktop\\defectogramm.txt", "r");  // ��������� ���� ��� ������
//    if (file == NULL) {
//        printf("File not found!");
//        return 1;
//    }
//
//    // ��������� ������ �� ����� � ����������� ������
//    for (int i = 0; i < SIZE; i++) {
//        if (fscanf(file, "%d", &x[i]) != 1) {  // ������ ����� �� �����
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
//        printf("%d ", x[i]);
//    }
//    printf("\n\nTime - %.3f s\n", elapsed_time);
//
//    return 0;
//}
