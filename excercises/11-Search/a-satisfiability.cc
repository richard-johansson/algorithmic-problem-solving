/**
 * @file a-satisfiability.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 2-SAT problem
 * https://liu.kattis.com/problems/satisfiability
 * https://cp-algorithms.com/graph/2SAT.html
 * https://www.geeksforgeeks.org/2-satisfiability-2-sat-problem/
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Converts to CNF format, e.g. for three variables:
 * ~X1 v ~X2 v ~X3 becomes -1 -2 -3 
 * ~X1 becomes -1 0 0
 * 
 * @return vector<int>
 */
vector<int> parse(string clause, int n)
{
    istringstream clauseStream{clause};
    int i{0};
    vector<int> parsedClause;

    while (clauseStream >> clause)
    {
        if (clause[i] == 'X')
        {
            parsedClause.push_back(clause[i+1] - '0');
        }
        else if (clause[i] == '~')
        {
            parsedClause.push_back(-(clause[i+2] - '0'));
        }
    }

    int len = n - parsedClause.size();
    while (len--)
    {
        parsedClause.push_back(0);
    }

    return parsedClause;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfTestCases{0};
    cin >> numberOfTestCases;
    // For every test case
    while(numberOfTestCases--)
    {
        // 1 ≤ n ≤ 20 -- number of variables
        int n{0};
        // 1 ≤ m ≤ 100 -- number of clauses
        int m{0};
        cin >> n >> m;
        cin.ignore(1, '\n');


        // Each clause is a disjunction of literals in the form X𝑖 or ~X𝑖 
        // for some 1≤𝑖≤𝑛, where ~X𝑖 indicates the negation of the literal X𝑖. 
        // The “or” operator is denoted by a ‘v’ character and is seperated 
        // from literals with a single space.
        vector<vector<int>> allClauses;
        for (int i{0}; i < m; ++i)
        {
            string clause{};
            getline(cin, clause);

            // cout << clause << endl;
            allClauses.push_back(parse(clause, n));
        }

        // TEST PRINT
        for (auto &a : allClauses)
        {
            for (auto &b : a)
            {
                cout << setw(3) << b;
            }
            cout << "\n";
        }
        cout << "\n";

        // SOLVE



    }
    return 0;
}