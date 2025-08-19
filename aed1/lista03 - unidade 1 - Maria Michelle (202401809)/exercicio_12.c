#include <stdio.h>

int resultado(int x, int y, int mapa[100][100][2], int visitado[100][100]) {
    if (x == 0 && y == 0) {
        return 1;
    }
    if (visitado[x][y]) {
        return 0;
    }
    visitado[x][y] = 1;

    int proximoX = mapa[x][y][0];
    int proximoY = mapa[x][y][1];

    return resultado(proximoX, proximoY, mapa, visitado);
}

int main() {
    int m, n, x, y, i , j;
    int mapa[100][100][2];
    int visitado[100][100] = {0};

    do {
        scanf("%d %d", &m, &n);
    } while (m < 1 || n < 1 || m > 100 || n > 100);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d %d", &mapa[i][j][0], &mapa[i][j][1]);
        }
    }

    scanf("%d %d", &x, &y);

    if (resultado(x, y, mapa, visitado)) {
        printf("VENCE\n");
    } else {
        printf("PRESO\n");
    }

    return 0;
}
