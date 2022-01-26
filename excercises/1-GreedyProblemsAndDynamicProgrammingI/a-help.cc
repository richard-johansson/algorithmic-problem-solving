/**
 * @file a-help.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 * @version 1.0
 * @date 2022-01-26
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>

using namespace std;

/**
 * @brief Takes a stream as input an returns a 
 * vector consisting of the strings in the stream
 * 
 * @param instream an istream to be converted
 * @return vector<string> 
 */
vector<string> getvector(string const& line)
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

bool find_phrase_from_word(unordered_map<string,string> &mainPatternMap, unordered_map<string,string> &secondPatternMap, string const& mainWord, string const& secondWord, stringstream &finalLine)
{
    // if value is a placeholder
    if (secondWord[0] == '<' && secondWord[secondWord.length()-1] == '>')
    {
        // key exist
        if (mainPatternMap.find(mainWord) != mainPatternMap.end())
        {
            finalLine << mainPatternMap[mainWord] << ' ';
        }
        // value exist as key
        else if(secondPatternMap.find(secondWord) != mainPatternMap.end())
        {
            finalLine << secondPatternMap[secondWord] << ' ';
        }
        // no key exists yet
        else
        {
            finalLine << "random_word" << ' ';
        }
    }
    // value is not a placeholder
    // key does not exist
    else if (mainPatternMap.find(mainWord) == mainPatternMap.end() && secondWord[0] != '<')
    {
        mainPatternMap[mainWord] = secondWord;
        finalLine << secondWord << ' ';
    }
    // key exists and matches word
    else if (mainPatternMap[mainWord] == secondWord)
    {
        finalLine << secondWord << ' ';
    }
    else
    {
        return false;
    }
    return true;
}

/**
 * @brief Updates the finalLine stringsstream and returns true if successful, false if insuccessful
 * 
 * @param patternA 
 * @param patternB 
 * @param finalLine 
 * @return true 
 * @return false 
 */
bool find_phrase(vector<string> const& patternA, vector<string> const& patternB, stringstream &finalLine)
{
    unordered_map<string,string> patternMapA{}, patternMapB{};
    bool phraseExists{true};

    // early break
    if (patternA.size() != patternB.size())
    {
        return false;
    }

    // loop through each pattern
    for (int i=0; i<patternA.size(); i++)
    {
        string wordA{patternA[i]}, wordB{patternB[i]};

        if (wordA[0] == '<' && wordA[wordA.length()-1] == '>')
        {
            phraseExists = find_phrase_from_word(patternMapA, patternMapB, wordA, wordB, finalLine);
        }
        else if (wordB[0] == '<' && wordB[wordB.length()-1] == '>')
        {
            phraseExists = find_phrase_from_word(patternMapB, patternMapA, wordB, wordA, finalLine);
        }
        else if (wordA == wordB)
        {
            finalLine << wordA << ' ';
        }
        else
        {
            return false;
        }
    }
    return phraseExists;
}

void print_phrase(stringstream &phrase, bool phraseExists)
{
    if (phraseExists && !phrase.str().empty())
    {
        cout << phrase.str() << "\n";
    }
    else
    {
        cout << "-\n";
    }
}

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
        vector<string> patternA{getvector(line)};
        line = "";
        getline(cin, line);
        vector<string> patternB{getvector(line)};
        
        bool phraseExists{true};
        stringstream finalLine{};
        phraseExists = find_phrase(patternA, patternB, finalLine);

        // Check length
        print_phrase(finalLine, phraseExists);
    }
    return 0;
}