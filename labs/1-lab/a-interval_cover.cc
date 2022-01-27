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
 * @param start 
 * @param end 
 * @return vector<int> The index of the needed intervals.
 */
vector<int> covering(vector<pair<double, double>> intervals, double start, double end)
{
    vector<int> chosenIntervals{0};
    int chosenIndex{0};
    /* Algorithm: 
        * Choose the interval that covers the beginning and covers most of the
        * rest of the interval. 
        * Then loop over the remaining intervals and find the one that covers
        * the end of the interval before and covers most of the remaining 
        * interval.
    */

    sort(intervals.begin(), intervals.end());
    double currentStart{start}, currentEnd{start};
    int numberOfIntervalsNeeded{0};

    cout << "SOLVING\n";
    cout << "currentStart: " << currentStart << " currentEnd: " << currentEnd << "\n";

    for (int i{0}; i<intervals.size(); ++i)
    {
        // If this interval covers the start of the last interval
        if(intervals[i].first <= currentStart)
        {
            // Update currentEnd if this end is longer than the saved one
            currentEnd = max(intervals[i].second, currentEnd);
            cout << "new currentEnd: " << currentEnd << " start: " << intervals[i].first << "\n";
        }
        else
        {
            // Update the start value with the best end value
            currentStart = currentEnd;
            cout << "new currentStart: " << currentStart << "\n";

            ++numberOfIntervalsNeeded;
            chosenIntervals.push_back(i);

            // Break the loop if we are done or the interval is already covered
            if (currentEnd >= end || intervals[i].first > currentEnd)
            {
                break;
            }
        }
    }
    // If complete coverage is not found
    if (currentEnd < end)
    {
        return {-1};
    }
    return chosenIntervals;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read until no more input
    double mainStart{}, mainEnd{};
        
    cout << "------------------" << endl;
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
            intervals.push_back(make_pair(subStart, subEnd));
        }

        // Test output
        cout << "numberOfIntervals: " << numberOfIntervals << endl;
        cout << "interval: [" << mainStart << ", " << mainEnd << "]" << endl;
        cout << "available intervals: " << endl;
        for (auto &interval : intervals)
        {
            cout << "[" << interval.first << ", " << interval.second << "]" << endl;
        }

        // Call the solver
        vector<int> chosenIntervals = covering(intervals, mainStart, mainEnd);

        cout << "SOLUTION: ";
        // Output the solution
        if (chosenIntervals[0] == -1)
        {
            cout << "impossible\n";
        }
        else
        {
            cout << chosenIntervals.size() << endl;
            for (auto& intervalIndex : chosenIntervals)
            {
                cout << intervalIndex << " ";
            }
            cout << "\n";
        }
        cout << "------------------" << endl;
    }
    return 0;
}