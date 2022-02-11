/**
 * @file e-fenwick-tree.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 */
#include <iostream>

using namespace std;

void add(int fenwickTree[], int N, int i, int val)
{
    ++i;
    while (i <= N)
    {
        cout << "i: " << i << endl;
        fenwickTree[i] += val;
        // Go to the next node (exponentially increasing interval)
        i += i & (-i);
    }
}

void sum(int fenwickTree[], int i)
{
    int result{0};
    // Fenwick tree is indexed from 1
    // ++i;
    while (i > 0)
    {
        cout << "i: " << i << endl;
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
    cout << "FT: ";
    for (int i{0}; i<=N; ++i)
    {
        cout << fenwickTree[i] << " ";
    }
    cout << endl;

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
            cout << Q << ": " << op << " " << i << " " << val << endl;
            cout << "FT: ";
            for (int i{0}; i<=N; ++i)
            {
                cout << fenwickTree[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cin >> i;

            // Test print
            cout << Q << ": " << op << " " << i << endl;
            cout << "FT: ";
            for (int i{0}; i<=N; ++i)
            {
                cout << fenwickTree[i] << " ";
            }
            cout << endl;
            
            sum(fenwickTree, i);
        }
    }
    return 0;
}