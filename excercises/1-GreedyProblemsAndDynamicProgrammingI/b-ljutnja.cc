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
 * @param children amount of children having wishes
 * @param candies amount of candy to give
 * @param sumWishes sum of the childrens wishes
 * @param childrenWishes individual childrens wishes
 */
void print_anger(unsigned long long int children, unsigned long long int candies, long long int sumWishes, vector<unsigned long long int> childrenWishes)
{
    sort(childrenWishes.begin(), childrenWishes.end(), [](int a, int b)
    {
        return a > b;
    });
    
    unsigned long long int candiesToGive {sumWishes - candies}, anger{0};

    for (unsigned long long int &wish : childrenWishes)
    {
        unsigned long long int candy = min(wish, candiesToGive/children);
        anger += candy * candy;
        candiesToGive -= candy;
        --children;
    }
    cout << anger << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long int candies{0}, children{0};
    cin >> candies >> children;

    vector<unsigned long long int> childrenWishes{};
    int wish{0};
    unsigned long long int sumWishes{0};
    
    while(cin >> wish)
    {
        sumWishes += wish;
        childrenWishes.push_back(wish);
    }

    print_anger(children, candies, sumWishes, childrenWishes);

    return 0;
}