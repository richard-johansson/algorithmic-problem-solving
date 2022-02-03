/**
 * @file chopping_wood.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 * @version 1.0
 * @date 2022-02-02
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read number of test cases
    int inputLen{0};
    cin >> inputLen;
    
    // Read input to vector
    int input{0};
    vector<int> v;
    // Vector with input as index and last found as value
    vector<int> v_index(inputLen+2, -1);

    // For every test case
    for (int i{0}; i<inputLen; ++i)
    {
        // Read input
        cin >> input;
        v.push_back(input);
        v_index[input] = i;
    }

    // Early return since last element must be deletet last!
    if (v[inputLen-1] != inputLen+1)
    {
        cout << "Error\n";
        return 0;
    }

    // Save all integers not in v into heap
    priority_queue< int, vector<int>, greater<int> > heap;
    for (int i{1}; i<inputLen+2; ++i)
    {
        // If element not in v_index, push to heap
        if (v_index[i] == -1)
        {
            heap.push(i);
        }
    }

    // Print heap
    for (int i{0}; i<inputLen; ++i)
    {
        // Pop the smallest value of heap
        cout << heap.top() << "\n";
        heap.pop();

        // Add first value of v to heap
        if (v_index[v[i]] == i)
        {
            heap.push(v[i]);
        }
    }

    return 0;
}