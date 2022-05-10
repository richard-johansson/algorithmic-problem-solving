/**
 * @file b-knapsack.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief The knapsack problem solved with dynamic programming. Runs in O(objects * capacity) time.
 * @version 2.0
 * @date 2022-02-10
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * @brief recursive function to find the actual items related to the optimal solution.
 * 
 * @param i Number of items
 * @param j Capacity of the knapsack
 * @param objects The objects available to choose from and pack in the kapsack, as pairs of <value, weight>
 * @param dp Dynamic programming array containing the values of the objects
 * @param result Vector to save the resulting indices in
 */
void knapsack(int i, int j, vector< pair<int, int> > &objects, vector< vector<int> > &dp, vector<int> &result) {
    if(dp[i][j] == 0) {
        return;
    }

    if(dp[i-1][j] == dp[i][j]) {
        knapsack(i-1, j, objects, dp, result);
    }
    else {
        knapsack(i-1, j-objects[i].second, objects, dp, result);
        result.push_back(i-1);
    }
}

/**
 * @brief iterative function that finds the optimal solution given capacity of the knapsack,
 * the objects to choose from and a dp table.
 * 
 * @param capacity Capacity of the knapsack
 * @param objects Objects to choose from, as pairs of <value, weight>
 * @param dp Dynamic programming table
 */
void solve(int capacity, vector< pair<int, int> > &objects, vector< vector<int> > &dp)
{
    for(int i = 1; i < objects.size(); i++) {
        pair<int, int> object = objects[i];
        for(int j = 1; j <= capacity; j++) {
            // If we can't take this item, continue
            if(j < object.second) {
                dp[i][j] = dp[i-1][j];
                continue;
            }

            dp[i][j] = max(dp[i-1][j-object.second]+object.first, dp[i-1][j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read input
    int items, capacity;
    while(cin >> capacity >> items) {
        // Create the dynamic programming table and fill with 0
        vector< vector<int> > dp;
        dp.resize(items+1, vector<int>(capacity+1, 0));

        // Read all data, first push {0,0} to match the dp table
        vector< pair<int, int> > objects;
        objects.push_back({0,0});
        for(int i = 0; i < items; i++) {
            pair<int, int> p;
            cin >> p.first >> p.second;
            objects.push_back(p);
        }

        // Run the knapsack algorithm
        solve(capacity, objects, dp);

        // // Print items
        // cout << "ITEMS:\nval weight\n";
        // for(int i = 0; i <= items; i++) {
        //     cout << " " << objects[i].first << "   " << objects[i].second << "\n";
        // }
        // // Print dp table
        // cout << "DYNAMIC TABLE:\n";
        // for(int i = 0; i <= items; i++) {
        //     for(int j = 0; j <= capacity; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "RESULT:\n";

        // Calculate result
        vector<int> result;
        knapsack(items, capacity, objects, dp, result);

        // Print result
        cout << result.size() << "\n";
        for(auto &i : result) {
            cout << i << " ";
        }
        cout << "\n";
    }
}