/**
 * @file a-getting_gold.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 */
#include <iostream>
#include <queue>

using namespace std;

// Print the queue
void showq(queue<pair<int,int> > gq)
{
    queue<pair<int,int> > g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front().first << g.front().second;
        g.pop();
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read number of test cases
    int W,H;
    cin >> W >> H;

    // Picked gold and map
    int gold{0};
    char map[H][W];
    pair<int,int> start;

    // Read input
    for (int h{0}; h < H; ++h)
    {
        for (int w{0}; w < W; ++w)
        {
            cin >> map[h][w];

            if (map[h][w] == 'P') 
            {
                start = make_pair(h,w);
            }
        }
    }

    // Test print
    // cout << "P: " << start.first << "," << start.second << "\n";
    // for (int h{0}; h < H; ++h)
    // {
    //     for (int w{0}; w < W; ++w)
    //     {
    //         cout << map[h][w];
    //     }
    //     cout << "\n";
    // }

    // Flood fill queue
    queue<pair<int,int> > myQueue;
    myQueue.push(start);

    // Flood fill already visited
    bool visited[H][W];
    for (int h{0}; h < H; ++h)
    {
        for (int w{0}; w < W; ++w)
        {
            visited[h][w] = false;
        }
    }
    visited[start.first][start.second] = true;

    // Flood fill algorithm
    int iter{0};
    while(!myQueue.empty())
    {
        if (iter++ == W*H)
            break;
        pair<int,int> curr = myQueue.front();
        myQueue.pop();
        // cout << "CURR: " << curr.first << " " << curr.second << "\n";

        // Check if current square is gold
        if (map[curr.first][curr.second] == 'G')
        {
            ++gold;
            // cout << " - gold\n";
        }

        // Check if we are trapped
        if (map[curr.first + 1][curr.second] == 'T' ||
            map[curr.first - 1][curr.second] == 'T' ||
            map[curr.first][curr.second + 1] == 'T' ||
            map[curr.first][curr.second - 1] == 'T')
        {
            continue;
            // cout << " - trap\n";
        }

        // Check if we can move to square below
        if (!visited[curr.first + 1][curr.second] && 
            map[curr.first + 1][curr.second] == 'G' ||
            map[curr.first + 1][curr.second] == '.')
        {
            myQueue.push(make_pair(curr.first + 1, curr.second));
            visited[curr.first + 1][curr.second] = true;
            // cout << "below - " << curr.first + 1 << curr.second << "\n";
        }

        // Check if we can move to square above
        if (!visited[curr.first - 1][curr.second] && 
            map[curr.first - 1][curr.second] == 'G' ||
            map[curr.first - 1][curr.second] == '.')
        {
            myQueue.push(make_pair(curr.first - 1, curr.second));
            visited[curr.first - 1][curr.second] = true;
            // cout << "above - " << curr.first - 1 << curr.second << "\n";
        }

        // Check if we can move to square to right
        if (!visited[curr.first][curr.second + 1] && 
            map[curr.first][curr.second + 1] == 'G' ||
            map[curr.first][curr.second + 1] == '.')
        {
            myQueue.push(make_pair(curr.first, curr.second + 1));
            visited[curr.first][curr.second + 1] = true;
            // cout << "right - " << curr.first << curr.second + 1 << "\n";
        }

        // Check if we can move to square to left
        if (!visited[curr.first][curr.second - 1] && 
            map[curr.first][curr.second - 1] == 'G' ||
            map[curr.first][curr.second - 1] == '.')
        {
            myQueue.push(make_pair(curr.first, curr.second - 1));
            visited[curr.first][curr.second - 1] = true;
            // cout << "left - " << curr.first << curr.second - 1 << "\n";
        }
        
        // cout << "---NEXT----\nQUEUE:";
        // showq(myQueue);
;    }

    cout << gold << "\n";

    return 0;
}