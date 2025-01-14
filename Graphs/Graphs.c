#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct{
    int numVertices;
    int adjMatrix[max][max];
}graph_matrix;

void initGraphMatrix(graph_matrix *g, int numVertices){
    g->numVertices = numVertices;
    int i,j;
    for(i = 0;i<numVertices;i++){
        for(j=0;j<numVertices;j++){
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdgeMatrix(graph_matrix *g, int u, int v, int weight){
    g->adjMatrix[u][v] = weight;
}

void displayMatrix(graph_matrix *g){
    int i,j;
    for(i = 0;i<g->numVertices;i++){
        for(j=0;j<g->numVertices;j++){
            printf("%d ",g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

typedef struct Node{
    int vertex;
    int weight;
    struct Node *next;
} node;

typedef struct {
    int numVertices;
    node *adjMatrix[max];
} GraphList;

void initGraphList(GraphList *g, int numVertices){
    g->numVertices = numVertices;
    int i;
    for(i=0;i<numVertices;i++){
        g->adjMatrix[i] = NULL;
    }
}

void addEdgeList(GraphList *g, int u, int v, int weight){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = g->adjMatrix[u];
    g->adjMatrix[u] = newNode;
}

void displayList(GraphList *g){
    int i;
    for (i=0;i<g->numVertices;i++){
        printf("Verted %d: ",i);
        node *temp = g->adjMatrix[i];
        while (temp){
            printf("-> %d(%d) ",temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

//Depth First Search (DFS)
void dfs(GraphList *g, int start, int visied[]){
    visied[start] = 1;
    printf("%d ",start);
    node *temp = g->adjMatrix[start];
    while (temp){
        if (!visied[temp->vertex]){
            dfs(g, temp->vertex, visied);
        }
        temp = temp->next;
    }
}

//Breadth First Search (BFS)
void bfs(GraphList *g, int start){
    int visited[max] = {0};
    int queue[max], front = 0,rear=0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear){
        int current = queue[front++];
        printf("%d ",current);
        node *temp = g->adjMatrix[current];
        while (temp){
            if (!visited[temp->vertex]){
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    graph_matrix gMatrix;
    GraphList gList;

    printf("Adjacency Matrix Representation:\n");
    initGraphMatrix(&gMatrix, 5);
    addEdgeMatrix(&gMatrix, 0, 1, 1);
    addEdgeMatrix(&gMatrix, 1, 2, 1);
    addEdgeMatrix(&gMatrix, 2, 3, 1);
    addEdgeMatrix(&gMatrix, 3, 4, 1);
    displayMatrix(&gMatrix);

    printf("\nAdjacency List Representation:\n");
    initGraphList(&gList, 5);
    addEdgeList(&gList, 0, 1, 1);
    addEdgeList(&gList, 1, 2, 1);
    addEdgeList(&gList, 2, 3, 1);
    addEdgeList(&gList, 3, 4, 1);
    displayList(&gList);

    printf("\nDepth First Search (DFS):\n");
    int visited[max] = {0};
    dfs(&gList, 0, visited);

    printf("\nBreadth First Search (BFS):\n");
    bfs(&gList, 0);

    return 0;
}