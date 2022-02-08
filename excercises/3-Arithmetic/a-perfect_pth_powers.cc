/**
 * @file a-perfect_pth_powers.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief A program that given an integer x, calculates the 
 * largest integer p, such that x is a perfect pth power. 
 * More generally, x is a perfect pth power if, for some
 * integer b, x=b^p.
 * @version 1.0
 * @date 2022-02-07
 */
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int x{0}, p{0};
    while(cin >> x)
    {
        if (x == 0) break;
        // Test output
        cout << x << "\n";

        // https://cr.yp.to/papers/powers-ams.pdf



    
    }
    return 0;
}