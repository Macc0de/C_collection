#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int page = 0, total_pages = 30;
    int res;
    while (scanf("%d", &page)) {
        printf("\033[0d\033[2J");
        res = (page * 100) / total_pages;
        printf("Achieved --- %d%%\n\n\n", res);
    }

    return 0;
}