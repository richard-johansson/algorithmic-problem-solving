/**
 * @file a-interval_cover.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Program that solves the classic interval cover problem
 * Time complexity: O(n log n)
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/**
 * @brief Struct that hold the start and end values of any
 * interval, as well as the initial index of it.
 * Intervals can be compared with the < operator.
 */
struct Interval {
    double start;
    double end;
    int index;

    bool operator< (Interval compare) const 
    {
        return start < compare.start;
    }
};

/**
 * @brief Function that finds the minimal number of and which of the given
 * intervals that cover the start and end of the given main interval
 * First sorts the interval and then iterates it once --> O(n log n) time.
 * 
 * @param intervals Intervals available to cover the main interval
 * @param mainStart Start point of the interval to be covered
 * @param mainEnd End point of the interval to be covered
 * @return vector<int> The indicies of the chosen intervals
 */
vector<int> minimizeSegment(vector<Interval> &intervals, double mainStart, double mainEnd)
{
    int len = intervals.size();

    sort(intervals.begin(), intervals.end());

    // Insert INT_MAX to prevent going out of bounds
    // last in the array but with non-relevant interval index
    intervals.push_back({INT_MAX, INT_MAX, -1});
 
    double start = mainStart;
    double end = mainStart - 1;
    vector<int> chosen;

    // cout << "Interval to cover: start = " << start << " end = " << end << endl;

    // Keeps iterating until no more intervals cover current start, 
    // then updating value of current start with best end
    int i{0}, old_i{0};
    // cout << "size: " << intervals.size() << endl;
    while (i < intervals.size()) 
    {
        // cout << "Interval: " << i << ": " << intervals[i].start << ", " << intervals[i].end << endl;
        if (intervals[i].start <= start)
        {
            // cout << "intervals[i].start <= start - " << intervals[i].start << " <= " << start << endl;
            if (intervals[i].end > end)
            {
                // cout << "intervals[i].end > end - " << intervals[i].end << " > " << end << endl;
                old_i = i;
                end = intervals[i].end;
                // cout << "NEW: " << i << ": " << intervals[i].start << ", " << intervals[i].end << endl;
            }
            ++i;
        }
        else
        {
            // cout << "CHOSEN: [" << intervals[old_i].start << "," << intervals[old_i].end << "] at " << intervals[old_i].index << ", old_i: " << old_i << endl;
            chosen.push_back(intervals[old_i].index);
            start = end;

            // Already covered or not able to move further
            if (intervals[i].start > end || end >= mainEnd)
            {
                break;
            }
        }
    }
 
    // If the entire target interval is not covered
    if (end < mainEnd)
    {
        return {};
    }

    return chosen;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read until no more input
    double mainStart, mainEnd;
    while(cin >> mainStart >> mainEnd)
    {
        int numberOfIntervals;
        cin >> numberOfIntervals;

        vector<Interval> intervals(numberOfIntervals);
        for (int i{0}; i<numberOfIntervals; ++i)
        {
            double start, end;
            cin >> start >> end;

            intervals[i] = {start, end, i};
        }
        // cout << "Interval to cover: [" << mainStart << "," << mainEnd << "]\n";
        // cout << "Intervals: \n";
        // for (int i{0}; i<intervals.size(); ++i)
        // {
        //     cout << "[" << intervals[i].start << ","
        //     << intervals[i].end << "] = " 
        //     << intervals[i].index << " ";
        // }
        // cout << "\nSOLUTION:\n";

        // Call the solver
        vector<int> chosenIntervals = minimizeSegment(intervals, mainStart, mainEnd);

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
            cout << "\n";
            // cout << "Chosen intervals\n";
            // for (auto &i : chosenIntervals)
            // {
            //     cout << "[" << intervals[i].start << "," << intervals[i].end << "] ";
            // }
            // cout << "\n--------------\n";
        }
    }
    return 0;
}