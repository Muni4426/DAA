#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
#define INF 999999
typedef struct {
 int x;
 int y;
} Point;
typedef struct {
 int u, v;
 double cost;
} Edge;
Point group1[MAX], group2[MAX];
int n1, n2;
double calculateDistance(Point p1, Point p2) {
 return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
void createEdges(Edge edges[], int *edgeCount) {
 *edgeCount = 0;
 for (int i = 0; i < n1; i++) {
 for (int j = 0; j < n2; j++) {
 edges[*edgeCount].u = i;
 edges[*edgeCount].v = j;
 edges[*edgeCount].cost = calculateDistance(group1[i], group2[j]);
 (*edgeCount)++;
 }
 }
}
int findParent(int parent[], int i) {
 if (parent[i] == -1) {
 return i;
 }
 return findParent(parent, parent[i]);
}
void unionSets(int parent[], int x, int y) {
 int xset = findParent(parent, x);
 int yset = findParent(parent, y);
 parent[xset] = yset;
}
double kruskal(Edge edges[], int edgeCount) {
 double minCost = 0;
 int parent[MAX];
 for (int i = 0; i < MAX; i++) {
 parent[i] = -1;
 }
 // Sort edges based on cost (bubble sort for simplicity)
 for (int i = 0; i < edgeCount - 1; i++) {
 for (int j = 0; j < edgeCount - i - 1; j++) {
 if (edges[j].cost > edges[j + 1].cost) {
 Edge temp = edges[j];
 edges[j] = edges[j + 1];
 edges[j + 1] = temp;
 }
 }
 }
 // Process edges in sorted order
 for (int i = 0; i < edgeCount; i++) {
 int u = edges[i].u;
 int v = edges[i].v;
 if (findParent(parent, u) != findParent(parent, v)) {
 minCost += edges[i].cost;
 unionSets(parent, u, v);
 }
 }
 return minCost;
}
int main() {
 printf("Enter number of points in Group 1: ");
 scanf("%d", &n1);
 printf("Enter points (x y):\n");
 for (int i = 0; i < n1; i++) {
 scanf("%d %d", &group1[i].x, &group1[i].y);
 }
 printf("Enter number of points in Group 2: ");
 scanf("%d", &n2);
 printf("Enter points (x y):\n");
 for (int i = 0; i < n2; i++) {
 scanf("%d %d", &group2[i].x, &group2[i].y);
 }
 Edge edges[MAX * MAX];
 int edgeCount;
 createEdges(edges, &edgeCount);
 double minCost = kruskal(edges, edgeCount);
 
 printf("Minimum cost to connect the two groups of points: %.2f\n", minCost);
 return 0;
}
