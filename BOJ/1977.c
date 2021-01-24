#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int add = 0, min = 0;
    for (int i = m; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i == j * j) {
                add += i;
                if (min == 0) min = i;
                break;
            }
        }
    }

    if (add == 0) printf("%d", -1);
    else printf("%d\n%d", add, min);
}