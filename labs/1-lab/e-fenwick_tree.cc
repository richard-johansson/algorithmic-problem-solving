/**
 * @file e-fenwick-tree.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Program that creates a Fenwick Tree (Binary 
 * Indexed Tree, BIT) and can add and output the sum.
 * Time complexity is O(log n) for add and sum.
 */
#include <iostream>

using namespace std;

/**
 * @brief Updates the node at index i and its ancestors
 * in the tree with the given value.
 */
void add(int fenwickTree[], int N, int i, int val)
{
    ++i;
    while (i <= N)
    {
        // cout << "i: " << i << endl;
        fenwickTree[i] += val;
        // Go to the next node (exponentially increasing interval)
        i += i & (-i);
    }
}

/**
 * @brief Outputs the sum from 0 to index i.
 */
void sum(int fenwickTree[], int i)
{
    int result{0};
    // Fenwick tree is indexed from 1
    // ++i;
    while (i > 0)
    {
        // cout << "i: " << i << endl;
        result += fenwickTree[i];
        // Go to the "parent"-node in the tree
        i -= i & (-i);
    }
    cout << result << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;

    cin >> N >> Q;

    // Init the Fenwick tree
    int fenwickTree[N+1];
    for (int i{0}; i<=N; ++i)
    {
        fenwickTree[i] = 0;
    }
    // cout << "FT: ";
    // for (int i{0}; i<=N; ++i)
    // {
    //     cout << fenwickTree[i] << " ";
    // }
    // cout << endl;

    char op;
    int i, val;
    // For every test case
    while(Q--)
    {
        // Read input
        cin >> op;
        if (op == '+')
        {
            cin >> i >> val;
            add(fenwickTree, N, i, val);

            // Test print
            // cout << Q << ": " << op << " " << i << " " << val << endl;
            // cout << "FT: ";
            // for (int i{0}; i<=N; ++i)
            // {
            //     cout << fenwickTree[i] << " ";
            // }
            // cout << endl;
        }
        else
        {
            cin >> i;

            // Test print
            // cout << Q << ": " << op << " " << i << endl;
            // cout << "FT: ";
            // for (int i{0}; i<=N; ++i)
            // {
            //     cout << fenwickTree[i] << " ";
            // }
            // cout << endl;
            
            sum(fenwickTree, i);
        }
    }
    return 0;
}