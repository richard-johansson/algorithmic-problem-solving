/**
 * @file a-satisfiability.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief SAT problem
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

    // int len = n - parsedClause.size();
    // while (len--)
    // {
    //     parsedClause.push_back(0);
    // }

    return parsedClause;
}
/*
    0   0   0
    0   0   1
    0   1   0
    0   1   1
    1   0   0
    1   0   1
    1   1   0
    1   1   1
*/
bool increase(vector<int> &variables)
{
    bool done{true};
    for (int v : variables)
    {
        if (v == 0)
            done = false;
    }
    if (done)
        return false;

    int n = variables.size();
    int carry = 1; 
    // Traverse from last digit
    for (int i{n - 1}; i >= 0; --i)
    {
        if (carry == 1) 
        {
            ++variables[i];
            carry = variables[i] / 2;
            variables[i] = variables[i] % 2;
        }
    }

    return true;
}

/*
    VARIABLES:
    0   0   0
    0   0   1
    0   1   0
    0   1   1
    1   0   0
    1   0   1
    1   1   0
    1   1   1
------------------
    CLAUSES:
    1   2   0
    -1  0   0
    -2  3   0
-------------------------   (0 0 0)
    0   0       --> FALSE
    1           --> TRUE
    1   0       --> TRUE
--> FALSE
-------------------------   (0 0 1)
    1   0       --> TRUE
    0           --> FALSE
    1   0       --> TRUE
--> FALSE
-------------------------   (0 1 0)
    0   1       --> TRUE
    1           --> TRUE
    0   0       --> FALSE
--> FALSE
-------------------------   (0 1 1)
    1   1       --> TRUE
    0           --> FALSE
    0   0       --> FALSE
--> FALSE
-------------------------   (1 0 0)
    0   0       --> FALSE
    1           --> TRUE
    1   1       --> TRUE
--> FALSE
-------------------------   (1 0 1)
    1   0       --> TRUE
    0           --> FALSE
    1   1       --> TRUE
--> FALSE
-------------------------   (1 1 0)
    0   1       --> TRUE
    1           --> TRUE
    0   1       --> TRUE
--> TRUE
-------------------------   (1 1 1)
    1   1       --> TRUE
    1           --> FALSE
    0   1       --> TRUE
--> TRUE
*/
bool satisfiable(vector<vector<int>> &allClauses, vector<int> &variables, bool allSatisfied)
{
    if (allSatisfied)
        return true;

    for (auto &clause : allClauses)
    {
        bool satisfied{false};
        for (auto &literal : clause)
        {
            // If one literal in the clause is true then whole clause is true
            if ((literal > 0 && variables[abs(literal)-1]) || (literal < 0 && !variables[abs(literal)-1]))
            {
                satisfied = true;
            }
        }
        // If one clause is false then all clauses is false
        if (!satisfied)
        {
            allSatisfied = false;
            break;
        }
        else
        {
            allSatisfied = true;
        }
    }
    if (increase(variables))
    {
        return satisfiable(allClauses, variables, allSatisfied);
    }
    
    return false;
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

            allClauses.push_back(parse(clause, n));
        }

        // SOLVE
        vector<int> variables(n, 0);
        if (satisfiable(allClauses, variables, false))
        {
            cout << "satisfiable\n";
        }
        else
        {
            cout << "unsatisfiable\n";
        }


    }
    return 0;
}