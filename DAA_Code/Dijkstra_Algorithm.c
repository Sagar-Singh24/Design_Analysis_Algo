#include <stdio.h>
#include <stdlib.h>
#define V 6
#define INF 9999

void printAllIterations(int dijcom[][V], char vertex[])
{
    printf("\nAll Iterations:\n");

    printf("\t");
    for (int i = 0; i < V; i++)
    {
        printf("%c\t", vertex[i]);
    }
    printf("\n");

    for (int i = 0; i < V; i++)
    {
        printf("%c\t", vertex[i]);
        for (int j = 0; j < V; j++)
        {
            if (dijcom[i][j] == INF)
            {
                printf("inf \t");
            }
            else
            {
                printf("%d \t", dijcom[i][j]);
            }
        }
        printf("\n");
    }
}

void printPath(int parent[], int v, char vertex[])
{
    if (parent[v] == -1)
    {
        printf("%c", vertex[v]);
        return;
    }
    printPath(parent, parent[v], vertex);
    printf(" -> %c", vertex[v]);
}

void printSolution(int dist[], int parent[], char vertex[], int visitedSequence[], int src, int dest)
{
    printf("\nSource: %c\nDestination: %c\n", vertex[src], vertex[dest]);
    printf("Shortest Distance: %d\n", dist[dest]);
    printf("Path: ");
    printPath(parent, dest, vertex);
    printf("\nVisit Sequence: %d\n", visitedSequence[dest]);
}

int main()
{
    char vertex[V] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int graph[V][V] = {
        {0, 3, 2, 5, 0, 0},
        {3, 0, 0, 2, 4, 0},
        {2, 0, 0, 2, 0, 1},
        {5, 2, 2, 0, 3, 0},
        {0, 4, 0, 3, 0, 2},
        {0, 0, 1, 0, 2, 0}};

    int dijcom[V][V];
    int dist[V];
    int visited[V];
    int visitedSequence[V];
    int parent[V];
    int i, j, k, u;
    int seq = 1;
    int src, dest;
    printf("Enter the source vertex : ");
    scanf("%d", &src);
    printf("Enter the destination vertex : ");
    scanf("%d", &dest);

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            dijcom[i][j] = INF;
        }
        dist[i] = INF;
        visited[i] = 0;
        visitedSequence[i] = -1;
        parent[i] = -1;
    }
    dist[src] = 0;
    
    for (i = 0; i < V; i++)
    {
        if (i == src)
        {
            dijcom[0][i] = 0;
        }
        else
        {
            dijcom[0][i] = INF;
        }
    }

    for (k = 0; k < V - 1; k++)
    {
        int min = INF;
        for (i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }
        visited[u] = 1;
        visitedSequence[u] = seq++;

        for (j = 0; j < V; j++)
        {
            if (!visited[j] && graph[u][j] != 0 && dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
                parent[j] = u;
            }
        }
        for (i = 0; i < V; i++)
        {
            if (dist[i] != INF && !visited[i])
            {
                dijcom[k + 1][i] = dist[i];
            }
        }
    }
    for (i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            visitedSequence[i] = seq++;
        }
    }

    printAllIterations(dijcom, vertex);
    printSolution(dist, parent, vertex, visitedSequence, src, dest);

    return 0;
}