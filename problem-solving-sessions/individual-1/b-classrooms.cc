#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n, k;
    cin >> n >> k;

    vector<pair<long long,long long>> activities;
    long maxActivites{0};
    
    while(n--)
    {
        // Read input
        long long si,fi;
        cin >> si >> fi;

        activities.push_back(make_pair(si,fi));
    }

    sort(activities.begin(), activities.end());

    // Test print
    for (auto &a: activities)
    {
        cout << a.first << ": " << a.second << endl;
    }



    cout << maxActivites << endl;

    return 0;
}