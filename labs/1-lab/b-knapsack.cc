/**
 * @file b-knapsack.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief The knapsack problem solved with dynamic programming
 * @version 1.0
 * @date 2022-01-27
 * 
 * https://en.wikipedia.org/wiki/Knapsack_problem#0-1_knapsack_problem
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int solve(int maxCapacity, vector<int> &values, vector<int> &weights)
{
    int state{sizeof(values) / sizeof(values[0])};
    int bestValue[maxCapacity+1];
    memset(bestValue, 0, sizeof(bestValue));

    for(int i{1}; i<state+1; ++i)
    {
        for(int capacity{maxCapacity}; capacity>=0; --capacity)
        {
            if (weights[i-1] <= capacity)
            {
                bestValue[capacity] = max(bestValue[capacity], bestValue[capacity - weights[i-1]] + values[i-1]);
            }
        }
    }
    return bestValue[maxCapacity];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int maxCapacity, qtyObjects;

    while(cin >> maxCapacity >> qtyObjects)
    {
        vector<int> values;
        vector<int> weights;
        for (int i{0}; i<qtyObjects; ++i)
        {
            int value, weight;
            cin >> value >> weight;
            values.push_back(value);
            weights.push_back(weight);
            
        }

        // Test output
        /*
        cout << "------------------\n";
        cout << "maxCapacity: " << maxCapacity << endl;
        cout << "qtyObjects: " << qtyObjects << endl;
        cout << "values: [ ";
        for (auto &v : values)
        {
            cout << v << " ";
        }
        cout << "]\n";
        cout << "weights: [ ";
        for (auto &w : weights)
        {
            cout << w << " ";
        }
        cout << "]\n";
        cout << "SOLUTION:\n";
        */

        // Solve
        int bestValue = solve(maxCapacity, values, weights);

        
        // Output
        cout << bestValue << "\n";
        /*
        cout << chosenItems.size() << "\n";
        for (auto &item : chosenItems)
        {
            cout << item << " ";
        }
        cout << "\n";
        */
    }
    return 0;
}