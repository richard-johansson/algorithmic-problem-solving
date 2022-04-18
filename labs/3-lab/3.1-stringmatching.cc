/**
 * @file 3.1-stringmatching.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 */
#include <bits/stdc++.h>
using namespace std;

// S - the text to be searched
// W - the word sought
// T - the table, computed elsewhere
void kmp_search(string &S, string &W, vector<int> &T)
{
    vector<int> P(S.size(), 0);
    int nP{0}; // number of positions

    int j{0}; // the position of the current character in S
    int k{0}; // the position of the current character in W

    while (j < S.size())
    {
        if (W[k] == S[j])
        {
            ++j;
            ++k;
            if (k == W.size())
            {
                // occurrence found
                P[nP] = j - k;
                ++nP;
                k = T[k]; // T[length(W)] can't be -1
            }
        }
        else
        {
            k = T[k];
            if (k < 0)
            {
                ++j;
                ++k;
            }
        }
    }

    // print the result
    for (int i{0}; i < nP; ++i)
    {
        cout << P[i] << " ";
    }
    cout << "\n";
}

// W - the word to be analyzed
// T - the table to be filled
void kmp_table(string &W, vector<int> &T)
{
    int pos{1}; // the current position we are computing in T
    int cnd{0}; // the zero-based index in W of the next character of the current candidate substring
    
    T[0] = -1;

    while (pos < W.length())
    {
        if (W[pos] == W[cnd])
        {
            T[pos] = T[cnd];
        }
        else
        {
            T[pos] = cnd;
            while (cnd >= 0 && W[pos] != W[cnd])
            {
                cnd = T[cnd];
            }
        }
        ++pos;
        ++cnd;
    }

    T[pos] = cnd; // only needed when all word occurrences are searched
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string pattern{};
    string text{};
    while(getline(cin, pattern))
    {
        getline(cin, text);

        // solve 
        vector<int> T(pattern.size(), 0); // the table to be filled 
        kmp_table(pattern, T);
        kmp_search(text, pattern, T);
    }
    return 0;
}