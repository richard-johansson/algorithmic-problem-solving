#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/**
* Compile with g++ -std=c++17 a-help.cc 
* Run with ./a.out < ../../test.txt 
*
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line{};

    // Read number of test cases
    // For every test case
        // read two lines (patterns) into two vectors
        // loop through each pattern
            // if there is a placeholder on either line
                // map placeholders to words
            // push the words to a stringstream
        // if the stringstream is not empty
            // print out the stringstream
        // else
            // print '-'

    return 0;
}