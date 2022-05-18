/**
 * @file a-shortestpath1.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Program that solves the single source shortest path, negative 
 * weights problem using the Bellman Ford algorithm. 
 * 
 * Time complexity: O(m*n)
 */
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int INF{1000000000};
vector<int> d; // Distances
vector<int> p; // Predecessor
vector<char> negCycle; // If a negative cycle is present

/**
 * @brief A structure for representing the edges in the graph. 
 * Each edge consists of a start point a, end point b and cost.
 */
struct edge
{
    int a,b,cost;
};

/**
 * @brief The algorithm consists of several phases. Each phase scans 
 * through all edges of the graph, and the algorithm tries to produce 
 * relaxation along each edge (a,b) with weight cost, by using the edge 
 * and current response for vertex a. 
 * To prevent endless relaxation, there are only n - 1 phases. If if 
 * we run algorithm for one more phase, and it performs at least one 
 * more relaxation, then the graph contains a negative weight cycle that 
 * is reachable from, otherwise, such a cycle does not exist.
 * 
 * @param n number of vertices/nodes
 * @param s starting node
 * @param edges all edges
 */
void bellman_ford(int n, int s, vector<edge> &edges)
{
    // Sets distances to INF, parents to -1 and negative circles to false
    d.assign(n, INF);
    p.assign(n, -1);
    negCycle.assign(n, 'f');

    d[s] = 0;

    for (int i{0}; i < n; ++i) 
    {
        for (edge e : edges) 
        {
            if (d[e.a] + e.cost < d[e.b] && d[e.a] != INF) 
            {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
            }
        }
    }

    // Iterate again to check for negative cycles
    for (int i{0}; i < n; ++i) 
    {
        for (edge e : edges) 
        {
            // Cannot reach node
            if (d[e.a] == INF)
            {
                continue;
            }
            // Start node part of negative cycle -> end node is too OR
            // Still get cheaper routes -> end node is part of neg cycle
            if (negCycle[e.a] == 't' || (d[e.a] + e.cost < d[e.b]))
            {
                negCycle[e.b] = 't';
                d[e.b] = -INF;
            }
        }
    }
}

/**
 * @brief Function that restores the shortest path from the predecessors, 
 * starting point and ending point.
 * 
 * Using the predecessor vector p, the shortest path to some vertex a, is 
 * is a shortest path to some vertex p[a], to which we added a at the end 
 * of the path.
 * 
 * @param s start node
 * @param e end node
 * @return vector<int> shortest path
 */
vector<int> restore_path(int s, int e)
{
    vector<int> path;
    int curr{e};

    while (true)
    {
        path.push_back(curr);
        int parent{p[curr]};

        if (parent == -1 && curr == s)
        {
            break;
        }

        if (parent == -1)
        {
            return {};
        }

        curr = parent;
    }

    return path;
}


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // n = number of nodes, 1 ≤ n ≤ 10 000
    // m = number of edges, 1 ≤ m ≤ 30 000
    // q = number of queries, 1 ≤ q ≤ 100
    // s = index of starting node
    int n, m, q, s;

    // Read test case data
    while (cin >> n >> m >> q >> s)
    {
        if (n == 0 && m == 0 && q == 0 && s == 0)
        {
            return 0;
        }

        // List of all edges
        vector<edge> edges;

        // edge from u to v with weight w, -2000 ≤ w ≤ 2000
        int u, v, w;
        while (m--)
        {
            cin >> u >> v >> w;
            edge e{u,v,w};

            // All edges from node u is added to the list
            edges.push_back(e);
        }

        // Calculate all shortest paths from starting node s
        bellman_ford(n, s, edges);

        // Queries asking for the minimum distance from 
        // start node s to given node
        int query, result;
        char isNegativeCycle;

        while (q--)
        {
            cin >> query;
            result = d[query];

            if (result == INF)
            {
                cout << "Impossible\n";
            }
            else if (result == -INF)
            {
                cout << "-Infinity\n";
            }
            else
            {
                cout << result << "\n";
            }
        }

        // Restore the path
        // cout << "[ ";
        // for (auto &a : restore_path(s, query))
        //     cout << a << " ";
        // cout << "]\n";

        cout << "\n";
    }

    return 0;
}