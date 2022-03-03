/**
 * @file a-getting_gold.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Minimum spanning tree with Kruskal's algorithm
 */
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

struct node
{
    double x;
    double y;
};

struct edge
{
    int point1;
    int point2;
    double weight;
};

double get_distance (node &a, node &b)
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Number of test cases and islands
    int n,m;

    cin >> n;
    while (n--)
    {
        cin >> m;
        // Reads all nodes
        vector<node> nodes(m);
        for (node &n : nodes)
        {
            cin >> n.x >> n.y;
        }

        // Read all potential edges between all nodes to a vector
        vector<edge> edges;
        vector<int> tree_id(m);
        for (int i{0}; i < m; ++i)
        {
            tree_id[i] = i;
            for (int j{i+1}; j < m; ++j)
            {
                edges.push_back({i, j, get_distance(nodes[i], nodes[j])});
                
                // Test print
                // cout << "[" << nodes[i].x << ", " << nodes[i].y << "], " 
                // << "[" << nodes[j].x << ", " << nodes[j].y << "]: "
                // << get_distance(nodes[i], nodes[j]) << endl;
            }
        }

        sort (edges.begin(), edges.end(), [](edge a, edge b)
        {
            return a.weight < b.weight;
        });

        // vector<edge> result;
        double cost{0};

        for (edge &e : edges)
        {
            // Test print
            // cout << "[" << tree_id[e.point1] << "," << tree_id[e.point2] << "] " 
            // << e.point1 << "," << e.point2 << ": " 
            // << e.weight << endl;

            if (tree_id[e.point1] != tree_id[e.point2])
            {
                cost += e.weight;
                // result.push_back(e);

                int old_id = tree_id[e.point1];
                int new_id = tree_id[e.point2];

                for (int i{0}; i < m; ++i)
                {
                    if (tree_id[i] == old_id)
                    {
                        tree_id[i] = new_id;
                    }
                }
            }
        }

        cout.precision(14);
        cout << cost << "\n";

        // Test print
        // for (edge &e : result)
        // {
        //     cout << e.point1 << "," << e.point2 << ": " << e.weight << endl;
        // }

    }

    return 0;
}