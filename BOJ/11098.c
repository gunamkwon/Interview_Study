#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct playerlist {
    int money;
    char name[21];
}playerlist;

int main()
{
    int n, p;
    scanf("%d", &n);

    playerlist* max = (playerlist*)malloc(sizeof(playerlist) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        playerlist* fc = (playerlist*)malloc(sizeof(playerlist) * p);

        for (int j = 0; j < p; j++) {
            scanf("%d %s", &(fc[j].money), fc[j].name);
            if (max[i].money < fc[j].money)  max[i] = fc[j];
        }
        free(fc);
    }
    for (int i = 0; i < n; i++)
        printf("%s\n", max[i].name);
    free(max);
}