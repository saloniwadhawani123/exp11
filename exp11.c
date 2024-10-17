
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function prototypes
void bfs(int adj_matrix[MAX][MAX], int n, int start);
void dfs(int adj_matrix[MAX][MAX], int n, int start, int visited[MAX]);
void dfs_call(int adj_matrix[MAX][MAX], int n, int start);

// Main function with menu-driven interface
int main() {
    int adj_matrix[MAX][MAX];
    int n, choice, start;
    int visited[MAX] = {0};

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. BFS Traversal\n");
        printf("2. DFS Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the starting vertex for BFS: ");
                scanf("%d", &start);
                printf("BFS Traversal starting from vertex %d: ", start);
                bfs(adj_matrix, n, start);
                break;

            case 2:
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &start);
                for (int i = 0; i < n; i++) {
                    visited[i] = 0; // Reset visited array
                }
                printf("DFS Traversal starting from vertex %d: ", start);
                dfs_call(adj_matrix, n, start);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 3);

    return 0;
}

// BFS Function
void bfs(int adj_matrix[MAX][MAX], int n, int start) {
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};

    // Mark the starting vertex as visited and enqueue it
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Enqueue all adjacent vertices of current vertex
        for (int i = 0; i < n; i++) {
            if (adj_matrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// DFS Function (Recursive)
void dfs(int adj_matrix[MAX][MAX], int n, int start, int visited[MAX]) {
    visited[start] = 1;
    printf("%d ", start);

    // Visit all adjacent vertices of the current vertex
    for (int i = 0; i < n; i++) {
        if (adj_matrix[start][i] == 1 && !visited[i]) {
            dfs(adj_matrix, n, i, visited);
        }
    }
}

// DFS function with initial call setup
void dfs_call(int adj_matrix[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    dfs(adj_matrix, n, start, visited);
    printf("\n");
}
