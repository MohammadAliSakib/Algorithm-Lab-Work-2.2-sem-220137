#include <iostream>
#define N 4
using namespace std;

void tspGreedy(int g[N][N], int start) {
    bool v[N] = {false};
    int cost = 0, city = start;

    cout << "Path: " << city << " ";
    v[city] = true;

    for (int i = 1; i < N; i++) {
        int next = -1, minDist = 1e9;
        for (int j = 0; j < N; j++)
            if (!v[j] && g[city][j] < minDist && g[city][j] > 0)
                minDist = g[city][j], next = j;

        v[next] = true;
        cost += minDist;
        city = next;
        cout << city << " ";
    }

    cost += g[city][start];
    cout << start << "\nCost: " << cost << endl;
}

int main() {
    int g[N][N] = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    tspGreedy(g, 0);
}
