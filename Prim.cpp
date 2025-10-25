#include <iostream>
#include <limits.h>

#define MAX 100
#define INF INT_MAX
using namespace std;
void prim(int n, int W[MAX][MAX]) {
    int nearest[MAX];     // nearest vertex in MST
    int distance[MAX];    // minimum edge weight to MST
    int F[MAX][2];        // store MST edges (u, v)
    int min, vnear;
    int i, j, e = 0;

    // Initialize
    for (i = 2; i <= n; i++) {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }
    distance[1] = -1; // vertex 1 is included in MST

    // Repeat n-1 times
    for (int k = 1; k <= n - 1; k++) {
        min = INF;
        vnear = -1;

        // Find nearest vertex not yet in MST
        for (i = 2; i <= n; i++) {
            if (distance[i] >= 0 && distance[i] < min) {
                min = distance[i];
                vnear = i;
            }
        }

        // Record the selected edge
        F[e][0] = nearest[vnear];
        F[e][1] = vnear;
        e++;

        distance[vnear] = -1; // include vnear in MST

        // Update distances
        for (i = 2; i <= n; i++) {
            if (W[i][vnear] < distance[i]) {
                distance[i] = W[i][vnear];
                nearest[i] = vnear;
            }
        }
    }

    // Print MST edges
    cout<<"Edges in the Minimum Spanning Tree:\n";
    for (i = 0; i < e; i++) {
        
		cout<<"("<<F[i][0]<<","<<F[i][1]<<")";
		//printf("(%d, %d)\n", F[i][0], F[i][1]);
    }
}

int main() {
    int n = 5;
    int W[MAX][MAX] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 2, INF, 6, INF},
        {0, 2, 0, 3, 8, 5},
        {0, INF, 3, 0, INF, 7},
        {0, 6, 8, INF, 0, 9},
        {0, INF, 5, 7, 9, 0}
    };

    prim(n, W);
    return 0;
}

