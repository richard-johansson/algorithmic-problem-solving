/**
 * @file a-cudak.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Prints the number of integers in the interval with
 * the digit sum equal to S and the smallest such integer.
 */
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int L{17};
const int Sum{136};
long long dp[L][Sum];

/**
 * @brief Initialize the dynamic programming table.
 */
void initialize()
{
    // Fill all with 0
	memset(dp, 0, sizeof(dp));

    // Fill first cell with 1 since only one solution on that row,
	// i.e., digit sum = 0 is only valid if number is 0
	dp[0][0] = 1;
	   
	// Fill first 10 columns on second row with 1 since only single 
	// digits have a digit sum of that particular digit
	for (int i{0}; i < 10; ++i)
    {
		dp[1][i] = 1;
    }
    // Fill rest of the table with the corresponding number of 
	// solutions in the right place
	for (int i{2}; i < L; ++i)
    {
		for (int j{0}; j < Sum; ++j)
        {
			for (int k{0}; (k < 10 && j-k >= 0); ++k)
            {
				dp[i][j] += dp[i-1][j-k];
            }
        }
    }
}

/**
 * @brief Returns the total number of integers from 1 to n
 * that have digit sum s
 */
long long findSum(long long n, long long s)
{
    // Early returns for bad s, 
	if (s < 0)
	{
        return 0;
	}
	if (n == 0 && s == 0)
	{
        return 1;
	}
	if (n == 0)
	{
        return n;
	}

	long long sum{0}, temp_n{n}, last, length{0};
	while(temp_n)
    {
		last = temp_n % 10;
		temp_n /= 10;
		++length;
	}
	if (length == 1)
    {
		if (s <= n)
        {
            return 1;
        }
		return 0;
	}
	for (int i{0}; (i < last && s-i >= 0); ++i)
    {
		sum += dp[length-1][s-i];
    }
	return (sum + findSum(n - last * pow(10,length-1), s-last));
}

/**
 * @brief Returns the first match using binary search
 */
long long findFirstOccurence(long long A, long long B, long long s)
{
	long long high{B}, low{A}, mid;
	while(low != high)
    {
		mid = (low + high + 1) / 2;
		if (findSum(mid, s) - findSum(low, s))
        {
			high = mid - 1;
        }
		else
        {
			low = mid;
        }
	}
	return low + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long long A, B, S;

    // Initialize dp table
	initialize();

    // Read input
	cin >> A >> B >> S;

    // Call solver and print output
	cout << findSum(B, S) - findSum(A-1, S) << endl;
	cout << findFirstOccurence(A, B, S) << endl;

    return 0;
}