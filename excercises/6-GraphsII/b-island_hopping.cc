/**
 * @file a-getting_gold.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
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
    double distance;
};

double get_distance (node &a, node &b)
{
    return sqrt(pow((a.y - a.x), 2) - pow((b.y - b.x), 2));
}

int find (vector<int> &dis, int a)
{
    if (dis[a] == -1)
    {
        return a;
    }
    return dis[a] = find(dis, dis[a]);
}

void join (vector<int> &dis, int a, int b)
{
    a = find(dis, a);
    b = find(dis, b);
    if (a == b)
    {
        return;
    }
    else
    {
        dis[a] = b;
    }
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

        // Read edges to a vector
        vector<edge> edges;
        for (int i{0}; i < m; ++i)
        {
            for (int j{i+1}; j < m; ++j)
            {
                edges.push_back({i, j, get_distance(nodes[i], nodes[j])});
            }
        }

        // Sort as part of Kruskals
        sort (edges.begin(), edges.end(), [](edge a, edge b)
        {
            return a.distance < b.distance;
        });

        vector<int> dis(n);
        double cost{0};

        for (edge &e : edges)
        {
            if (find(dis, e.point1) != find(dis, e.point2))
            {
                join(dis, e.point1, e.point2);
                cost += e.distance;
            }
        }

        cout << cost << "\n";
    }

    return 0;
}