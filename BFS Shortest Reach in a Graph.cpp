#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
private:
    std::vector<std::vector<int>> graph;
public:
    Graph(int n) {
        graph.resize(n);
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> shortest_reach(int start)
    {
        std::vector<int> distance(graph.size(), -1);
        std::vector<int> parents(graph.size(), -1);
        std::vector<bool> visited(graph.size());
        std::queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < graph[cur].size(); ++i)
            {
                int neighbour = graph[cur][i];
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parents[neighbour] = cur;
                }
            }
        }
        for (int i = 0; i < parents.size(); ++i)
        {
            int dist = -1;
            if (visited[i])
            {
                dist = 0;
                int par = parents[i];
                while (par != -1)
                {
                    par = parents[par];
                    dist += 6;
                }
            }
            distance[i] = dist;

        }
        return distance;
    }

};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
