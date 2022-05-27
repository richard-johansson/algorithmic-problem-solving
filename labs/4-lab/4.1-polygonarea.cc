/**
 * @file 4.1-polygonarea.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Computes the area of a simple polygon, and the direction 
 * (clockwise or counterclockwise) in which its vertices are given.
 */
#include <bits/stdc++.h>
using namespace std;

struct point
{
    double x,y;
};

/**
 * @brief Calculates the area from the points. Formula used is
 * | 1/2 * [ (x1y2 + x2y3 + … + xn-1yn + xny1) 
 *   – (x2y1 + x3y2 + … + xnyn-1 + x1yn) ] |
 * 
 * @param points 
 * @return double 
 */
double calculateArea(vector<point> &points)
{
    double area{0.0};

    int n = points.size();
    // int j{n - 1};
    // for (int i{0}; i < n; ++i)
    // {
    //     area += (points[j].x + points[i].x) * (points[j].y + points[i].y);
    //     j = i;
    // }

    for(int i{0}, j{1}; i < n; ++i, j = (j+1) % n) {
        area += points[i].x * points[j].y;
        area -= points[i].y * points[j].x;
    }

    return (area / 2.0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n)
    {
        if (n == 0) break;
        vector<point> points;

        while(n--)
        {
            // Read input
            point point;
            cin >> point.x >> point.y;
            points.push_back(point);
        }

        // Test print
        // for (auto &p : points)
        // {
        //     cout << "(" << p.x << "," << p.y << ")" << endl;
        // }

        double area = calculateArea(points);
        cout << setprecision(1) << fixed;
        
        if (area < 0)
            cout << "CW " << abs(area) << "\n";
        else
            cout << "CCW " << abs(area) << "\n";
    }
    return 0;
}