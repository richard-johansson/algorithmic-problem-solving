/**
 * @file a-cudak.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Prints the number of integers in the interval with
 * the digit sum equal to S and the smallest such integer.
 */
#include <iostream>

using namespace std;

/**
 * @brief Returns the sum of the digits
 */
long long getSum(long long n)
{
    long long sum{0};
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A,B,S;
    // Read input
    cin >> A >> B >> S;

    // Solve problem
    long long i{A}, smallest{0}, nmbr{0};
    while (i<=B)
    {
        // Checking if number has sum of digits = N
        if (getSum(i) == S)
        {
            // The first match is the smallest
            if (smallest == 0)
            {
                smallest = i;
            }
            ++nmbr;
        }
        ++i;
    }
    cout << nmbr << "\n" << smallest << "\n";

    return 0;
}