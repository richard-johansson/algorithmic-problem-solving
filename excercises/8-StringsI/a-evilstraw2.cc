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

    // Count odd occurrences. 
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
    // string is even then palindrome cannot be formed from the given string.
    if (oddCount > 1 || oddCount == 1 && word.length() % 2 == 0)
    {
        cout << "Impossible" << "\n";
        return;
    }

    int counter{0};
    while (word.length() > 1)
    {
        // If the first letter has more than one occurence
        if (charachterMap[word[0]] > 1)
        {
            for (int i{(int)word.length() - 1}; i >= 0; --i)
            {
                if ((word[i] = word[0]))
                {
                    counter += word.length() - i - 1;
                    charachterMap[word[0]] -= 2;
                    word.erase(i, 1);
                    word = word.substr(1, word.length());
                    break;
                }
            }
        }
        else
        {
            // Swap first and second letter
            char temp = word[0];
            word[0] = word[1];
            word[1] = temp;

            ++counter;
        }
    }


    // string firstHalf{""}, secondHalf{""};
    // // Traverse the map. For every character, attach count/2 characters 
    // // to end of firstHalf and beginning of secondHalf.
    // // For every iteration, increase counter.
    // for (auto &x : charachterMap)
    // {
    //     cout << "map x[" << x.first << "] = " << x.second << endl;
    //     string temp(x.second/2, x.first);
    //     firstHalf = firstHalf + temp;
    //     secondHalf = temp + secondHalf;
     
    //     // TODO: count SWAPS not just moving a bunch of letters
    //     cout << "temp(x.second/2, x.first) = " << temp << "(" << x.second/2 << "," << x.first << ")" << endl;
    //     counter += temp.length();
    // }

    // // Result is achieved by appending firstHalf and secondHalf and 
    // // inserting oddChar if there is any.
    // string finalWord{""};
    // if (oddCount == 1)
    // {
    //     finalWord = firstHalf + oddChar + secondHalf;
    // }
    // else
    // {
    //     finalWord = firstHalf + secondHalf;
    // }

    // Print number of swaps
    cout << counter << "\n";
    // cout << word << " --> " << finalWord << ": " << counter << "\n";
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