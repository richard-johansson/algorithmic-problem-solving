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
            primes[i] += 1;
            x = x/i;
        }
    }

    // If x is a prime number greater than 2
    if (x > 2)
    {
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

    for (int i{0}; i<primes.size(); ++i)
    {
        result = gcd(result, primes[i]);
    }
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

        // factor n into primes
        vector<int> factor{get_primes(x)};

        // x is perfect power iff gcd(factors) > 0
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