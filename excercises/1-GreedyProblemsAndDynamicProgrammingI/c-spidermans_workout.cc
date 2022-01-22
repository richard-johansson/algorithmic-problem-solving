/*
* Compile with g++ -std=c++17 c-spidermans_workout.cc 
* Run with ./a.out < ../../test.txt 
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;
/*
vector<int> read(istream const& stream)
{
    int numberOfDistances{};
    stream >> numberOfDistances;

    cin.ignore(1, '\n');
    string line{};
    vector<int> distances{};
    getline(stream, line);

    istringstream lineStream{line};
    int distance;
    while(lineStream >> distance)
    {
        distances.push_back(distance);
    }

    return distances;
} */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfTestCases{0};

    // Read number of test cases
    cin >> numberOfTestCases;
    // For every test case
    while(numberOfTestCases--)
    {   
        // Read input
        int numberOfDistances{};
        cin >> numberOfDistances;

        string line{};
        cin.ignore(1, '\n');
        getline(cin, line);
        istringstream lineStream{line};

        int distances[numberOfDistances];
        int distance{0};
        int i{0};
        while(lineStream >> distance)
        {
            distances[i] = distance;
            ++i;
        }

        // Solve the problem
        int sum{0}, biggestDistance{0};
        for (auto &d : distances)
        {
            sum += d;
            if (d > biggestDistance)
            {
                biggestDistance = d;
            }
        }
        // Test output
        cout << "[ ";
        for (auto &x : distances)
        {
            cout << x << " ";
        }
        cout << "] biggestDistance: " << biggestDistance
        << " sum: " << sum << endl;
        
        // sum must be even for problem to be solvable
        if (sum % 2 != 0)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        /* Two arrays with all possible positions after all possible moves
            and all possible moves to get there
            First move is always up
        input:  |3|2|4|1|           

        UUUU    |3|5|9|10|

        UDUU    |3|1|5|6|
        UUDU    |3|5|1|2|
        UUUD    |3|5|9|8|

        UDDU    |3|1|-3|-3|
        UUDD    |3|5|1|0|

        UDDD    |3|1|-3|-4|
        */
        int position[numberOfDistances][3];

        for (int i=0; i<numberOfDistances; ++i)
        {
            for (int j=0; j<3; ++j)
            {
                
            }
        }


        /* Loop through the arrays to find optimal solution
            if last is not 0 --> impossible
            if some position is negative --> impossible
            if 
        input:  |3|2|4|1|           

        UUUU    |3|5|9|10|

        UDUU    |3|1|5|6|
        UUDU    |3|5|1|2|
        UUUD    |3|5|9|8|

        UDDU    |3|1|-3|-3|
        UUDD    |3|5|1|0|

        UDDD    |3|1|-3|-4|
        */
        
    }

    return 0;
}

