/**
 * @file a-interval_cover.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 * @version 1.0
 * @date 2022-01-27
 */
#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read until no more input
    double mainStart{}, mainEnd{};
    while(cin >> mainStart >> mainEnd)
    {
        // Read the data
        int numberOfIntervals{0};
        cin >> numberOfIntervals;

        multimap<double, double> intervals{};
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
        

    }



    return 0;
}