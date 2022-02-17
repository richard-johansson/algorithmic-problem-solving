#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> weights;
    
    int weight;
    while(n--)
    {
        cin >> weight;
        weights.push_back(weight);
        // Test output
        // cout << weight << endl;
    }

    int bestWeightOver1000{INT16_MAX};
    map<int,int> weightMap;
    weightMap[0] = 1;

    for (int weight: weights)
    {
        vector<int> newWeights{};

        for (auto &w : weightMap)
        {
            int newWeight{w.first + weight};

            if (newWeight <= 1000)
            {
                newWeights.push_back(newWeight);
            }
            else if (newWeight < bestWeightOver1000)
            {
                bestWeightOver1000 = newWeight;
                newWeights.push_back(newWeight);
            }
        }
        for (int newWeight : newWeights)
        {
            weightMap[newWeight] = 1;
        }
    }

    int best, leastDistance{1000};
    for (auto &weight : weightMap)
    {
        int currentDistance{abs(1000 - weight.first)};

        if (currentDistance <= leastDistance)
        {
            leastDistance = currentDistance;
            best = weight.first;
        }
    }

    cout << best << endl;

    return 0;
}