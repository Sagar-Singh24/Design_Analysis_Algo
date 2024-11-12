#include<stdio.h>
#define V 6

int main() {
    int relax, i, j, k;
    int adj[V][V] = { {0, 4, 2, 0, 0, 0},
                      {0, 0, 3, 2, 0, 0},
                      {0, 1, 0, 4, 5, 0},
                      {0, 0, 0, 0, 0, 2},
                      {0, 0, 0, -5, 0, 0},
                      {0, 0, 0, 0, 5, 0} };

    char ver[V] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char source = 'A';
    int dist[V];
    for (i = 0; i < V; i++) {
        dist[i] = 10000;
    }

    dist[source - 'A'] = 0;
    printf("Initial distance array:\n");
    printf("Iteration\t");
    for (i = 0; i < V; i++) {
        printf("%c\t", ver[i]);
    }
    printf("\n");

    for (i = 0; i < V-1; i++) {
        printf("%d\t\t", i+1);
        for (j = 0; j < V; j++) {
            for (k = 0; k < V; k++) {
                if (adj[j][k] != 0 && dist[j] + adj[j][k] < dist[k]) {
                    dist[k] = dist[j] + adj[j][k];
                }
            }
        }

        for (int l = 0; l < V; l++) {
            if (dist[l] == 10000)
                printf("INF\t");
            else
                printf("%d\t", dist[l]);
        }
        printf("\n");
    }

    for (j = 0; j < V; j++) {
        for (k = 0; k < V; k++) {
            if (adj[j][k] != 0 && dist[j] + adj[j][k] < dist[k]) {
                printf("Graph contains a negative weight cycle\n");
                return 0;
            }
        }

    }
    printf("\nFinal distances from source %c:\n", source);
    for (i = 0; i < V; i++) {
        printf("%c\t\t%d\n", ver[i], dist[i]);
    }

    return 0;
}