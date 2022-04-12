/**
 * @file a-evilstraw.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 */
#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

void solve(string &word)
{
    // Count occurrences of all characters
    unordered_map<char, int> charachterMap;
    for (int i{0}; i < word.length(); ++i)
    {
        ++charachterMap[word[i]];
    }

    // Count odd occurrences
    int oddCount{0};
    char oddChar;
    for (auto &x : charachterMap)
    {
        if (x.second % 2 != 0)
        {
            ++oddCount;
            oddChar = x.first;
        }
    }
    // If this count is greater than 1 or is equal to 1 and length of the 
    // string is even then palindrome cannot be formed from the given string
    if (oddCount > 1 || oddCount == 1 && word.length() % 2 == 0)
    {
        cout << "Impossible" << "\n";
        return;
    }
    // Else reorder to create palindrome and count swaps
    else
    {
        int counter{0};
        for (int i{0}, j{(int)(word.length() - 1)}; i < j; ++i, --j)
        {
            int leftmost, rightmost;
            for (rightmost = j; rightmost > i; --rightmost)
            {
                if (word[i] == word[rightmost])
                {
                    break;
                }
            }
            for (leftmost = i; leftmost < j; ++leftmost)
            {
                if (word[j] == word[leftmost])
                {
                    break;
                }
            }
            if (j - rightmost > leftmost - i)
            {
                counter += leftmost - i;
                for (int k = leftmost - 1; k >= i; k--)
                {
                    swap(word[k], word[k + 1]);
                }
            }
            else
            {
                counter += j - rightmost;
                for (int k = rightmost + 1; k <= j; k++)
                {
                    swap(word[k], word[k - 1]);
                }
            }
        }
        cout << counter << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read number of test cases
    int n;
    cin >> n;
    string word;
    // Solve for every case
    while(n--)
    {
        cin >> word;
        solve(word);
    }
    return 0;
}