#define VERTICE 5
#define INF 999

typedef struct {
    int numV;
    int dist[VERTICE][VERTICE];
    int next[VERTICE][VERTICE];
} Grafos;

void insere(Grafos* g, int elem[VERTICE][VERTICE]);
void floydWarshall(Grafos* g);
void consultaCaminho(Grafos* g, char origemC, char destinoC);
void imprime(Grafos* g);