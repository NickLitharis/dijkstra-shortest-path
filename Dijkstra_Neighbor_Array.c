#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

int n;  // Number of vertices

// Function to find the vertex with the smallest distance not yet processed
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Recursive function to print the path from source to a given vertex
void printPath(int parent[], int vertex) {
    if (parent[vertex] == -1)
        return;
    printPath(parent, parent[vertex]);
    printf("%d ", vertex + 1); // 1-based index
}

// Function to print the final shortest path result
void printSolution(int dist[], int src, int parent[], int radius) {
    printf("\nVertex\tDistance from Source\tUsed Path\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] <= radius) {
            printf("%d -> %d\t%d\t\t%d ", src, i + 1, dist[i], src);
            printPath(parent, i);
            printf("\n");
        } else if (dist[i] == INT_MAX) {
            printf("%d -> %d\tUnreachable\n", src, i + 1);
        } else {
            printf("%d -> %d\t%d\t\tNo path within radius\n", src, i + 1, dist[i]);
        }
    }
}

// Dijkstra's algorithm to find the shortest paths
void fastpath(int a[][n], int src, int radius) {
    int dist[n], parent[n];
    bool visited[n];

    // Initialize distances and visited status
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src - 1] = 0; // Convert 1-based to 0-based index

    for (int count = 0; count < n; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break;

        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && a[u][v] && dist[u] != INT_MAX &&
                dist[u] + a[u][v] < dist[v]) {
                dist[v] = dist[u] + a[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, src, parent, radius);
}

int main() {
    int maxWeight, radius, source;

    printf("Enter maximum edge weight: ");
    scanf("%d", &maxWeight);

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    // Seed the random number generator
    srand(time(NULL));

    // Generate random weights for the graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = rand() % maxWeight;
        }
    }

    printf("Input radius (max allowed distance): ");
    scanf("%d", &radius);

    printf("Input starting vertex (1 to %d): ", n);
    scanf("%d", &source);

    if (source < 1 || source > n) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    // Time the Dijkstra algorithm
    clock_t start = clock();
    fastpath(graph, source, radius);
    clock_t end = clock();

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime Elapsed: %.3lf milliseconds\n", elapsed * 1000);

    return 0;
}
