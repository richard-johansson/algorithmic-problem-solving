/**
 * @file a-interval_cover.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 * @version 1.0
 * @date 2022-01-27
 */
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Finds which sub-intervals that are needed for complete coverage.
 * 
 * @param intervals 
 * @param intervalToCover 
 * @return vector<int> The index of the needed intervals.
 */
vector<int> covering(vector<pair<double, double>> intervals, double start, double end)
{
    vector<int> chosenIntervals{0};
    int chosenIndex{0};
    double currentStart{start}, currentEnd{start};
    // Iterating all intervals
    for (int i{0}; i<intervals.size(); ++i)
    {
        // If this interval covers the start of the last interval
        if(intervals[i].first <= currentStart)
        {
            // And if this interval 
            if (intervals[i].second >= currentEnd)
            {
                currentStart = intervals[i].first;
                currentEnd = intervals[i].second;
                chosenIndex = i;
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read until no more input
    double mainStart{}, mainEnd{};
    while(cin >> mainStart >> mainEnd)
    {
        //pair<double, double> intervalToCover{mainStart,mainEnd};
        // Read the data
        int numberOfIntervals{0};
        cin >> numberOfIntervals;

        vector<pair<double, double>> intervals{};
        for (int i{0}; i<numberOfIntervals; ++i)
        {
            double subStart{}, subEnd{};
            cin >> subStart >> subEnd;
            intervals.insert(pair<double, double>{subStart, subEnd});
        }

        // Test output
        cout << "numberOfIntervals: " << numberOfIntervals << endl;
        cout << "interval: [" << mainStart << ", " << mainEnd << "]" << endl;
        cout << "available intervals: " << endl;
        for (auto &interval : intervals)
        {
            cout << "[" << interval.first << ", " << interval.second << "]" << endl;
        }

        // Solve the problem
        /* Algorithm: 
            * Choose the interval that covers the beginning and covers most of the
            * rest of the interval. 
            * Then loop over the remaining intervals and find the one that covers
            * the end of the interval before and covers most of the remaining 
            * interval.
        */
       vector<int> chosenIntervals = covering(intervals, mainStart, mainEnd);
       for (auto& intervalIndex : chosenIntervals)
       {
           cout << intervalIndex << " ";
       }
       cout << endl;
    }



    return 0;
}