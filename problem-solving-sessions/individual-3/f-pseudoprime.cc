/**
 * @file f-pseudoprime.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 */
#include <bits/stdc++.h>

using namespace std;

// Check if x is composite
bool checkcomposite(long long x)
{
    for (long long i{2}; i * i <= x; ++i)
    {
        if (x % i == 0)
            return 1;
    }
    return 0;
}

// Effectively calculate a^p (mod p)
long long power(long long x, long long y, long long mod)
{
    long long res{1};
 
    while (y)
    {
        if (y & 1)
        {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 2 < p ≤ 1 000 000 000
    // 1 < a < p
    long long p, a;

    while(true)
    {
        cin >> p >> a;
        // cout << p << " " << a << endl;

        if (p == 0 && a == 0)
        {
            break;
        }

        // true if a^p ≡ a (mod p)
        if (checkcomposite(p) && power(a, p, p) == a)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}