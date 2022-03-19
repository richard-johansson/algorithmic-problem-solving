/**
 * @file b-hiding_places.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Solving Hiding Places problem with Breath First Search
 */
#include <bits/stdc++.h>

using namespace std;

bool inbounds(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

void bfs(vector<vector<int>> &distances, int x_start, int y_start, vector<int> &dx, vector<int> &dy)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x_start, y_start));
    distances[x_start][y_start] = 0;

    // BFS traversal
    while (!q.empty())
    {
        int x_curr = q.front().first;
        int y_curr = q.front().second;
        q.pop();

        for (int i{0}; i < 8; ++i)
        {
            int x_next{x_curr + dx[i]};
            int y_next{y_curr + dy[i]};
    
            if (!inbounds(x_next, y_next)) 
            {
                continue;
            }
            // Only update if the distance is least 1 bigger
            if (distances[x_next][y_next] > distances[x_curr][y_curr] + 1)
            {
                distances[x_next][y_next] = distances[x_curr][y_curr] + 1;
                q.push(make_pair(x_next, y_next));
            }
        }
    }
}

void solve(string start)
{
    // Convert starting point to 0-indexed ints
    int x_start{start[0] - 'a'};
    int y_start{start[1] - '1'};

    // Vector containing distances from start to each point
    vector< vector <int> > distances(8, vector<int>(8, INT_MAX));

    // Initializing direction vectors
    vector<int> dx{-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> dy{-1, 1, -2, 2, -2, 2, -1, 1};

    // Do breath first search
    bfs(distances, x_start, y_start, dx, dy);

    // Find number of jumps to the hiding places
    int biggest{0};
    for (int i{0}; i < 8; ++i)
    {
        for (int j{0}; j < 8; ++j)
        {
            biggest = max(biggest, distances[i][j]);
        }
    }
    cout << biggest << " ";

    // Print position of hiding places in order from top to bottom and left to right
    for (int i{7}; i >= 0; --i)
    {
        for (int j{0}; j < 8; ++j)
        {
            if (distances[j][i] == biggest)
            {
                cout << (char)(j + 'a') << (char)(i + '1') << " ";
            }
        }
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read number of test cases
    int numberOfTestCases{0};
    cin >> numberOfTestCases;

    // For every test case
    while(numberOfTestCases--)
    {
        // Read input
        string startPoint{};
        cin >> startPoint;

        solve(startPoint);
    }

    return 0;
}