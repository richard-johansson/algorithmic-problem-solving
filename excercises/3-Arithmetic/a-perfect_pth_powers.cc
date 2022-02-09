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
#include <sstream>
#include <vector>
#include <cmath>
#include <numeric>
#include <unordered_map>
#include <math.h>

using namespace std;

vector<long int> get_primes(long int x)
{
    vector<long int> factor{};
    unordered_map<long int, long int> primes{};

    cout << "Factors: ";

    // Save all 2s that divide x
    while (x % 2 == 0)
    {
        cout << 2 << " ";
        primes[2] += 1;
        x = x/2;
    }

    // x must be odd at this point. So we can skip
    // one element (Note i = i + 2)
    for (long int i{3}; i <= sqrt(x); i = i + 2)
    {
        // While i divides n, save i and divide x
        while (x % i == 0)
        {
            cout << i << " ";
            primes[i] += 1;
            x = x/i;
        }
    }

    // If x is a prime number greater than 2
    if (x > 2)
    {
        cout << x << " ";
        primes[x] += 1;
    }

    for (auto &a : primes)
    {
        factor.push_back(a.second);
    }
    cout << "\n";

    return factor;
}

long int get_gcd(vector<long int> const& primes)
{
    long int result = primes[0];

    cout << "Primes: ";
    for (long int i{0}; i<primes.size(); ++i)
    {
        result = gcd(result, primes[i]);
        cout << result << " ";
    }
    cout << "\n";
    return result;
}

long int solution2(long int x)
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

        // if (x < 2 && x > -2)
        // {
        //     cout << "Invlalid input: " << x << "\n";
        //     continue;
        // }
        // cout << "x: " << x << "\n";

    // Solution 1
        // // factor n into primes
        // vector<long int> factor{get_primes(x)};
        // // x is perfect power iff gcd(factors) > 0
        // long int gcd{get_gcd(factor)};
        //
        // if (gcd > 0)
        // {
        //     cout << gcd << "\n";
        // }
        // else 
        // {
        //     cout << x << "\n";
        // }

        cout << solution2(x) << endl;;
    }

    return 0;
}