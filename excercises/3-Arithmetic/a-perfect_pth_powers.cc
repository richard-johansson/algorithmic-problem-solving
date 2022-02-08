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
#include <vector>
#include <cmath>
#include <numeric>
#include <unordered_map>

using namespace std;

vector<int> get_primes(int x)
{
    vector<int> factor{};
    unordered_map<int, int> primes{};

    // Save all 2s that divide x
    while (x % 2 == 0)
    {
        //factor.push_back(2);
        primes[2] += 1;
        x = x/2;
    }

    // x must be odd at this point. So we can skip
    // one element (Note i = i + 2)
    for (int i{3}; i <= sqrt(x); i = i + 2)
    {
        // While i divides n, save i and divide x
        while (x % i == 0)
        {
            //factor.push_back(i);
            primes[i] += 1;
            x = x/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (x > 2)
    {
        //factor.push_back(x);
        primes[x] += 1;
    }

    for (auto &a : primes)
    {
        factor.push_back(a.second);
    }

    return factor;
}

int get_gcd(vector<int> primes)
{
    int result = primes[0];

    // cout << "GCD: ";
    for (int i{0}; i<primes.size(); ++i)
    {
        // cout << result << " ";
        result = gcd(result, primes[i]);
    }
    // cout << "\n";
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int x{0}, p{0};
    while(cin >> x)
    {
        if (x == 0) break;
        // Test output
        // cout << x << "\n";

        // https://cr.yp.to/papers/powers-ams.pdf
        // https://en.wikipedia.org/wiki/Perfect_power

        // n = m^k
        // k = ap, p is prime
        // --> n = m^(ap)

        // factor n into primes
        vector<int> factor{get_primes(x)};

        // cout << "Primes: ";
        // for (auto &a : factor)
        // {
        //     cout << a << " ";
        // }
        // cout << "\n";

        // x is perfect power iff gcd(factors) > 1
        int gcd{get_gcd(factor)};

        if (gcd > 0)
        {
            cout << gcd << "\n";
        }
        else 
        {
            cout << x << "\n";
        }
    
    }
    return 0;
}