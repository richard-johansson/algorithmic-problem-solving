/**
 * @file a-shortestpath1.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Program that solves the single source shortest path problem. 
 */
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct edge
{
    int src, dst;
};

class Graph
{
public:
    vector<vector<int>> listOfEdges;

    // Constructor
    Graph(vector<edge> const &edges, int n)
    {
        listOfEdges.resize(n);
 
        for (auto &edge: edges)
        {
            listOfEdges[edge.src].push_back(edge.dst);
            listOfEdges[edge.dst].push_back(edge.src);
        }
    }
};

/**
 * @brief DFS traversal
 * 
 * @param graph 
 * @param v starting vertex
 * @param discovered 
 */
void DFS(Graph const &graph, int v, vector<char> &discovered)
{
    discovered[v] = 't';
    cout << v << " ";

    for (int u : graph.listOfEdges[v])
    {
        if (discovered[u] == 'f')
        {
            DFS(graph, u, discovered);
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, house1, house2;
    vector<edge> edges;
    
    cin >> N >> M;
    for (int i{0}; i < M; ++i)
    {
        cin >> house1 >> house2;
        edges.push_back({house1,house2});
    }

    Graph graph(edges, N);
    vector<char> discovered(N+1, 'f');

    // DFS traversal from all undiscovered nodes
    for (int i{1}; i < M; ++i)
    {
        if (discovered[i] == 'f')
        {
            DFS(graph, i, discovered);
        }
    }
    cout << endl;

    if (discovered.size() == 1)
    {
        cout << "Connected\n";
    }
    else
    {
        for (int i{0}; i <= N; ++i)
        {
            cout << discovered[i] << "\n";
            if (discovered[i] == 'f')
            {
                cout << i << "\n";
            }
        }
    }

    return 0;
}