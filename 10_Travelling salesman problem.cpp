#include <iostream>
#include <climits>
using namespace std;

// Function to find the minimum cost path
void findMinRoute(int tsp[][4], int n) {
    int sum = 0;
    int counter = 0;
    int j = 0, i = 0;
    int min = INT_MAX;

    // Array to track visited cities
    int visitedRouteList[4] = {0};
    visitedRouteList[0] = 1;

    // Array to store the route
    int route[4];

    // Traverse the adjacency matrix tsp[][]
    while (i < n && j < n) {
        // If all cities have been visited, stop
        if (counter >= n - 1) {
            break;
        }

        // If the path is unvisited and the cost is less, update the cost
        if (j != i && visitedRouteList[j] == 0) {
            if (tsp[i][j] < min) {
                min = tsp[i][j];
                route[counter] = j + 1;
            }
        }
        j++;

        // Check all paths from the ith indexed city
        if (j == n) {
            sum += min;
            min = INT_MAX;
            visitedRouteList[route[counter] - 1] = 1;
            j = 0;
            i = route[counter] - 1;
            counter++;
        }
    }

    // Update the ending city in the array from the city which was last visited
    i = route[counter - 1] - 1;

    for (j = 0; j < n; j++) {
        if (i != j && tsp[i][j] < min) {
            min = tsp[i][j];
            route[counter] = j + 1;
        }
    }
    sum += min;

    // Print the minimum cost
    cout << "Minimum Cost is: " << sum << endl;
}

// Driver Code
int main() {
    // Input Matrix
    int tsp[4][4] = { { -1, 10, 15, 20 },
                      { 10, -1, 35, 25 },
                      { 15, 35, -1, 30 },
                      { 20, 25, 30, -1 } };
    int n = 4;

    // Function Call
    findMinRoute(tsp, n);

    return 0;
}
