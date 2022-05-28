/**
 * @file 4.1-polygonarea.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Computes the area of a simple polygon, and the direction 
 * (clockwise or counterclockwise) in which its vertices are given.
 * 
 * Time complexity is O(n)
 */
#include <bits/stdc++.h>
using namespace std;

struct point
{
    double x,y;
};

/**
 * @brief Calculates the area from the points. Formula used is
 * area = 1/2 * [ (x0y1 + x1y2 + … + xn-2yn-1 + xn-1y0) 
 *          – (x1y0 + x2y1 + … + xn-1yn-2 + x0yn-1) ]
 * 
 * Positive answer means the points are given in counter clock-
 * wise order and negative answer means clockwise order.
 * 
 * @param points The points given in order
 * @return double The area of the polygon, with the sign indicating
 * CW or CCW order of the points.
 */
double calculateArea(vector<point> &points)
{
    double area{0.0};
    int n = points.size(), j{1};

    // Looping
    // i: 0,1,2,...,n-1
    // j: 1,2,...,n-1,0
    for(int i{0}; i < n; ++i) {
        j = (i+1) % n;
        area += 0.5 * (points[i].x * points[j].y - points[i].y * points[j].x);
    }

    return (area);
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

        // Solve
        double area = calculateArea(points);
        
        // Depending on the sign, the points are in clockwise
        // or counter clockwise order.
        cout << setprecision(1) << fixed;
        if (area < 0)
            cout << "CW " << abs(area) << "\n";
        else
            cout << "CCW " << abs(area) << "\n";
    }
    return 0;
}