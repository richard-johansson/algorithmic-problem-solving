#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>

using namespace std;

/*
* Compile with g++ -std=c++17 a-help.cc 
* Run with ./a.out < ../../test.txt 
*/
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
        getline(cin, line);
        vector<string> patternB{getvector(line)};
        
        bool phraseExists{true};

        unordered_map<string,string> patternMapA{}, patternMapB{};
        stringstream finalLine{};
        // loop through each pattern
        for (int i=0; i<patternA.size(); i++)
        {
            string wordA{patternA[i]}, wordB{patternB[i]};
            if (wordB[0] == '<' && wordA[0] == '<')
            {
                    phraseExists = false;
                    break;
            }
            // if there is a placeholder on either line
                // map placeholders to words, and
                // push the words to a stringstream
            else if (wordA[0] == '<' && wordA[wordA.length()-1] == '>')
            {
                // if the key does not exist
                if (patternMapA.find(wordA) == patternMapA.end())
                {
                    patternMapA[wordA] = wordB;
                    finalLine << wordB << ' ';
                }
                else if (patternMapA[wordA] == wordB)
                {
                    finalLine << wordB << ' ';
                }
                else
                {
                    phraseExists = false;
                    break;
                }
                //cout << "push B - A: " << wordA << " B: " << wordB << "\n";
            }
            else if (wordB[0] == '<' && wordB[wordB.length()-1] == '>')
            {
                // if the key does not exist
                if (patternMapB.find(wordB) == patternMapB.end())
                {
                    patternMapB[wordB] = wordA;
                    finalLine << wordA << ' ';
                }
                else if (patternMapB[wordB] == wordA)
                {
                    finalLine << wordA << ' ';
                }
                else
                {
                    phraseExists = false;
                    break;
                }
                //cout << "push A - A: " << wordA << " B: " << wordB << "\n";
            }
            else if (wordA == wordB)
            {
                //cout << "A[1]: " << wordA[1] << "\n";
                //cout << "push A - A: " << wordA << " B: " << wordB << "\n";
                finalLine << wordA << ' ';
            }
            else 
            {
                phraseExists = false;
                break;
            }
        }
        // Print the phrase
        if (phraseExists && !finalLine.str().empty())
        {
            //cout << numberOfTestCases << ": " << finalLine.str() << "\n";
            cout << finalLine.str() << "\n";
        }
        else
        {
            //cout << numberOfTestCases << ":-\n";
            cout << "-\n";
        }
    }
    return 0;
}