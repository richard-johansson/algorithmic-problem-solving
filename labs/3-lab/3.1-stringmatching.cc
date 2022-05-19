/**
 * @file 3.1-stringmatching.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief Solving the String matching problem using Knuth-Morris-Pratt 
 * (KMP) algorithm. KMP searches for occurrences of a word W within a
 *  main text S by employing the observation that when a mismatch occurs, 
 * the word itself embodies sufficient information to determine where the 
 * next match could begin, thus bypassing re-examination of previously 
 * matched characters. 
 * 
 * Time complexity is O(text + pattern).
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Initialization of the KMP table T. The entries of T 
 * are constructed so that if we have a match starting at S[m] 
 * that fails when comparing S[m + i] to W[i], then the next 
 * possible match will start at index m + i - T[i] in S (that 
 * is, T[i] is the amount of "backtracking" we need to do after 
 * a mismatch).
 * 
 * @param W the word to be analyzed
 * @param T the table to be filled
 */
void fill_kmp_table(string &W, vector<int> &T)
{
    // the current position we are computing in T
    int pos{1};
    // the zero-based index in W of the next character 
    // of the current candidate substring
    int cnd{0};
    
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

/**
 * @brief Function that searches the string S for the word W, using the 
 * KMP table T. By using T, we know that T[0] = -1, so if W[0] is a 
 * mismatch, we cannot backtrack and must simply check the next character,
 * and although the next possible match will begin at index m + i - T[i], 
 * we need not actually check any of the T[i] characters after that, so 
 * that we continue searching from W[T[i]].
 * 
 * @param S the text to be searched
 * @param W the word sought
 */
void kmp_search(string &S, string &W)
{
    vector<int> T(W.size(), 0); // the KMP table to be filled 
    fill_kmp_table(W, T);

    vector<int> P(S.size(), 0); // positions in S at which W is found
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string pattern, text;
    while(getline(cin, pattern))
    {
        getline(cin, text);
        kmp_search(text, pattern);
    }
    return 0;
}