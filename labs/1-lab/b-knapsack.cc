/**
 * @file b-knapsack.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief The knapsack problem solved with dynamic programming
 * @version 1.0
 * @date 2022-01-27
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> solve(int const& maxCapacity, vector<int> const& values, vector<int> const& weights)
{
    // * https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
    vector<int> chosenItems{0};

    // Initialize dynamic programming array


    return chosenItems;
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

        // Solve
        vector<int> chosenItems = solve(maxCapacity, values, weights);

        // Output
        cout << chosenItems.size() << "\n";
        for (auto &item : chosenItems)
        {
            cout << item << " ";
        }
        cout << "\n";
    }
    return 0;
}