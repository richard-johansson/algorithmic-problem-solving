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
 * @brief BFS traversal
 * 
 * @param graph 
 * @param v starting vertex
 * @param discovered 
 */
void BFS(Graph const &graph, int v, vector<char> &discovered)
{
    queue<int> toVisit;
 
    toVisit.push(v);
    discovered[v] = 't';
 
    while (!toVisit.empty())
    {
        // dequeue front node and print it
        v = toVisit.front();
        toVisit.pop();
        cout << v << " ";
 
        // do for every edge (v, u)
        for (int u: graph.listOfEdges[v])
        {
            // Mark as discovered and enqueue if not
            if (discovered[u] == 'f')
            {
                discovered[u] = 't';
                toVisit.push(u);
            }
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
    vector<char> discovered(N, 'f');

    // BFS traversal from all undiscovered nodes
    for (int i{0}; i <= N; ++i)
    {
        if (discovered[i] == 'f')
        {
            BFS(graph, i, discovered);
            cout << i << "\n";
        }
    }

    for (auto a: discovered)
    {
        if (a == 'f')
        {
            //cout << a << "\n";
        }
        cout << a << "\n";
    }


    return 0;
}