/**
 * @file a-interval_cover.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 */
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


struct Interval {
    double start;
    double end;
    int index;

    bool operator< (Interval compare) const 
    {
        return start < compare.start;
    }
};

// Function to find the minimum number
// of intervals in the array A[] to
// cover the entire target interval
vector<int> minimizeSegment(vector<Interval> &intervals, int start, int end)
{
    int len = intervals.size();

    sort(intervals.begin(), intervals.end());

    // Insert a pair of INT_MAX to
    // prevent going out of bounds
    intervals.push_back({INT_MAX, INT_MAX, -1});
 
    double currentStart = start;
    double currentEnd = start - 1;
    int count{0};
    vector<int> chosen;

    // Keeps iterating in the if-statement until no more
    // intervals cover current start, then updating value
    // of current start
    int i{0}, curri{0};
    while (i < intervals.size()) {
        curri = i;
        while (intervals[curri].start <= currentStart)
        {
            currentEnd = max(intervals[curri].end, currentEnd);
            ++curri;
        }
        chosen.push_back(intervals[i].index);

        i = curri;

        currentStart = currentEnd;

        //++count;
        
        // Already covered or not able to move
        if (intervals[i].start > currentEnd || currentEnd >= end) {
            break;
        }
    }
 
    // If the entire target interval is not covered
    if (currentEnd < end) {
        return {};
    }
 
    // Return Answer
    return chosen;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read until no more input
    double start, end;
    while(cin >> start >> end)
    {
        // Read the data
        int numberOfIntervals;
        cin >> numberOfIntervals;

        vector<Interval> intervals(numberOfIntervals);

    // Test printing /*
        for (int i{0}; i<numberOfIntervals; ++i)
        {
            double subStart, subEnd;
            cin >> subStart >> subEnd;

            intervals[i] = {subStart, subEnd, i};
        }

        cout << "Intervals: \n";
        for (int i{0}; i<intervals.size(); ++i)
        {
            cout << "[" << intervals[i].start << ","
            << intervals[i].end << "] = " 
            << intervals[i].index << " ";
        }
        cout << "\nSOLUTION:\n";
    // Test printing over */

        // Call the solver
        vector<int> chosenIntervals = minimizeSegment(intervals, start, end);

        // Print result
        if (chosenIntervals.size() == 0)
        {
            cout << "impossible\n";
        }
        else
        {
            cout << chosenIntervals.size() << "\n";
            for (auto &i : chosenIntervals)
            {
                cout << i << " ";
            }
            cout << "\nChosen intervals\n";
            for (auto &i : chosenIntervals)
            {
                cout << intervals[i].start << ",";
                cout << intervals[i].end << " ";
            }
            cout << "\n--------------\n";
        }
    }
    return 0;
}