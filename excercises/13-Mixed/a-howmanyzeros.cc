/**
 * @file a-howmanyzeros.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Progam that prints one integer number giving the 
 * number of 0’s from the first number to the second numberk.
 * @cite Algorithm found at Codility 
 * (https://codility.com/media/train/solution-number-of-zeros.pdf)
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Gives the i:th digit of n
 */
long digitAt(long n, long i)
{
    return (n / (long) pow(10, i)) % 10;
}

/**
 * @brief Counts number of digits of the given number
 */
long numberOfDigits(long n) {
    long digits{0};
    while (n > 0)
    {
        n /= 10;
        ++digits;
    }
    return digits;
}

/**
 * @brief Iterates each digit of the number and summarize
 * the number of zeros
 */
long zerosUpTo(long n)
{
    long totalZeros{0}, number{0}, zeros{0}, digits = numberOfDigits(n);

    // Loop digits rom most to least significant
    for (long i = digits-1; i >= 0; --i)
    {
        long digit = digitAt(n, i);
        totalZeros = (10 * totalZeros + number - zeros * (9 - digit));
        if (digit == 0)
        {
            ++zeros;
        }
        number = 10 * number + digit;
    }
    return totalZeros + 1;
}

/**
 * @brief Counts number of zeros between the numbers m and n if the 
 * decimal representations of all natural numbers between and including
 * m and n would be written down
 */
long howManyZeros(long m, long n)
{
    if (m == 0)
    {
        return zerosUpTo(n);
    }
    return zerosUpTo(n) - zerosUpTo(m-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long m,n;

    while(cin >> m >> n)
    {
        if (m == -1)
            break;
        // cout << m << " " << n << endl;
        cout << howManyZeros(m, n) << "\n";
    }
    return 0;
}