/**
 * @file a-arbitrage.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 */
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <sstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // n = number of nodes
    // m = number of edges
    int n, m;
    string currency;
    // Mapping currency to index
    unordered_map<string, int> currencies;
    
    while(cin >> n){
        if (n == 0)
        {
            break;
        }

        double weights[n][n];
        currencies.clear();

        for (int i{0}; i < n; ++i)
        {
            cin >> currency;
            currencies[currency] = i;

            // Setting every transaction cost to 0 initially
            for (int j{0}; j < n; ++j)
            {
                if (j == i)
                {
                    // Transaction to itself is 1
                    weights[i][j] = 1.0;
                }
                else
                {
                    weights[i][j] = 0.0;
                }
                // cout << i << " " << j << " = " << weights[i][j] << endl;
            }
        }

        // Read exchange rates = edges
        int rate1, rate2;
        string curr1, curr2, str;
        cin >> m;
        for (int i{0}; i < m; ++i)
        {
            // Read names of currencies
            cin >> curr1 >> curr2;

            // Rest is the numbers, divided by ':'
            getline(cin, str, ':');
            stringstream ss(str);
            ss >> rate1;
            cin >> rate2;

            // Save greatest of 1 and the rate
            int index1{currencies[curr1]};
            int index2{currencies[curr2]};
            weights[index1][index2] = max(weights[index1][index2], (double)rate2/rate1);
            
            cout << index1 << " " << index2 << " = " << weights[index1][index2] << endl;
        }

        // Run through Bellman Ford
        for (int i{0}; i < n; ++i)
        {
            for(int j{0}; j < n; ++j)
            {
                for(int k{0}; k < n; ++k)
                {
                    weights[j][k] = max(weights[j][k], weights[j][i] * weights[i][k]);
                }
            }
        }

        // If loops are found it is an arbitrage!
        for (int i{0}; i < n; ++i) 
        {
            if (weights[i][i] > 1.0)
            {
                cout << "Arbitrage\n";
                break;
            }
            else
            {
                cout << "Ok\n";
                break;
            }
        }
    }

    return 0;
}