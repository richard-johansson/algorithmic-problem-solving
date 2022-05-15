/**
 * @file a-shortestpath1.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Program that solves the single source shortest path problem
 * using Dijkstras algorithm.
 * 
 * Time complexity: O(n^2 + m), where the running time consists of:
 * - n searches for a vertex with the smallest value d[v] among O(n)
 * unmarked vertices
 * - m relaxation attempts.
 * This complexity is optimal for dense graph, i.e. when m ≈ n^2.
 */
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int INF{1000000000};

/**
 * @brief The function takes the starting vertex and two vectors that 
 * will be used as return values and fills them with the distances to 
 * the indicies and the predecessors to the indicies.
 * 
 * @param s starting node index
 * @param d distances
 * @param p predecessors
 */
void dijkstra(vector< vector< pair< int, int > > > &adj, int s, vector<int> &d, vector<int> &p)
{
    // Fill distances with INF, predecessors with -1 and labels with false
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<char> u(n, 'f');

    // Starting node costs 0 to get to 
    d[s] = 0;

    for (int i{0}; i < n; ++i)
    {
        int v{-1};
        for (int j{0}; j < n; ++j)
        {
            // Label is false and vertex is unvisited or smaller exists
            if (u[j] == 'f' && (v == -1 || d[j] < d[v]))
            {
                v = j;
            }
        }

        // Break if distance to vertex is infinity
        if (d[v] == INF)
        {
            break;
        }
        // Otherwise, mark the vertex and check all outgoing edges
        u[v] = 't';
        for (auto &edge : adj[v])
        {
            int to{edge.first};
            int len{edge.second};

            // Update the distance and predecessor when relaxation is possible
            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

/**
 * @brief Function that restores the shortest path from the predecessors, 
 * starting point and ending point
 * 
 * @param s start node
 * @param t end node
 * @param p predecessors
 * @return vector<int> shortest path
 */
vector<int> restore_path(int s, int t, vector<int> const& p)
{
    vector<int> path;

    for (int v{t}; v != s; v = p[v])
    {
        path.push_back(v);
    }
    path.push_back(s);

    reverse(path.begin(), path.end());
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

        // Adjency list of all edges going from the vertex at any index
        // where the first element in the pair is the vertex at the other 
        // end and the second element is the weight
        vector< vector< pair< int, int > > > adj(n);

        // edge from u to v with weight w
        // 0 ≤ w ≤ 1000
        int u, v, w;
        while (m--)
        {
            cin >> u >> v >> w;

            // All edges from node u is added to the list
            adj[u].push_back(make_pair(v, w));
        }

        // d = distances
        // p = predecessors
        vector<int> d, p;
        // Calculate all shortest paths from starting node s
        dijkstra(adj, s, d, p);

        // Queries asking for the minimum distance from 
        // start node s to given node
        int query, result;
        while (q--)
        {
            cin >> query;

            // Distances stored in vector d
            result = d[query];
            if (result == INF)
            {
                cout << "Impossible\n";
            }
            else
            {
                cout << result << "\n";

                // Print resulting path
                // cout << "[ ";
                // for (auto &a : restore_path(s, query, p))
                //     cout << a << " ";
                // cout << "]\n";
            }
        }
        cout << "\n";
    }

    return 0;
}