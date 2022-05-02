/**
 * @file b-trilemma.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 */
#include <bits/stdc++.h>
using namespace std;

string checkInternalAngles(vector<pair<int,int>> triangle)
{
    // if one of the internal angles is exactly 90 degrees
    // return "right";

    // else if one of the internal angles is greater than 90 degrees
    // return "obtuse";

    // else all the internal angles are less than 90 degrees
    // return "acute";
}

string checkRelativeLengthOfSides(vector<pair<int,int>> triangle)
{
    // if all three sides have different lengths
    // return "scalene"

    // else if two of the sides are of equal length
    // return "isosceles"

    // else all three sides have the same length
    // return "equilateral"
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Number of test cases, 1 ≤ N ≤ 100
    int N;
    cin >> N;
    while(N--)
    {
        // −1000 ≤ x1, y1, x2, y2, x3, y3 ≤ 1000    
        // int x1, y1, x2, y2, x3, y3;
        // cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        vector<pair<int,int>> triangle(3);
        for (auto &p : triangle)
        {
            cin >> p.first >> p.second;
        }

        sort(triangle.begin(), triangle.end());

        // Test print
        for (auto &p : triangle)
        {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;

        // SOLVE

        // check if triangle
        // checkRelativeLengthOfSides()
        // checkInternalAngles()
        // cout << "triangle"

    }
    return 0;
}