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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int x{0}, p{0};
    while(cin >> x)
    {
        if (x == 0) break;

            bool is_negative{false};
        // Check if negative
        if (x < 0)
        {
            is_negative = true;
            x = abs(x);
        }
        for (long int i{31}; i>0; --i)
        {
            long double inverted_i = 1 / (long double) i;
            long double root = pow(x , inverted_i);

            // Early break if the root is NOT an integer
            long double intpart_root;
            if ( modf(root, &intpart_root) != 0.0)
            {
                continue;
            }

            int int_root{(int) intpart_root};

            // If exponent is even & x is negative --> continue
            if (is_negative && (i % 2 == 0))
            {
                continue;
            }

            cout << i << "\n";
            break;
        }
    }

    return 0;
}