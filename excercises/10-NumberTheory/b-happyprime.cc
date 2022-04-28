/**
 * @file b-happyprime.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 */
#include <bits/stdc++.h>

using namespace std;

// Perfect digital invariant function
int pdi_function(int number, int base)
{
    int total{0};

    while (number > 0)
    {
        total += pow(number % base, 2);
        number = number / base;
    }

    return total;
}

// Determine if number is a happy number
bool is_happy(int number)
{
    unordered_set<int> seenNumbers{};

    while(number > 1 && (seenNumbers.find(number) == seenNumbers.end()))
    {
        seenNumbers.insert(number);
        number = pdi_function(number, 10);
    }

    return number == 1;
}

// Check if number is prime
bool is_prime(int number)
{
    if (number <= 1)
        return false;
    
    for (int i{2}; i < number; ++i)
    {
        if (number % i == 0)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Number of data sets
    int P{0};
    cin >> P;

    // For every test case
    while(P--)
    {
        // Data set number
        int K{};
        cin >> K;
        cout << K << " ";

        // Happy prime candidate
        int m{};
        cin >> m;
        cout << m << " ";

        // solve
        if (is_happy(m) && is_prime(m))
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}