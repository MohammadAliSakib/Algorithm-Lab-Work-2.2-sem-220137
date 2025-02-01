#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<int, vector<int>> Adj;
    int visited[100] = {0};
    int lvl[100] = {0};

    void addEdge(int u, int v, bool d) {
        Adj[u].push_back(v);
        // for undirected graph
        if (d == 0) {
            Adj[v].push_back(u);
        }
    }

    void bfs(int source) {
        queue<int> q;
        q.push(source);
        visited[source] = 1;


        while (!q.empty()) {
            int cur_vtx = q.front();
            q.pop();
            cout << cur_vtx << " ";

            for (int child : Adj[cur_vtx]) {
                if (!visited[child]) {
                    q.push(child);
                    visited[child] = 1;
                    lvl[child] = lvl[cur_vtx] + 1;
                }
            }
        }
    }
};

int main() {
    int e;
    cout << "Enter the number of Edges : ";
    cin >> e;

    Graph G;
    int u, v;
    cout << "Enter edges (u v):" << endl;
     cin >> u >> v;
     int first=u;
        G.addEdge(u, v, false);
    for (int i = 1; i < e; i++) {
        cin >> u >> v;
        G.addEdge(u, v, false); // assuming undirected graph
    }

    G.bfs(first);

    cout << "\nLevels:" << endl;
    for (int i = 1; i <= e; i++) {
        cout << i << " " << G.lvl[i] << endl;
    }

    return 0;
}

