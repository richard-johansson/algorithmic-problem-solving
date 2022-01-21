/*
* Compile with g++ -std=c++17 a-help.cc 
* Run with ./a.out < ../../test.txt 
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

bool find_phrase_from_word(unordered_map<string,string> &patternMap, string const& mainWord, string const& secondWord, stringstream &finalLine)
{
    // if value is a placeholder
    if (secondWord[0] == '<' && secondWord[secondWord.length()-1] == '>')
    {
        // key exist
        if (patternMap.find(mainWord) != patternMap.end())
        {
            finalLine << patternMap[mainWord] << ' ';
        }
        // value exist as key
        else if(patternMap.find(secondWord) != patternMap.end())
        {
            // TODO: fix problem with value here is stored in a different map!!
            finalLine << patternMap[secondWord] << ' ';
        }
        // no key exists
        else
        {
            return false;
        }
    }
    // value is not a placeholder
    // key does not exist
    else if (patternMap.find(mainWord) == patternMap.end() && secondWord[0] != '<')
    {
        patternMap[mainWord] = secondWord;
        finalLine << secondWord << ' ';
    }
    // key exists and matches word
    else if (patternMap[mainWord] == secondWord)
    {
        finalLine << secondWord << ' ';
    }
    else
    {
        return false;
    }
    //cout << "push B - A: " << mainWord << " B: " << secondWord << "\n";
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

    // loop through each pattern
    for (int i=0; i<patternA.size(); i++)
    {
        string wordA{patternA[i]}, wordB{patternB[i]};
        // cout << "patA: " << patternA[i] << " patB: " << patternB[i] << "\n";

        if (wordA[0] == '<' && wordA[wordA.length()-1] == '>')
        {
            phraseExists = find_phrase_from_word(patternMapA, wordA, wordB, finalLine);
        }
        else if (wordB[0] == '<' && wordB[wordB.length()-1] == '>')
        {
            phraseExists = find_phrase_from_word(patternMapB, wordB, wordA, finalLine);
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
        //cout << numberOfTestCases << ": " << finalLine.str() << "\n";
        cout << phrase.str() << "\n";
    }
    else
    {
        //cout << numberOfTestCases << ":-\n";
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

        print_phrase(finalLine, phraseExists);
    }
    return 0;
}