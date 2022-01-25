/**
 * @file b-ljutnja.cc
 * @author Richard Johansson (ricjo462@student.liu.se)
 * @brief 
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void print_anger_1(int children, int candies, int sumWishes)
{
    // Candies not to give
    int missingCandyEach{((sumWishes - candies) - (sumWishes - candies) % children) / children};
    //cout << "missingCandyEach: " << missingCandyEach << endl;

    // Lacking candy
    int childrenLackingMoreCandy{(sumWishes - candies)%children};
    //cout << "childrenLackingMoreCandy: " << childrenLackingMoreCandy << endl;
    int childrenLackingLessCandy{children-childrenLackingMoreCandy};
    //cout << "childrenLackingLessCandy: " << childrenLackingLessCandy << endl;

    // Anger
    int anger{childrenLackingLessCandy * (missingCandyEach * missingCandyEach)};
    //cout << "anger: " << anger << " = " << childrenLackingLessCandy << " * " << missingCandyEach << "^2" << endl;
    if (childrenLackingMoreCandy)
    {
        int moreAnger{childrenLackingMoreCandy * ((missingCandyEach + 1) * (missingCandyEach + 1))};
        //cout << "moreAnger: " << moreAnger << " = " << childrenLackingMoreCandy << " * " << missingCandyEach + 1 << "^2" << endl;
        //cout << anger + moreAnger << endl;
    }
    else
    {
        //cout << anger << endl;
    }
}

void print_anger_2(int children, int candies, vector<int> childrenWishes)
{
    sort(childrenWishes.begin(), childrenWishes.end(), [](int a, int b)
    {
        return a < b;
    });
    
    int candiesLeft{candies}, anger{0}, missingCandies{0}, candy{0};

    //cout << "sorted wishes: [ ";
    for (auto &wish : childrenWishes)
    {
        //cout << wish << " ";
    }
    //cout << "]" << endl;

    for (auto &wish : childrenWishes)
    {
        candy = min(wish, candiesLeft/children);
        missingCandies = wish - candy;
        
        anger += missingCandies * missingCandies;
        candiesLeft -= candy;
        --children;
        //cout << "wish: " << wish << " getsCand: " << candy << " missCand: " << missingCandies << " anger: " << missingCandies * missingCandies << endl;
    }
    //cout << anger << endl;
}
/*
    give most candy to those who want most, goal is to have the kids equally mad

    <=> take candy (wishes - candy) from those who have least
    
    candies     5
    wishes      [ 5 1 7 1 ]
    sumOfWish   14
    anger       [ ]
    max sorted  [ 7 5 1 1 ]
    min sorted  [ 1 1 5 7 ]
                [ 1-0 1-0 5-2 7-3 ]
    after       [ 1 1 3 4 ]
*/
void print_anger_3(unsigned long long int children, unsigned long long int candies, long long int sumWishes, vector<unsigned long long int> childrenWishes)
{
    sort(childrenWishes.begin(), childrenWishes.end(), [](int a, int b)
    {
        return a > b;
    });
    
    unsigned long long int candiesToGive {sumWishes - candies}, anger{0};

    cout << "sorted wishes: [ ";
    for (auto &wish : childrenWishes)
    {
        cout << wish << " ";
    }
    cout << "]" << endl;

    for (unsigned long long int &wish : childrenWishes)
    {
        unsigned long long int candy = min(wish, candiesToGive/children);
        
        anger += candy * candy;
        candiesToGive -= candy;
        --children;
        
        cout << "wish: " << wish 
            << " andiesToGive/children: " << candiesToGive/children 
            << " candy: " << candy 
            << " anger: " << candy * candy 
            << " candiesToGive: " << candiesToGive 
            << " children: " << children << endl;
    }
    cout << anger << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Data input
    unsigned long long int candies{0}, children{0};
    cin >> candies >> children;

    vector<unsigned long long int> childrenWishes{};
    int wish{0};
    unsigned long long int sumWishes{0};
    cout << "candies: " << candies << " children: " << children << endl;
    
    
    while(cin >> wish)
    {
        sumWishes += wish;
        childrenWishes.push_back(wish);
    }
    //cout << "sum of wishes: " << sumWishes << endl;

    //print_anger_1(children, candies, sumWishes);
    //print_anger_2(children, candies, childrenWishes);
    print_anger_3(children, candies, sumWishes, childrenWishes);

    return 0;
}