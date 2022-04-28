/**
 * @file c-fundamentalneighbors.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 */
#include <bits/stdc++.h>
using namespace std;

long neighbor(long n)
{
    unordered_map<long,long> primes;

    // divide to prime factors
    while (n % 2 == 0) 
    { 
        ++primes[2];
        n = n/2; 
    }

    for (int i{3}; i <= sqrt(n); i = i+2)
    { 
        while (n%i == 0) 
        {
            ++primes[i];
            n = n/i; 
        }
    }

    // if n is a prime number greater than 2 
    if (n > 2)
    {
        ++primes[n];
    }

    // Create neighbor
    long sum{1};
    for (auto &p : primes)
    {
        sum *= pow(p.second, p.first);
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n;

    while(cin >> n)
    {
        cout << n << " " << neighbor(n) << "\n";
    }
    return 0;
}