/**
 * @file a-perfect_pth_powers.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief A program that given an integer x, calculates the 
 * largest integer p, such that x is a perfect pth power. 
 * More generally, x is a perfect pth power if, for some
 * integer b, x=b^p.
 * @date 2022-02-07
 */
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long int solve(long int x)
{
    bool is_negative{false};
    for (long int i{32}; i>0; --i)
    {
        // Check if negative
        if (x < 0)
        {
            is_negative = true;
            x = abs(x);
            // cout << "NEGATIVE: " << x << endl;
        }

        long double inverted_i = 1 / (long double) i;
        long double root = pow(x , inverted_i);
        // cout << "Root: " << root << endl;

        // Early break if the root is NOT an integer
        long double intpart_root;
        if ( modf(root, &intpart_root) != 0.0)
        {
            continue;
        }

        int int_root{(int) intpart_root};

        //cout << "i: " << i << endl;
        // If exponent is even & x is negative --> continue
        if (is_negative && (i % 2 == 0))
        {
            continue;
        }
        return i;
    }
    return x;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int x{0}, p{0};
    while(cin >> x)
    {
        if (x == 0) break;

        // cout << "x: " << x << "\n";

        cout << solve(x) << endl;;
    }

    return 0;
}