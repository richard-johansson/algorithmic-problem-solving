/**
 * @file evilstraw.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 */
#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Takes a word as an argument, moves the letter at index x to the end and 
 * removes first and last letter from the word, returns number of swaps needed to place
 * the chosen letter last.
 * 
 * @param word word to be rearranged
 * @param x letter at index x to be moved
 * @return int number of swaps needed
 */
int moveToEnd(string &word, int x)
{
    int swaps{0};
    cout << "word: " << word << ", index x: " << x << ", letter: " << word[x] << "\n";

    while (x < word.length()-1)
    {
        // cout << word.substr(0, x) << "\n";
        // cout << word[x+1] << "\n";
        // cout << word[x] << "\n";
        // cout << word.substr(x+2, word.length()-1) << "\n";

        // Swap letter x and x+1
        word = word.substr(0, x) +  word[x+1] +  word[x] + word.substr(x+2, word.length()-1);
        cout << "Swap " << swaps << ", New word: " << word << "\n";
       
        ++x;
        ++swaps;
    }
    // TODO: Iteration 2 we want to move the letter not to end of word but to end-1
    word = word.substr(1, word.length()-2);

    cout << "Swaps: " << swaps << "\n";

    return swaps;
}

void solve(string &word)
{
        // Match leftmost char with rightmost mathcing char
        int leftmost{0}, rightmost{(int)word.length()-1}, swaps{0};

        char curr;
        while(leftmost < rightmost)
        {
            curr = word[leftmost];
            // Test print
            cout << "leftmost: " << leftmost << " = " << word[leftmost] << ", " 
                << "rightmost: " << rightmost << " = " << word[rightmost] << ", " 
                << "curr: " << curr << ", "
                << "word: " << word << "\n";

            if (curr == word[rightmost])
            {
                // Move letter to end of word
                swaps += moveToEnd(word, rightmost);

                ++leftmost;
                rightmost = (int)word.length() - leftmost;
            }

            --rightmost;
        }

        cout << "swaps: " << swaps << "\n";
        cout << "----------------------\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read number of test cases
    int n;
    cin >> n;
    // For every test case
    
    while(n--)
    {
        // Read input
        string word;
        cin >> word;

        // Test print
        cout << word << "\n";

        solve(word);
    }
    //string word = "aaabbb";
    //cout << moveToEnd(word, 2) << "\n";
    return 0;
}
