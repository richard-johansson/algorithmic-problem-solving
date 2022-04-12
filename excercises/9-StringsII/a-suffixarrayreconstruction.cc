/**
 * @file a-suffixarrayreconstruction.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief struct that holds the value and index of a suffix.
 * 
 * @param index Position of the suffix in the string, 1 ≤ p ≤ l
 * @param value Suffix containing only characters from the set of {a,...,z,A,...,Z,.,*}.
 * Each suffix contains at most one ‘*’, which is a wildcard character (placeholder 
 * replaceing an arbitrarily large substring).
 */
struct suffix
{
    int index;
    string value;
};

/**
 * @brief Inserts the given suffix into the word if possible.
 * 
 * @param word Word to add the suffix to
 * @param suffix Single suffix to insert into the word
 * @return true If the suffix can be inserted into the word, else false
 */
bool insertSuffix(string &word, suffix &suffix)
{
    bool wildcardFound{false};
    /*
     * Iterates suffix and corresponding index at suffix and checks
     * if the suffix value contains a wildcard character '*' or
     * if character is not changed ('#') or equal to corresponding
     * suffix character. Else return false. 
     */
    for (int suffixIndex{0}, wordIndex{suffix.index}; 
        wordIndex < word.size(); ++suffixIndex, ++wordIndex)
    {
        if (suffix.value[suffixIndex] == '*')
        {
            wildcardFound = true;
            break;
        }
        if (word[wordIndex] == '#' ||
            word[wordIndex] == suffix.value[suffixIndex])
        {
            word[wordIndex] = suffix.value[suffixIndex];
        }
        else
        {
            return false;
        }
    }

    /*
     * Iterates from right to left in word and suffix's value and breaks
     * if the character in the word is '#' and not matching the value,
     * else sets the character in the word to the caracter in the suffix.
     */
    if (wildcardFound)
    {
        for (int suffixIndex{(int)suffix.value.size() - 1}, wordIndex{(int)word.size() - 1}; 
            suffix.value[suffixIndex] != '*';
            --suffixIndex, --wordIndex)
            {
                if (word[wordIndex] != '#' && 
                    word[wordIndex] != suffix.value[suffixIndex])
                {
                    return false;
                }
                else
                {
                    word[wordIndex] = suffix.value[suffixIndex];
                }
            }
    }
    return true;
}

// l = length of desired output string, 1 ≤ l ≤ 10000
// s = number of (partially broken) suffixes, 1 ≤ s ≤ 10000
/**
 * @brief Checks wether a list of suffixes can be combined into a single word.
 * 
 * @param l Length of desired output string, 1 ≤ l ≤ 10000
 * @param suffixes Vector of suffixes to be combined to a single word
 * @param word The resulting word of combined suffixes
 * @return true If possible to combine all suffixes, else false
 */
bool isPossibleToCombine(int l, vector<suffix> &suffixes, string &word)
{
    // Insert suffixes into word
    word.resize(l, '#');
    for (auto &suffix : suffixes)
    {
        // Test print
        // cout << "[" << suffix.index << "] " << suffix.value << endl;

        if (!insertSuffix(word, suffix))
        {
            return false;
        }
    }

    // Break if not all characters changed to create a word
    for (auto &character : word)
    {
        if (character == '#')
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases, 0 < t ≤ 100
    cin >> t;
    while(t--)
    {
        int l; // Length of desigred output string, 1 ≤ l ≤ 10000
        int s; // Number of (partially broken) suffixes, 1 ≤ s ≤ 10000
        cin >> l >> s;

        // Read index and suffix and make index start from 0
        vector<suffix> suffixes;
        for (int i{0}; i < s; ++i)
        {
            suffix suffix;
            cin >> suffix.index >> suffix.value;
            --suffix.index;
            suffixes.push_back(suffix);
        }

        // Solve problem
        string word;
        if (isPossibleToCombine(l, suffixes, word))
        {
            cout << word << "\n";
        }
        else
        {
            cout << "IMPOSSIBLE" << "\n";
        }
    }

    return 0;
}