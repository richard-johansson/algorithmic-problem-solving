/**
 * @file 1.5-fenwick-tree.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Program that creates a Fenwick Tree (Binary Indexed Tree, BIT)
 * and can add and output the sum.
 * Time complexity is O(log n) for add and sum.
 * 
 * The idea is based on the fact that all positive integers can be 
 * represented as the sum of powers of 2. For example 19 can be represented 
 * as 16 + 2 + 1. Every node of the BIT stores the sum of n elements where n
 * is a power of 2. The number of set bits in the binary representation of a 
 * number n is O(Logn). Therefore, we traverse at-most O(Logn) nodes in both 
 * sum() and add() operations.
 */
#include <iostream>

using namespace std;

/**
 * @brief Updates the node at index i and its ancestors
 * in the tree with the given value.
 */
void add(long long fenwickTree[], long long N, long long i, long long val)
{
    // Tree is indexed from 1
    ++i;
    while (i <= N)
    {
        fenwickTree[i] += val;
        // Go to the next node (exponentially increasing interval)
        i += i & (-i);
    }
}

/**
 * @brief Outputs the sum from 0 to index i.
 */
void sum(long long fenwickTree[], long long i)
{
    long long result{0};
    while (i > 0)
    {
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

    long long N, Q;
    cin >> N >> Q;

    // Init the Fenwick tree
    long long fenwickTree[N+1];
    for (long long i{0}; i<=N; ++i)
    {
        fenwickTree[i] = 0;
    }

    // Read input and call corresponding function
    char op;
    long long i, val;
    while(Q--)
    {
        cin >> op;
        if (op == '+')
        {
            cin >> i >> val;
            add(fenwickTree, N, i, val);
        }
        else
        {
            cin >> i;
            sum(fenwickTree, i);
        }
    }
    return 0;
}