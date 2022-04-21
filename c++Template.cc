/**
 * @file template.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfTestCases{0};

    // Read number of test cases
    cin >> numberOfTestCases;
    // For every test case
    while(numberOfTestCases--)
    {
        // Read input
        int numberOfDistances{};
        cin >> numberOfDistances;

        string line{};
        cin.ignore(1, '\n');
        getline(cin, line);
        istringstream lineStream{line};

    }
    return 0;
}