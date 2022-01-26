/**
 * @file b-ljutnja.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 * @version 1.0
 * @date 2022-01-25
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Prints the least amout of anger given insufficient candy to please all children. 
 * Gives most candy to those who want most, goal is to have the kids equally mad.
 * 
 * @return int 0 for good run
 */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long candies{0}, children{0};
    cin >> candies >> children;

    vector<unsigned long long> childrenWishes{};
    unsigned long long wish{0}, sumWishes{0};
    
    while(cin >> wish)
    {
        sumWishes += wish;
        childrenWishes.push_back(wish);
    }

    sort(childrenWishes.begin(), childrenWishes.end());
    
    unsigned long long candiesToGive {sumWishes - candies}, anger{0};

    for (int i{0}; i<children; ++i)
    {
        unsigned long long candy = min (childrenWishes[i], candiesToGive/(children-i));
        anger += candy * candy;
        candiesToGive -= candy;
    }
    cout << anger << endl;

    return 0;
}