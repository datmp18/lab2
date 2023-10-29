#include <stdio.h>
#include <stdbool.h>


#define N 5
int array[5][5]= {
	{ 0,3 ,14 ,18,15},
	{ 3,0 ,4 ,22,20},
	{ 17,9 ,0 ,16,4},
	{ 9,20 ,7 ,0,18},
	{ 9,15 ,11 ,5,0},
};

int minCost = __INT_MAX__;
bool visited[N];



void tsp(int path[], int current, int cost, int level) {
    if (level == N) {
        // All cities have been visited, return to the starting city
        if (array[current][0] != 0) {
            cost += array[current][0];
            if (cost < minCost) {
                minCost = cost;
                // Store the best tour
                for (int i = 0; i < N; i++) {
                    path[i] = visited[i];
                }
            }
        }
        return;
    }

 

    // Branch and Bound
    for (int i = 0; i < N; i++) {
        if (!visited[i] && array[current][i] != 0) {
            visited[i] = true;
            tsp(path, i, cost + array[current][i], level + 1);
            visited[i] = false;
        }
    }
}


int main() {
   int path[N] = {0};  // Store the best tour
    visited[0] = true;  // Start from city 0

 

    tsp(path, 0, 0, 1);

 

    printf("Optimal Traveling Salesman Tour: 0");
    for (int i = 0; i < N; i++) {
        if (path[i]) {
            printf(" -> %d", i);
        }
    }
    printf(" -> 0\n");

 

    printf("Optimal Cost: %d\n", minCost);

 

    return 0;
}
