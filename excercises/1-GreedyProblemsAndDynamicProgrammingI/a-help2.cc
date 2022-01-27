#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * @brief Takes a stream as input an returns a 
 * vector consisting of the strings in the stream
 * 
 * @param instream an istream to be converted
 * @return vector<string> 
 */
vector<string> get_vector(string const& line)
{
    stringstream linestream{line};
    vector<string> pattern{};
    string word{};
    while (linestream >> word)
    {
        pattern.push_back(word);
    }

    return pattern;
}

/**
 * @brief Returns true if the string is a placeholder.
 * 
 * @param word 
 * @return true 
 * @return false 
 */
bool placeholder(string const& word)
{
    return (word[0] == '<' && word[word.length()-1] == '>');
}

/**
 * @brief Prints the phrase if it exists, otherwise prints "-".
 * 
 * @param phraseExists 
 * @param phrase 
 */
void print_phrase(bool phraseExists, vector<string> phrase)
{
    if (phraseExists)
    {
        for (auto const& word : phrase)
        {
            cout << word << "\n";
        }
    }
    else
    {
        cout << "-\n";
    }
}

/**
 * @brief Replacing placeholders with words in both patterns in regards to the other pattern. 
 * Returns true if there is a phrase that matches.
 * 
 * @param patternA 
 * @param patternB 
 * @return true 
 * @return false 
 */
bool find_phrase(vector<string> const& patternA, vector<string> const& patternB)
{
    // early break
    if (patternA.size() != patternB.size())
    {
        return false;
    }

    // loop through each pattern
    for (int i=0; i<patternA.size(); i++)
    {
        string wordA{patternA[i]}, wordB{patternB[i]};
        cout << wordA << " " << wordB << endl;

        if (placeholder(wordA) && !placeholder(wordB))
        {
            replace(patternA.begin(), patternA.end(), wordA, wordB);
        }
        /*
        else if (!placeholder(wordA) && placeholder(wordB))
        {
            replace(patternB.begin(), patternB.end(), wordB, wordA);
        }
        else if (placeholder(wordA) && placeholder(wordB))
        {
            string random_word{"x"};
            replace(patternA.begin(), patternA.end(), wordA, random_word);
            replace(patternB.begin(), patternB.end(), wordB, random_word);
        }
        */
    }

    // Check that both patterns match
    for (int i{0}; i<patternA.size(); ++i)
    {
        if (patternA[i] != patternB[i])
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief For each test case, outputs a phrase that matches both patterns.
 * If no phrase matches, outputs a line containing "-".
 * 
 * @return int 
 */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfTestCases{0};

    // Read number of test cases
    cin >> numberOfTestCases;
    cin.ignore(1, '\n');
    // For every test case
    while(numberOfTestCases--)
    {
        // read two lines (patterns) into two vectors
        string line{};
        getline(cin, line);
        vector<string> patternA{get_vector(line)};
        line = "";
        getline(cin, line);
        vector<string> patternB{get_vector(line)};
        
        bool phraseExists{true};

        phraseExists = find_phrase(patternA, patternB);

        // Check length
        print_phrase(phraseExists, patternA);
    }

    return 0;
}