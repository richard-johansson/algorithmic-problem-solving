/**
 * @file b-trilemma.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Calculates the area of the possible triangle, given
 * three points, and returns true if the are is not 0
 */
bool isTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

    if (area == 0)
        return false;
    else
        return true;
}

/**
 * @brief Using dot product to calculate the internal angle
 */
string checkInternalAngles(int vector1[], int vector2[], int vector3[])
{
    // Calculate dot product in all corners
    int product1{0}, product2{0}, product3{0};
    for (int i{0}; i < 2; ++i)
    {
        product1 = product1 + vector1[i] * vector2[i];
        product2 = product2 + (-vector1[i] * vector3[i]);
        product3 = product3 + (-vector2[i] * -vector3[i]);
    }

    // if one of the internal angles is exactly 90 degrees
    // then the dot product is 0
    if (product1 == 0 || product2 == 0 || product3 == 0)
        return "right ";

    // else if one of the internal angles is greater than 90 degrees
    // then the dot product is negative
    else if (product1 < 0 || product2 < 0 || product3 < 0)
        return "obtuse ";

    // else all the internal angles are less than 90 degrees
    else
        return "acute ";
}

/**
 * @brief Calculates length of all vectors and compare them
 */
string checkRelativeLengthOfSides(int vector1[], int vector2[], int vector3[])
{
    // Calculate lenght of all sides
    double side1 = sqrt(pow(vector1[0], 2) + pow(vector1[1], 2));
    double side2 = sqrt(pow(vector2[0], 2) + pow(vector2[1], 2));
    double side3 = sqrt(pow(vector3[0], 2) + pow(vector3[1], 2));

    // if two of the sides are of equal length
    if (side1 == side2 || side1 == side3 || side2 == side3)
        return "isosceles ";

    // if all three sides have different lengths
    else if (side1 != side2 && side1 != side3 && side2 != side3)
        return "scalene ";

    // else all three sides have the same length
    else
        return "equilateral ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Number of test cases, 1 ≤ N ≤ 100
    int N;
    cin >> N;
    for (int i{0}; i < N; ++i)
    {
        // −1000 ≤ x1, y1, x2, y2, x3, y3 ≤ 1000    
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        // cout << x1 << y1 << x2 << y2 << x3 << y3 << endl;

        // Create vector 1 from point (x1, y1) to (x2, y2) and 
        // vector 2 from point (x1, y1) to (x3, y3) and 
        // vector 3 from point (x2, y3) to (x3, y3) 
        int a, b;
        a = (x2 - x1);
        b = (y2 - y1);
        int vector1[] = {a, b};
        a = (x3 - x1);
        b = (y3 - y1);
        int vector2[] = {a, b};
        a = (x3 - x2);
        b = (y3 - y2);
        int vector3[] = {a, b};

        // SOLVE
        cout << "Case #" << i+1 << ": ";
        if (!isTriangle(x1, y1, x2, y2, x3, y3))
        {
            cout << "not a triangle\n";
            continue;
        }
        cout << checkRelativeLengthOfSides(vector1, vector2, vector3);
        cout << checkInternalAngles(vector1, vector2, vector3);
        cout << "triangle\n";
    }
    return 0;
}